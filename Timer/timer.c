#include <stdio.h>
#include <time.h>
#include <math.h>

unsigned long startTime;
unsigned long lastTime;
void update(unsigned long);

int main ()
{
	startTime = (unsigned long)clock();
	lastTime = 0;
	unsigned long miliseconds;
	while(1) {
		miliseconds = ((clock()- startTime)*1000/CLOCKS_PER_SEC);
		update(miliseconds);
	}
	return 0;
}

void update(unsigned long gameTime) {
	if(gameTime - lastTime >= 1000) {
		printf("SECOND\n");
		lastTime += 1000;
	}
}