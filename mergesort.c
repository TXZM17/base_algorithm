#include <stdio.h>
#include <stdlib.h>

void mergesort(int *data, int low, int high)
{
	if(low>=high){
		return;
	}
	int middle = (low+high)/2;
	mergesort(data, low, middle);
	mergesort(data, middle+1, high);
	int size = high - low + 1;
	int *temp = (int *)malloc(size*sizeof(int)); 
	int i = low;
        int j = middle+1;
	int k = 0;
	for(;i<=middle&&j<=high;){
		if(data[i]<=data[j]){
			temp[k] = data[i];
			i++;	
		}else{
			temp[k] = data[j];
			j++;
		}
		k++;
	}
	while(i>middle&&j<=high){
		temp[k] = data[j];
		k++;
		j++;
	}
	while(j>high&&i<=middle){
		temp[k] = data[i];
		k++;
		i++;
	}
	for(int i=low; i <= high; i++)
	{
		data[i] = temp[i-low];
	}
	free(temp);
}

int main()
{
	int a[10] = {11,1,34,65,87,3,56,76,14,44};
	mergesort(a, 0 ,9);
	for(int i=0;i<10;i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
