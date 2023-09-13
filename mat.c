#include "mat.h"


static Data rand_value() {
	return (Data) rand() / (Data) RAND_MAX;
}

Mat mat_alloc(size_t row, size_t col) {
	Mat m;
	m.row = row;
	m.col = col;
	m.stride = col
	m.es = malloc(sizeof(*m.es)*row*col);
	assert(m.es != NULL);
	return m;
}

void mat_dealloc(Mat m) {
	free(m.es);
}

void mat_rand(Mat m, Data low, Data high) {
	for (size_t i = 0; i < m.row; i++) {
		for (size_t j = 0; j < m.col; j++) {
			MAT_AT(m, i, j) = rand_value()*(high - low);
		}
	}
}

void mat_fill(Mat m, Data value) {
	for (size_t i = 0; i < m.row; i++) {
		for (size_t j = 0; j < m.col; j++) {
			MAT_AT(m, i, j) = value;
		}
	}
}

void mat_sum(Mat dst, Mat a) {
	assert(dst.row == a.row);
	assert(dst.col == a.col);

	for (size_t i = 0; i < dst.row; i ++) {
		for (size_t j = 0; j < dst.col; j ++) {
			MAT_AT(dst, i, j) += MAT_AT(a, i, j);
		}
	}
}

// 2x3 3X5
void mat_dot(Mat dst, Mat a, Mat b) {
	assert(a.col == b.row);
	assert(dst.row == a.row);
	assert(dst.col == b.col);

	for (size_t i = 0; i < dst.row; i ++) {
		for (size_t j = 0; j < dst.col; j ++) {
			MAT_AT(dst, i, j) = 0;
			for (size_t k = 0; k < a.col; k++) {
				MAT_AT(dst, i, j) += MAT_AT(a, i, k)*MAT_AT(b, k, j);
			}
		}
	}
}

void mat_print(Mat m, const char *m_name) {
	printf("%s = [\n", m_name);
	for (size_t i = 0; i < m.row; i++) {
		for (size_t j = 0; j < m.col; j++) {
			printf("%f  ", MAT_AT(m, i, j));
		}
		printf("\n");
	}
	printf("]\n");
}
