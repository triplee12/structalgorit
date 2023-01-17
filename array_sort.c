#include <stdio.h>
#include <string.h>

#define MAXN 100

/**
 * sort3 - Simple sort algorithms with no validation
 * @a: array or record to be sort
 * @N: the nth size of the array
 * 
 * Return: nothing
 */
void sort3(int a[], int N)
{
	int t;
	if (a[1] > a[2])
	{
		t = a[1];
		a[1] = a[2];
		a[2] = t;
	}

	if (a[1] > a[3])
	{
		t = a[1];
		a[1] = a[3];
		a[3] = t;
	}

	if (a[2] > a[3])
	{
		t = a[2];
		a[2] = a[3];
		a[3] = t;
	}
}


/**
 * selection - Selection sort algorithms
 * @a: array or record to be sort
 * @N: the nth size of the array
 *
 * Return: nothing
 */
void selection(int a[], int N)
{
	int i, j, min, t;
	for (i = 1; i < N; i++)
	{
		min = i;
		for (j = i + 1; j <= N; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		t = a[min];
		a[min] = a[i];
		a[i] = t;
	}
}


/**
 * insertion - Insertion sort algorithms
 * @a: array or record to be sort
 * @N: the nth size of the array
 *
 * Return: nothing
 */
void insertion(int a[], int N)
{
	int i, j, v;
	for (i = 2; i <= N; i++)
	{
		v = a[i];
		j = i;
		while (a[j - 1] > v)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = v;
	}
}

/**
 * bubble - bubble sort algorithms
 * @a: array or record to be sort
 * @N: the nth size of the array
 *
 * Return: nothing
 */
void bubble(int a[], int N)
{
	int i, j, t;
	for (i = N; i >= 1; i--)
	{
		for (j = 2, j <= i; j++)
		{
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
		}
	}
}

/**
 * main - starting program
 *
 * Return: always return 0 on success
 */
int main()
{
	int N, i, a[MAXN+1];
	N = 0;

	while (scanf("%d", &a[N+1]) != EOF)
		N++;
	a[0] = 0;

	sort3(a, N);

	for (i = 1; i <= N; i++)
		printf("%d ", a[i]);
	printf("\n");

	return (0);
}
