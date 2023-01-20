#include <stdio.h>

/**
 * counting_sort - sorting algorithm of distint integer keys
 * @a: array to be sorted
 * @N: size of array
 *
 * Return: nothing
 */
void counting_sort(int a[], int N)
{
	int i, j, b[N];
	int M = a[0];
	int count[M + 1];

	for (j = 0; j < M; j++)
		count[j] = 0;
	for (i = 1; i <= N; i++)
		count[a[i]]++;
	for (j = 1; j < M; j++)
		count[j] = count[j - 1] + count[j];
	for (i = N; i >= 1; i--)
		b[count[a[i]]--] = a[i];
	for (i = 1; i <= N; i++)
		a[i] = [i];
