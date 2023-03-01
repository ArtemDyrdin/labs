#include<iostream>
using namespace std;

class Complex
{
private:
	double m_r;
	double m_i;

public:
	// базовый конструктор
	explicit Complex(double r = 0.0, double i = 0.0) : m_r(r), m_i(i) {}

	// конструктор копирования при передаче другого объекта
	Complex(const Complex& z) {
		m_r = z.m_r;
		m_i = z.m_i;
	}

	// оператор присваивания "=" копированием
	Complex& operator =(Complex z)
	{
		swap(m_r, z.m_r);
		swap(m_i, z.m_i);
		return *this;
	}

	// оператор "+="
	Complex& operator +=(const Complex& z)
	{
		m_r += z.m_r;
		m_i += z.m_i;
		return *this;
	}

	//оператор "+"
	Complex operator +(const Complex& z)
	{
		Complex newStr = *this;
		newStr += z;
		return newStr;
	}

	// оператор "*="
	Complex& operator *=(const Complex& z)
	{
		double last_m_r = m_r;
		m_r = (m_r * z.m_r) - (m_i * z.m_i);
		m_i = last_m_r * z.m_i + m_i * z.m_r;
		return *this;
	}

	//оператор "*"
	Complex operator *(const Complex& z)
	{
		Complex newStr = *this;
		newStr *= z;
		return newStr;
	}

	// ++ префиксный
	Complex& operator ++() {
		m_r += 1;
		return *this;
	}

	// ++ постфиксный
	Complex& operator ++(int) {
		Complex z = *this;
		m_r += 1;
		return z;
	}

	friend ostream& operator <<(ostream& out, Complex& z);
	friend istream& operator >>(istream& in, Complex& z);
};

// оператор вывода в поток
ostream& operator <<(ostream& out, Complex& z)
{
	out << z.m_r << " " << z.m_i << "i" << endl;
	return out;
}

// оператор ввода в поток
istream& operator >>(istream& in, Complex& z)
{
	in >> z.m_r >> z.m_i;
	return in;
}

int main()
{
	setlocale(LC_ALL, "ru");

	Complex z1(1, 1);
	Complex z2(1, 1);

	z1 *= z2;
	cout << z1 << endl;

	Complex z3 = z1 * z2;
	cout << z3 << endl;

	++z3;
	z3++;
	cout << z3 << endl;

	cin >> z3;
	cout << z3 << endl;

	return 0;
}