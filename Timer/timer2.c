#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>

void milisecondStep(unsigned long);
unsigned long diff();
unsigned long lastUpdate;

#define period 16

unsigned long last;
int count, frames;

int main ()
{
	lastUpdate = 0;
	last = 0;
	count = 0;
	frames = 0;
	while(1) {
		milisecondStep(diff());
	}
	return 0;
}

unsigned long diff() {
	unsigned long clk = clock();
	unsigned long r = ((unsigned long)clk*1000/CLOCKS_PER_SEC) - lastUpdate;
	lastUpdate = (unsigned long)clk*1000/CLOCKS_PER_SEC;
	return r;
}

void milisecondStep(unsigned long gameTime) {
	//printf("%lu\n", gameTime);
	count++;
	last += gameTime;
	if(last >= period) {
		last -= period;
		frames++;
		printf("frame %d \n", frames);
		if(frames == 60) {
			frames = 0;
			printf("SECOND\n");
		}
		count = 0;
	}
} 