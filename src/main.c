#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pigpio.h>
#define PIN 17


void checkRange( float r1, float r2, float r3, float r4, float r5)
{
	if(r1 < 68 || r1 > 76)
	{
		printf("WARNING \n");
	}
	else
	{
		printf("NORMAL \n");
	}
	
	if(r2 < 68 || r2 > 76)
	{
		printf("WARNING \n");
	}
	else
	{
		printf("NORMAL \n");
	}
	
	if(r3 < 68 || r3 > 76)
	{
		printf("WARNING \n");
	}
	else
	{
		printf("NORMAL \n");
	}
	
	if(r4 < 68 || r4 > 76)
	{
		printf("WARNING \n");
	}
	else
	{
		printf("NORMAL \n");
	}
	
	if(r5 < 68 || r5 > 76)
	{
		printf("WARNING \n");
	}
	else
	{
		printf("NORMAL \n");
	}
}
	
		  





int main(int argc, char* argv[])
{
	float r1,r2,r3,r4,r5;
	float average;
	
 gpioInitialise();
   gpioSetMode(PIN,PI_OUTPUT);
   gpioWrite(PIN, 1); // LED ON 
   getchar(); // waits for Enter key
   gpioWrite( PIN,0); // LED OFF
   getchar(); // waits for Enter key
   gpioTerminate(); 
	
	printf("Enter first reading : \n");
	scanf("%f", &r1);
	printf("Enter second reading : \n");
	scanf("%f", &r2);
	printf("Enter third reading : \n");
	scanf("%f", &r3);
	printf("Enter fourth reading : \n");
	scanf("%f", &r4);
	printf("Enter fifth reading : \n");
	scanf("%f", &r5);
	
	average = r1 + r2 + r3 + r4 + r5;
	average = average/5;
	
	printf("Average : %.2f \n", average);
	
	
	checkRange(r1, r2, r3, r4, r5);
	
	FILE *FH;
	
	FH = fopen("reading.txt", "w+");
	if(FH == NULL)
	{ 
		printf("File did not open exiting");
		exit(0);
	}
	
if(r1 < 68 || r1 > 76)
	{
	fprintf(FH, "%f", r1);
	fprintf(FH, "WARNING \n", r1);
	}
	else
	{
	fprintf(FH, "%f", r1);
	fprintf(FH, "NORMAL \n", r1);
	}
	
	if(r2 < 68 || r2 > 76)
	{
	fprintf(FH, "%f", r2);
	fprintf(FH, "WARNING \n", r2);
	}
	else
	{
	fprintf(FH, "%f", r2);
	fprintf(FH, "NORMAL \n", r2);
	}
	
	if(r3 < 68 || r3 > 76)
	{
	fprintf(FH, "%f", r3);
	fprintf(FH, "WARNING \n", r3);
	}
	else
	{
	fprintf(FH, "%f", r3);
	fprintf(FH, "NORMAL \n", r3);
	}
	
	if(r4 < 68 || r4 > 76)
	{
	fprintf(FH, "%f", r4);
	fprintf(FH, "WARNING \n", r4);
	}
	else
	{
	fprintf(FH, "%f", r4);
	fprintf(FH, "NORMAL \n", r4);
	}
	
	if(r5 < 68 || r5 > 76)
	{
	fprintf(FH, "%f", r5);
	fprintf(FH, "WARNING \n", r5);
	}
	else
	{
	fprintf(FH, "%f", r5);
	fprintf(FH, "NORMAL \n", r5);
	}
	
	
	fclose(FH);
	return 0;
	
}

