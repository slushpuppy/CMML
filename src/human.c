#include "human.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

uint32_t mouseSpeed = 20;

void randomize(void)
{
	time_t now = time(NULL);
	uint8_t *p = (uint8_t *)&now;
	uint32_t seed = 0;
	size_t i;

	for (i = 0; i < sizeof(now); i++)
		seed = seed * (UCHAR_MAX + 2U) + p[i];

	srand(seed);
}

int32_t randRange(int32_t min, int32_t max)
{
	return min + (rand() * (1.0 / (RAND_MAX + 1.0))) * (max - min);
}

int32_t randNumber(int32_t number)
{
	return randRange(0, number);
}


void wait(uint32_t ms)
{
	usleep(ms * 1000);
}

void mouseMoveH(uint32_t x, uint32_t y, uint8_t r)
{
	double start_x, start_y;
	double end_x = x + randRange(-r, r), end_y = y + randRange(-r, r);
	uint32_t last_x, last_y;
	double gravity = 9.0, wind = 3.0;
	double speed = ((randNumber(mouseSpeed) / 2.0 + mouseSpeed) / 10.0);
	double min_wait = 10.0 / speed, max_wait = 15.0 / speed;
	double max_step = 10.0 * speed, target = 10.0 * speed;
	double veloX = 0.0, veloY = 0.0, veloMag = 0.0;
	double windX = 0.0, windY = 0.0, step = 0.0;
	double dist = 0.0, randDist = 0.0, lastDist = 0.0;
	double sqrt2 = sqrt(2), sqrt3 = sqrt(3), sqrt5 = sqrt(5);

	uint32_t _temp_x, _temp_y;
	mousePos(&_temp_x, &_temp_y);
	start_x = _temp_x;
	start_y = _temp_y;

	while (hypot(start_x - end_x, start_y - end_y) > 1) {
		dist = hypot(start_x - end_x, start_y - end_y);
		wind = min(wind, dist);

		if (dist >= target) {
			windX = windX / sqrt3 + (randNumber(round(wind) * 2 + 1) - wind) / sqrt5;
			windY = windY / sqrt3 + (randNumber(round(wind) * 2 + 1) - wind) / sqrt5;
		} else {
			windX = windX / sqrt2;
			windY = windY / sqrt2;

			max_step = (max_step < 3) ? randRange(3, 6) : max_step / sqrt5;
		}

		veloX = veloX + windX;
		veloX = veloX + gravity * (end_x - start_x) / dist;

		veloY = veloY + windY;
		veloY = veloY + gravity * (end_y - start_y) / dist;
		
		if (hypot(veloX, veloY) > max_step) {
			randDist = max_step / 2.0 + randNumber(round(round(max_step) / 2));
			veloMag = sqrt(veloX * veloX + veloY * veloY);
			veloX = (veloX / veloMag) * randDist;
			veloY = (veloY / veloMag) * randDist;
		}

		last_x = round(start_x);
		last_y = round(start_y);

		start_x += veloX;
		start_y += veloY;

		if ((round(start_x) != last_x) || (round(start_y) != last_y))
			mouseMove(round(start_x), round(start_y));

		step = hypot(start_x - last_x, start_y - last_y);
		wait(round((max_wait - min_wait) * (step / max_step) + min_wait));

		lastDist = dist;
	}

	if ((round(start_x) != round(end_x)) || (round(start_y) != round(end_y)))
		mouseMove(round(end_x), round(end_y));
}

void mouseClickH(mouseButton button)
{
	mouseDown(button);
	wait(80 + randNumber(120));
	mouseUp(button);
	wait(50 + randNumber(50));
}
