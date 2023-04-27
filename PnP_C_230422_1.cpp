#include <stdio.h>

void swap(int* i, int* j)
{
	int temp = *i;

	*i = *j;
	*j = temp;


	return;
}

void quicksort(int arr[], int lower, int upper)
{
	if (lower >= upper)
	{
		return;
	}

	int pivot = lower;
	int L = lower + 1;
	int R = upper;

	while (L <= R)
	{
		while (L <= upper && arr[L] <= arr[pivot])
		{
			L++;
		}
		while (R > lower && arr[R] >= arr[pivot])
		{
			R--;
		}

		if (L > R)
		{
			swap(&arr[R], &arr[pivot]);
		}
		else
		{
			swap(&arr[L], &arr[R]);
		}
	}

	quicksort(arr, lower, (R - 1));
	quicksort(arr, (R + 1), upper);
}

void print_array(int arr[], int N)
{
	for (int q = 0; q < N; q++)
	{
		printf("%d ", arr[q]);
	}


	return;
}

int main()
{
	int arr[100] = { 0 };
	int N = 0;

	scanf("%d", &N);

	for (int q = 0; q < N; q++)
	{
		scanf("%d", &arr[q]);
	}

	quicksort(arr, 0, N - 1);
	print_array(arr, N);


	return 0;
}