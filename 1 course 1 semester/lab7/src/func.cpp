#include <iostream>
#include <cctype>
#include <fstream>

#include "func.h"

using namespace std;

namespace functions {
	void show_matrix(int matrix[100][100], int n) {
		cout << "Matrix\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << matrix[i][j] << "\t";
			cout << endl;
		}
		cout << endl;
	}

	void reading(int matrix[100][100], int& n, int t, int elements[100*100]) {
		ifstream in("matrix.txt", ios::in);
		while (!in.eof()) {
			int el;
			in >> el;
			elements[t] = el;
			t++;
		}
		n = pow(t, 0.5);

		int stp = 0;
		while (stp < t) {
			for (int i = 0; i < n; i++) {
				int s = 0;
				for (int j = stp; j < stp + n; j++) {
					matrix[i][s] = elements[j];
					s++;
				}
				stp += n;
			}
		}
		show_matrix(matrix, n);
	}

	bool isPrime(int num) {
		for (int i = 2; i <= pow(abs(num), 0.5); i++) {
			if (abs(num) % i == 0 || abs(num) == 1) {
				return 0;
			}
		}
		cout << num << "\tпростое число" << endl;
		return 1;
	}

	void set_norms(int matrix[100][100], double norms[], int n) {
		for (int j = 0; j < n; j++) {
			int norm = 0;
			for (int i = 0; i < n; i++) {
				norm += pow(matrix[i][j], 2);
			}
			norms[j] = pow(norm, 0.5);
		}
	}

	bool is_this(int matrix[100][100], int n) {
		for (int i = 0; i < n; i++) {
			int sum = 0;
			bool prime = 0;
			for (int j = 0; j < n; j++) {
				if (isPrime(matrix[i][j])) {
					prime = 1;
				}
				sum += matrix[i][j];
			}
			if (prime == 1 && sum == 0) {
				return 1;
			}
		}
		return 0;
	}

	void sort_matrix_cols(int matrix[100][100], double* norms, int n) {
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (norms[j] > norms[j - 1])
				{
					swap(norms[j], norms[j - 1]);
					for (int s = 0; s < n; s++) {
						swap(matrix[s][j], matrix[s][j - 1]);
					}
				}
			}
		}
	}

	void processing(int matrix[100][100], int n) {
		if (is_this(matrix, n)) {
			double norms[100] = {};
			set_norms(matrix, norms, n);
			cout << endl;
			for (int i = 0; i < n; i++) {
				cout << norms[i] << "\t" << "норма " << i << endl;
			}
			cout << endl;
			sort_matrix_cols(matrix, norms, n);
			show_matrix(matrix, n);
		}
		else {
			cout << "Данная матрица не содержит строки с простым числом и нулевой суммой элементов" << endl;
		}
	}

	void recording(int matrix[100][100], int n) {
		ofstream out;
		out.open("new_matrix.txt");
		if (out.is_open())
		{
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					out << matrix[i][j] << " ";
				}
				out << "\n";
			}
			cout << "Запись совершена" << endl;
		}
		//out << words[i] << " ";
		else
		{
			cout << "Файл закрыт" << endl;
		}
	}
}