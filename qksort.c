#include <stdio.h>


int qksort(int *array, int low, int high)
{
	if(low>=high)
	{
		return 0;
	}
	int key = array[low];
	int i = low;
	int j = high;
	i--;
	j++;
	while(1)
	{
		do{
			j--;
		}while(array[j]>key);
		
		do{
			i++;
		}while(array[i]<key);
	
		if(i>=j){
			break;
		}
		else{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	partition(array, low, j);
	partition(array, j+1, high);
	return high;
}


int main()
{
	int a[10] = {23,12,45,33,66,15,24,56,87,12};
	partition(a, 0, 9);
	for(int i=0; i<10; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
