#include <stdio.h>

/**
 * insertion - insertion sort algorithm that sorts large file
 * @a: first array
 * @p: second array
 * @N: record size
 *
 * Return: nothing
 */
void insertion(int a[], int p[], int N)
{
	int i, j, v;

	for (i = 0; i <= N; i++)
		p[i] = i;

	for (i = 2; i <= N; i++)
	{
		v = p[i];
		j = i;

		while (a[p[j - 1]] > a[v])
		{
			p[j] = p[j - 1];
			j--;
		}
		p[j] = v;
	}
}


/**
 * insitu - insertion sort algorithm for larger file
 * @a: first array
 * @p: second array
 * @N: size of the record
 *
 * Return: nothing
 */
void insitu(int a[], int p[], int N)
{
	int i, j, k, t;
	for (i = 1; i <= N; i++)
	{
		if (p[i] != i)
		{
			t = a[i];
			k = i;
			do
			{
				j = k;
				a[j] = a[p[j]];
				k = p[j];
				p[j] = j;
			}
			while (k != i);
			a[j] = t;
		}
	}
}

/**
 * p_insertion - insertion sort algorithm with pointer for large file
 * @a: first array
 * @p: second pointer array
 * @N: size of array
 *
 * Return: nothing
 */
void p_insertion(int a[], int *p[], int N)
{
	int i, j, *v;
	for (i = 0; i <= N; i++)
		p[i] = &a[i];
	
	for (i = 2; i <= N; i++)
	{
		v = p[i];
		j = i;
		while (*p[j - 1] > *v)
		{
			p[j] = p[j - 1];
			j--;
		}
		p[j] = v;
	}
}
