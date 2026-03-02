#include <stdio.h>
#include <stdlib.h>

int getint(char* str,int* out);

int main()
{
	int speed_limit, driver_speed, fine=0;

	// Get user input for speed limit
	int count=getint("Enter the speed limit: ",&speed_limit);
	if(count==0)
	{
		printf("Invalid input");
		return 1;
	}

	// Get user input for driver's speed
	count=getint("Enter the driver's speed: ",&driver_speed);
	if(count==0)
	{
		printf("Invalid input");
		return 1;
	}

	// Determine if the driver is speeding
	if(driver_speed>speed_limit)
	{
		int excess_speed=driver_speed-speed_limit;

		// Calculate fine based on how much over the limit
		if(excess_speed<=10)
		{
			fine=50;
		}
		else if(excess_speed<=20)
		{
			fine=100;
		}
		else
		{
			fine=200;
		}
		printf("Fine: $%d\n",fine);
	}
	else
	{
		printf("No fine needed.\n");
	}
	return 0;
}

int getint(char* str,int* out)
{
	char input[20];
	int found=0;
	printf("%s",str);
	if(fgets(input,sizeof(input),stdin))
	{
		found=sscanf(input,"%d",out);
	}
	return found;
}