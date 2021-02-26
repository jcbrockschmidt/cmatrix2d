#include <assert.h>
#include <stdio.h>
#include "matrix2d.h"

int main(int argc, char *argv[]) {
  double data1[2][3] = {{1.0, 2.0, 3.0},
			{4.0, 5.0, 6.0}};
  double data2[3][2] = {{7.0, 8.0},
			{9.0, 10.0},
			{11.0, 12.0}};
  double expect_data1[2][2] = {{58.0, 64.0},
			       {139.0, 154.0}};
  Matrix2d m1;
  Matrix2d m2;
  Matrix2d mut;
  Matrix2d m1_clone;
  Matrix2d m2_clone;
  Matrix2d expect1;
  m1 = init_matrix2d((double*)&data1, 3, 2);
  m2 = init_matrix2d((double*)&data2, 2, 3);
  mut = init_zeros_matrix2d(2, 4);
  m1_clone = init_matrix2d((double*)&data1, 3, 2);
  m2_clone = init_matrix2d((double*)&data2, 2, 3);
  expect1 = init_matrix2d((double*)&expect_data1, 2, 2);

  printf("Testing GET_ELEM_MATRIX2D...\n");
  assert(GET_ELEM_MATRIX2D(m1, 0, 0) == 1.0);
  assert(GET_ELEM_MATRIX2D(m1, 0, 1) == 2.0);
  assert(GET_ELEM_MATRIX2D(m1, 0, 2) == 3.0);
  assert(GET_ELEM_MATRIX2D(m1, 1, 0) == 4.0);
  assert(GET_ELEM_MATRIX2D(m1, 1, 1) == 5.0);
  assert(GET_ELEM_MATRIX2D(m1, 1, 2) == 6.0);
  assert(GET_ELEM_MATRIX2D(m2, 0, 0) == 7.0);
  assert(GET_ELEM_MATRIX2D(m2, 0, 1) == 8.0);
  assert(GET_ELEM_MATRIX2D(m2, 1, 0) == 9.0);
  assert(GET_ELEM_MATRIX2D(m2, 1, 1) == 10.0);
  assert(GET_ELEM_MATRIX2D(m2, 2, 0) == 11.0);
  assert(GET_ELEM_MATRIX2D(m2, 2, 1) == 12.0);

  printf("Testing SET_ELEM_MATRIX2D...\n");
  SET_ELEM_MATRIX2D(mut, 0, 0, 1.0);
  assert(GET_ELEM_MATRIX2D(mut, 0, 0) == 1.0);
  SET_ELEM_MATRIX2D(mut, 0, 1, 2.0);
  assert(GET_ELEM_MATRIX2D(mut, 0, 1) == 2.0);
  SET_ELEM_MATRIX2D(mut, 3, 1, 3.0);
  assert(GET_ELEM_MATRIX2D(mut, 3, 1) == 3.0);

  printf("Testing equals_matrix2d...\n");
  assert(equals_matrix2d(m1, m1));
  assert(equals_matrix2d(m2, m2));
  assert(equals_matrix2d(m1, m1_clone));
  assert(equals_matrix2d(m1_clone, m1));
  assert(equals_matrix2d(m2, m2_clone));
  assert(equals_matrix2d(m2_clone, m2));
  assert(!equals_matrix2d(m1, m2));
  assert(!equals_matrix2d(m2, m1));

  printf("Testing mult_matrix2d...\n");
  mult_matrix2d(m1, m2);
  assert(equals_matrix2d(mult_matrix2d(m1, m2), expect1));

  printf("Done\n");
}
