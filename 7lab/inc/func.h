#pragma once

namespace functions {
	void show_matrix(int matrix[100][100], int n);
	void reading(int matrix[100][100], int& n, int t, int elements[100 * 100]);
	bool isPrime(int num);
	void set_norms(int matrix[100][100], double norms[], int n);
	bool is_this(int matrix[100][100], int n);
	void sort_matrix_cols(int matrix[100][100], double* norms, int n);
	void processing(int matrix[100][100], int n);
	void recording(int matrix[100][100], int n);
}