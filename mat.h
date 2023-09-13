#ifndef MAT_H_
#define MAT_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define Data float 

typedef struct {
	size_t row;
	size_t col;
	size_t stride;
	Data *es;
} Mat;

#define MAT_AT(m, i, j) (m).es[(i)*m.stride + (j)]

Mat mat_alloc(size_t row, size_t col);
void mat_dealloc(Mat m);

void mat_rand(Mat m, Data low, Data high);
void mat_fill(Mat m, Data value);

void mat_sum(Mat dst, Mat a);
void mat_dot(Mat dst, Mat a, Mat b);

#define MAT_PRINT(m) mat_print((m), #m)
void mat_print(Mat m, const char *m_name);

#endif // MAT_H_
