#include "matrix2d.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

Matrix2d init_matrix2d(double* data, const size_t w, const size_t h) {
  Matrix2d m;
  m.data = (double *) malloc(w * h * sizeof(double));
  memcpy(m.data, data, w * h * sizeof(double));
  m.w = w;
  m.h = h;
  return m;
}

Matrix2d init_zeros_matrix2d(const size_t w, const size_t h) {
  Matrix2d m;
  size_t size = w * h * sizeof(double);
  m.data = (double *) malloc(size);
  memset(m.data, 0, size);
  m.w = w;
  m.h = h;
  return m;
}

int equals_matrix2d(Matrix2d m1, Matrix2d m2) {
  if (m1.w != m2.w || m1.h != m2.h) {
    return 0;
  }
  for (int i = 0; i < m1.w * m1.h; i++) {
    if (m1.data[i] != m2.data[i]) {
      return 0;
    }
  }
  return 1;
}

Matrix2d mult_matrix2d(Matrix2d m1, Matrix2d m2) {
  Matrix2d res;
  assert(m1.w == m2.h);
  res = init_zeros_matrix2d(m2.w, m1.h);
  for (int i = 0; i < res.h; i++) {
    for (int j = 0; j < res.w; j++) {
      double dot = 0.0;
      for (int k = 0; k < m1.w; k++) {
	dot += GET_ELEM_MATRIX2D(m1, i, k) * GET_ELEM_MATRIX2D(m2, k, j);
      }
      SET_ELEM_MATRIX2D(res, i, j, dot);
    }
  }

  // TODO
  return res;
}
