#include <stdio.h>
#include <stdlib.h>

#define SIZE 9


void selection(int array[])
{
	int swaps[SIZE] = {0};
	int total = 0;
	int min = 0;

	for(int i = 0; i < SIZE-1; i++)
	{
		min = i;
		for(int j = i; j < SIZE; j++)
		{
			if(array[j]<array[min])
			{
				min = j;
			}
		}


		if(min != i)
		{
			swaps[i]++; swaps[min]++; total++;
		
			int temp = array[i];
			array[i] = array[min];
			array[min] = temp;

			temp = swaps[i];
			swaps[i] = swaps[min];
			swaps[min] = temp;
		}
		
	}

	printf("Selection:\n");
	
	for (int i = 0; i < SIZE; i++)
	{
		printf("%2d: %d\n", array[i], swaps[i]);
	}
	printf("Total swaps: %d\n\n", total);


}


void bubble(int array[])
{
	//counter for # of swaps per number
	int swaps[SIZE] = {0};
	int total = 0;



	for(int i = 0; i < SIZE-1; i++)
	{
		for(int j = 0; j < SIZE-i-1; j++)
		{
			//if the next number is greater, swap
			if(array[j] > array[j+1])
			{
				//increment swap counters
				swaps[j]++; swaps[j+1]++; total++;
				
				//swap numbers
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;

				//swap counter so indices match those of the sorted array
				temp = swaps[j];
				swaps[j] = swaps[j+1];
				swaps[j+1] = temp;
			}
		}
	}

	printf("Bubble:\n");
	
	for (int i = 0; i < SIZE; i++)
	{
		printf("%2d: %d\n", array[i], swaps[i]);
	}
	printf("Total swaps: %d\n\n", total);


}






int main(void)
{
	int array1B[] = {97, 16, 45, 63, 13, 22, 7,  58, 72};
	int array2B[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
	int array1S[] = {97, 16, 45, 63, 13, 22, 7,  58, 72};
	int array2S[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};



	printf(" ARRAY 1\n");
	selection(array1S);
	bubble(array1B);

	printf("\n\n");

	printf(" ARRAY 2\n");
	selection(array2S);
	bubble(array2B);

}