// чтобы исправить ошибку с открытием файлов, подправьте cmakelist или как-нибудь сами

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

int glas(char letter) {
	switch (letter) {
	case 'a':
		return 0;
		break;
	case 'e':
		return 0;
		break;
	case 'y':
		return 0;
		break;
	case 'u':
		return 0;
		break;
	case 'i':
		return 0;
		break;
	case 'o':
		return 0;
		break;
	default:
		return 1;
		break;
	}
}

void state_1() {
	char g[100];
	cout << "Введите строку" << endl;
	cin >> g;
	for (int i = 0; i < sizeof(g); i++) {
		if (glas(g[i])) {
			g[i] = toupper(g[i]);
		}
	}

	cout << "Все согласные строчные буквы заменены на заглавные:" << endl;
	cout << g << endl;
}

int count_letter(string s, string l) {
	for (int i = 0; i < s.size(); i++) {
		if (toupper(s[i]) == toupper(l[0])) {
			return 1;
		}
	}
	return 0;
}

int compare(string str1, string str2) {
	if (str1.length() < str2.length())
		return 1;
	return 0;
}

void state_2() {
	int sum = 0;
	int ind = 0;
	int N;
	string a;
	string b;

	std::ifstream in("C:/Users/PAVILION/Desktop/lab5_2.txt", std::ios::in);
	cout << "Введите кол-во слов для записи: ";
	cin >> N;
	string words[100] = {};

	cout << "Сортировка слов по двум буквам:" << endl;
	cout << "Первая: ";
	cin >> a;
	std::cout << a << std::endl;
	cout << "Вторая: ";
	cin >> b;

	int last_counts = 0;

	int t = 0;
	while (!in.eof()) {
		string word;
		in >> word;

		if (count_letter(word, a) && count_letter(word, b)) {
			words[t] = word;
			t++;
		}
	}
	sort(words, words + t, compare);
	for (int i = 0; i < t; i++) {
		cout << words[i] << endl;
	}

	std::cout << "111" << std::endl;

	std::ofstream out;          // поток для записи
	out.open("C:/Users/PAVILION/Desktop/lab5_21.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		for (int i = 0; i < t; i++) {
			std::cout << words[i] << std::endl;
			out << words[i] << " ";
		}
	}
	else
	{
		std::cout << "111" << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int program;
	cout << "Введите пункт упражнения: ";
	cin >> program;
	if (program == 1) {
		state_1();
	}
	else if (program == 2) {
		state_2();
	}
}
