#include<iostream>
using namespace std;

class MyString
{
private:
	int m_size = 0;
	char* m_str = nullptr;

public:
	// базовый конструктор
	MyString() = default;

	// запрещенный конструктор
	MyString(const int a, size_t size) = delete;

	// конструктор по символу
	MyString(const char a, size_t size) : m_size(size), m_str(new char[m_size])
	{
		fill(m_str, m_str + m_size, a);
		m_str[m_size] = '\0';
	}

	// конструктор
	MyString(const char* str) : m_size(strlen(str)), m_str(new char[m_size + 1])
	{
		copy(str, str + m_size + 1, m_str);
	}

	// конструктор копирования при передаче другого объекта
	MyString(const MyString& other) : MyString(other.m_str) {}

	// оператор присваивания "=" копированием
	MyString& operator =(MyString temp)
	{
		swap(m_size, temp.m_size);
		swap(m_str, temp.m_str);
		return *this;
	}

	// оператор "+="
	MyString& operator+=(const MyString& other)
	{
		char* new_str = new char[m_size + other.m_size + 1];
		copy(m_str, m_str + m_size, new_str);
		copy(other.m_str, other.m_str + other.m_size + 1, new_str + m_size);

		delete[] m_str;
		m_str = new_str;
		m_size += other.m_size;
		return *this;
	}

	//оператор "+"
	MyString operator+(const MyString& other)
	{
		MyString newStr = *this;
		newStr += other;
		return newStr;
	}

	// чтение и изменение элемента по индексу
	char& operator [](int index) const
	{
		return m_str[index];
	}

	// оператор <
	bool operator <(const MyString& other) const
	{
		return m_size < other.m_size;
	}

	// оператор >
	bool operator >(const MyString& other) const
	{
		return m_size > other.m_size;
	}

	// оператор ==
	bool operator ==(const MyString& other) const
	{
		if (m_size != other.m_size)
			return false;

		for (int i = 0; i < m_size; i++)
			if (m_str[i] != other.m_str[i])
				return false;
		return true;
	}

	// поиск первого вхождения символа слева
	int find(char a) const
	{
		for (int i = 0; i < m_size; i++)
			if (m_str[i] == a)
				return i;
			else
				abort();
	}

	// длина строки
	int length() const
	{
		return m_size;
	}

	// строка
	char* c_str() const
	{
		return m_str;
	}

	char& at(int index) {
		if (index >= 0 && index < m_size)
			return m_str[index];
		else
			abort();
	}

	// деструктор
	~MyString()
	{
		if (m_str != nullptr) {
			delete[] m_str;
		}
	}

	friend ostream& operator <<(ostream& out, MyString& str);
	friend istream& operator >>(istream& in, MyString& str);
};

// оператор вывода в поток
ostream& operator <<(ostream& out, MyString& str)
{
	out << str.m_str << "\t" << str.m_size << endl;
	return out;
}

// оператор ввода в поток
istream& operator >>(istream& in, MyString& str)
{
	in >> str.m_str;
	str.m_size = strlen(str.m_str);
	return in;
}

int main()
{
	setlocale(LC_ALL, "ru");

	cout << "Копирование по char[]:" << endl;
	MyString str("Hello");
	cout << str << endl;
	MyString str2("World");
	cout << str2 << endl << endl;

	cout << "Строка по символу:" << endl;
	MyString str4('a', 5);
	cout << str4 << endl << endl;

	cout << "Копирование по объекту MyString:" << endl;
	MyString str3(str);
	cout << str3 << endl << endl;

	cout << "Оператор присваивания (=) копированием:" << endl;
	str3 = str2;
	cout << str3 << endl << endl;

	cout << "Оператор (+=):" << endl;
	str3 += str;
	cout << str3 << endl << endl;

	cout << "Оператор (+):" << endl;
	str3 = str + str2;
	cout << str3 << endl << endl;

	cout << "Чтение и изменение элемента по индексу: " << endl;
	cout << str[0] << "\t";
	str[0] = 'T';
	cout << str[0] << endl << endl;

	cout << "<  >  == :" << endl;
	cout << (str > str3) << "\t" << (str < str3) << "\t" << (str == str3) << endl << endl;;

	cout << "<<  >>" << endl;
	cin >> str;
	cout << str << endl << endl;

	cout << "find :" << endl;
	cout << str2.find('W') << endl << endl;

	cout << "length: " << endl;
	cout << str.length() << endl << endl;

	cout << "c_str :" << endl;
	cout << str.c_str() << endl << endl;

	cout << "at :" << endl;
	str.at(1) = 'X';
	cout << str;

	return 0;
}