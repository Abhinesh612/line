#include <stdio.h>
#include "mat.h"

int main() {
	srand(69);
	float arr[] = {1, 0, 0, 1};
	Mat a = mat_alloc(2, 2);
	Mat b = mat_alloc(2, 2);
	Mat c = mat_alloc(2, 2);
	mat_rand(a, 0, 1);
	b.es = arr;
	MAT_PRINT(a);
	MAT_PRINT(b);
	mat_dot(c, b, a);
	printf("-------------\n");
	MAT_PRINT(c);
	mat_dealloc(a);
	mat_dealloc(c);
	return 0;
}
