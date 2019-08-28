#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
	int i;
	float f;
	double d;

	i = INT_MAX;
	f = FLT_MAX;
	d = DBL_MAX;

	printf("%d\n%f\n%lf", i, f, d);

	return 0;
}
