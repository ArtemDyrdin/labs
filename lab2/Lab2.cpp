/*
Вариант 2.
Ввести натуральные числа A, B и C. Если A кратно C и B кратно C, то вывести (A+B)/C, 
если A кратно C и B не кратно C, то вывести A/С+B, 
в остальных случаях вывести A-B-C.
Ввести натуральное число N, обозначающее номер дня недели. 
Используя оператор switch вывести название всех дней недели. Предусмотреть обработку ошибочного ввода N.
*/


#include <iostream>

int main()
{
    std::cout << "Enter numbers A, B, C\n";
    int A, B, C;
    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    double a = A;
    double b = B;
    double c = C;

    if (A % C == 0 && B % C == 0) {
        std::cout << "(A + B) / C = " << ((a + b) / c) << "\n";
    }
    else if (A % C == 0 && B % C != 0) {
        std::cout << "(A / C) + B = " << ((a / c) + b) << "\n";
    }
    else {
        std::cout << "A - B - C = " << a - b - c << "\n";
    }

    std::cout << "Enter day of the week\n";
    int N;
    std::cin >> N;

    switch (N){

    case 1:
        std::cout << "Monday";
        break;
    case 2:
        std::cout << "Tuesday";
        break;
    case 3:
        std::cout << "Wednsday";
        break;
    case 4:
        std::cout << "Thursday";
        break;
    case 5:
        std::cout << "Friday";
        break;
    case 6:
        std::cout << "Saturday";
        break;
    case 7:
        std::cout << "Sunday";
        break;
    default:
        std::cout << "Wrong number!!!";
        break;
    }
}