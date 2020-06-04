#include "median_filter.h"
#include <stdio.h>
#include <stdlib.h>


int loadData(double *input, int n) {
	int val;
	int i = 0;

	while (scanf("%d", &val) > 0) {
		input[i] = val;
		i++;
		}

	return i;
}

void printData(double *data, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%lf\n", data[i]);
	}
}

double median(double *data, int n) {
	double med;
	double pom;
	for (int i = 0;i <= n - 2;i++) {
		for (int j = 0;j <= n;j++) {
			if (data[i] > data[i + 1]) {
				pom = data[i];
				data[i] = data[i + 1];
				data[i + 1] = pom;
			}
		}
	}
	med = data[n / 2];
	return med;
}

void filterData(double *input, double *output, int k, int w){
	double data[5];
	for (int i = 0;i <= k;i++) {
		for (int j = 0;j <= 3;j++) {
			data[j] = input[j + i];
		}
		output[i + 1] = median(data, w * 2 + 1);
	}
}


int main() {
	double input[MAX_DATA_SIZE];
	double output[MAX_DATA_SIZE];
	int i, n, w;
	w = 2;

	n = loadData(input, MAX_DATA_SIZE);
	filterData(input, output, n-2, w);
	for (i = 0; i < w; i++)
		output[i] = input[i];
	for (i = n; i > w; i--)
		output[i-1] = input[i-1];
	printData(output, n);

	getchar();
	return 1;
}
