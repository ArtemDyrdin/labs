// найти длину окружности с использованием абстракции и инкапсуляции класса

#include <iostream>
using namespace std;

class Circle {
// Абстракция
private:
    const double pi = 3.141592653589793;
    double m_length = 0;
    double m_radius = 0;
// Инкапсуляция
public:
    // Конструктор
    Circle(double radius) {
        if (SetRadius(radius)) {
            m_radius = radius;
            m_length = 2 * pi * m_radius;
        }
    }
    // Деструктор
    ~Circle() {}

    bool SetRadius(double radius) {
        if (radius < 0) {
            cout << "Введены некоректные данные" << endl;
            return false;
        }
        else {
            return true;
        }
    }
    double get_length() {
        return m_length;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    double radius = 0;
    cout << "Введите радиус окружности" << endl;
    cin >> radius;

    Circle circle1(radius);
    cout << circle1.get_length() << endl;
}
