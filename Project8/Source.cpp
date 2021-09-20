#include <iostream>
#include <stdlib.h>

using namespace std;

static int length = 1000;
int countComparisons = 0;

void insertionSort(int *val) {
	for (int i = 1; i < length; i++) {
		int key = val[i];
		int j = i - 1;
		while (j >= 0 && val[j] > key)
		{
			val[j+1] = val[j];
			j--;
			countComparisons++;
		}
		val[j+1] = key;
		countComparisons++;
	}
}

void merge(int *val, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	int *L = new int[n1];
	int *R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = val[p + i];
	for (int j = 0; j < n2; j++)
		R[j] = val[q + j + 1];

	int i = 0, j = 0;

	for (int k = p; k <= r; k++) {
		if (i == n1) {
			val[k] = R[j++];
		}
		else if (j == n2) {
			val[k] = L[i++];
		}
		else if (L[i] <= R[j]) {
			val[k] = L[i++];
		}
		else {
			val[k] = R[j++];
		}
		countComparisons++;
	}
	delete[] L, R;
}

void mergeSort(int *val, int p = 0, int r = length - 1) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(val, p, q);
		mergeSort(val, q + 1, r);
		merge(val, p, q, r);
	}
}

int* generateData(int size, int type) {

	int *p = new int[size];

	switch (type)
	{
	case 0:
		for (int i = 0; i < size; i++)
		{
			p[i] = rand() % (size + 1);
		}
		break;

	case 1:
		for (int i = 0; i < size; i++)
		{
			p[i] = i;
		}
		break;

	case 2:
		for (int i = 0; i < size; i++)
		{
			p[i] = size - i - 1;
		}
		break;

	default:
		break;
	}

	return p;
}

void main() {

	int *a = generateData(length, 0);
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << "\t";
	}
	cout << "\n\n";
	mergeSort(a);
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << "\t";
	}
	cout << "\ncount = " << countComparisons << "\n";

	delete[] a;

	system("pause");
}