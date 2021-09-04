#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a) > (b))? (a):(b)

double getProductConsecutiveMax(double*, int);

int main() {
	int n;
	double *list;

	scanf("%d", &n);

	list = malloc(sizeof(double) * n);

	for(int i = 0; i < n; i++)
		scanf("%lf", &(list[i]));

	printf("%lf\n", getProductConsecutiveMax(list, n));

	return 0;
}

// Algorithm O(n):
// PCM => Product Consecutive Max
// PFMin => Product Final (ending) Min
// PFMax => Product Final (ending) Max
// Basically PFMax is used to compute the maximum sum after the addition of new element
// ... PFMin helps to generate PFMax and PCM is the answer to the problem

// BASE: Consider a null vector => PCM = PFMin = PFMax = 1
// IH: Given an array v[1...i-1] with PCM, PFMin and PFMax determined, find PCM, PFMin and PFMax for v[1...i]
// STEP:
// if (v[i] == 0): restart PFMin & PFMax;
// if (v[i] > 0): PFMin|PFMax = 1 or PFMin|PFMax*v[i]
// if (v[i] < 0): PFMin = PFMax*v[i] & PFMax = 1 or PFMin*v[i]
// PCM = MAX(PFMax,PCM)
double getProductConsecutiveMax(double *list, int n) {
	double PFMax=1.0, PFMin=1.0, PCM=1.0; //null sums
	for(int i = 0; i < n; i++) {
		
		if (list[i] == 0.0) {
			PFMax = 1.0;
			PFMin = 1.0;
		} else if (list[i] > 0.0) {
			PFMax = MAX(PFMax * list[i], 1);
			if (PFMin < 0.0)
				PFMin *= list[i]; //else PFMin is 1 and keeps that way
		} else { //list[i] < 0
			double aux = PFMax;
			
			if (PFMin > 0.0)
				PFMax = 1;
			else
				PFMax = MAX(PFMin * list[i], 1);

			PFMin = aux * list[i];
		}

		if (PFMax > PCM)
			PCM = PFMax;

	}
	return PCM;
}