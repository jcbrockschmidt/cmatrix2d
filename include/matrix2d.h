#include <stddef.h>

typedef struct Matrix2d {
  double* data;
  size_t w, h;
} Matrix2d;

Matrix2d init_matrix2d(double* data, const size_t w, const size_t h);

Matrix2d init_zeros_matrix2d(const size_t w, const size_t h);

int equals_matrix2d(Matrix2d m1, Matrix2d m2);

Matrix2d mult_matrix2d(Matrix2d m1, Matrix2d m2);

#define GET_ELEM_MATRIX2D(m, y, x) (m.data[y * m.w + x])

#define SET_ELEM_MATRIX2D(m, y, x, a) (m.data[y * m.w + x] = a)
