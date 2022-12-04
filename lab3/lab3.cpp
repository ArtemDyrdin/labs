/* Вариант - 2. Дана последовательность вещественных чисел{Aj}. Найти сумму чисел, лежащих
на отpезке[-7, 19], наибольшее из таких чисел и номер этого числа в последовательности. */

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите кол-во чисел последовательности: ";
    int n = 0;
    std::cin >> n;
    
    double nums[10000] = {0};

    std::cout << "Вводите последовательность\n";

    for (int i = 0; i < n; i++) {
        std::cout << "Элемент " << i << " : ";
        std::cin >> nums[i];
    }

    double max_number = 0;
    int index_max_number = 0;
    double summ = 0;

    for (int i = 0; i < n; ++i) {
        if (nums[i] >= -7 && nums[i] <= 19) {
            summ += nums[i];
            if (nums[i] > max_number) {
                max_number = nums[i];
                index_max_number = i;
            }
        }
    }
    std::cout << "Сумма: " << summ << "\nМаксимальное число: " << max_number << "\nИндекс: " << index_max_number;
}