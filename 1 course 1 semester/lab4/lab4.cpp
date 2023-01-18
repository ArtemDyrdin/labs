
#include <iostream>
#include <string> 

void state_1(int* nums, int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] % 10 > nums[j - 1] % 10)
            {
                std::swap(nums[j], nums[j - 1]);
            }
        }
    }
}

void state_2(int* nums, int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            int x1 = nums[j]; // сортировка по неубыванию первой цифры числа
            int x2 = nums[j - 1];
            while (x1 > 9) // нахождение первой цифры nums[j]
            {
                x1 /= 10;
            }
            while (x2 > 9) // нахождение первой цифры nums[j - 1]
            {
                x2 = x2 / 10;
            }
            if (x1 < x2)
            {
                std::swap(nums[j], nums[j - 1]);
            }
            if (x1 == x2) { // сортировка по неубыванию произведения цифр числа
                int prod1 = 1;
                int a = nums[j];
                while (a > 0) { // нахождение произведения цифр nums[j]
                    int digit = a % 10;
                    if (digit != 0) {
                        prod1 *= digit;
                    }
                    a = a / 10;
                }
                int prod2 = 1;
                int a1 = nums[j - 1];
                while (a1 > 0) { // нахождение произведения цифр nums[j - 1]
                    int digit = a1 % 10;
                    if (digit != 0) {
                        prod2 *= digit;
                    }
                    a1 = a1 / 10;
                }
                if (prod2 > prod1) {
                    std::swap(nums[j], nums[j - 1]);
                }
                if (prod2 == prod1) { // сортировка по неубыванию самого числа
                    if (nums[j] < nums[j - 1]) {
                        std::swap(nums[j], nums[j - 1]);
                    }
                }
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите кол-во чисел последовательности: ";
    int n = 0;
    std::cin >> n;

    int nums[10000] = {0};

    std::cout << "Вводите последовательность\n";

    for (int i = 0; i < n; ++i) 
    {
        std::cout << "i " << i << " : ";
        std::cin >> nums[i];
    }

    int var = 0;
    std::cout << "Выберите пункт лабораторной: ";
    std::cin >> var;

    if (var == 1) {
        std::cout << "Последовательность по невозрастанию последней цифры числа" << std::endl;
        state_1(nums, n);
        for (int i = 0; i < n; i++)
        {
            std::cout << nums[i] << " ";
        }
    }
    else if (var == 2) {
        std::cout << "Последовательность по неубыванию первой цифры числа, числа с одинаковыми \
                первыми цифрами упорядоченны по неубыванию произведения цифр числа, \
                числа с одинаковыми первыми цифрами и одинаковыми произведениями цифр \
                упорядоченны по неубыванию самого числа" << std::endl;
        state_2(nums, n);
        for (int i = 0; i < n; i++)
        {
            std::cout << nums[i] << " ";
        }
    }
    else if (var == 3) {
        std::cout << "Создание Матрицы" << std::endl;
        int N, M, a[100][100];
        std::cout << "Количествр строк: ";
        std::cin >> N;
        std::cout << "Количество столбцов: "; 
        std::cin >> M;
        std::cout << "Введите значения матрицы A \n";
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                std::cout << "[" << i << "]" << "[" << j << "] : ";
                std::cin >> a[i][j];
            }
        std::cout << "matrix A \n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                std::cout << a[i][j] << "\t"; 
            std::cout << std::endl;
        }

        //нахождение столбца с мин суммой и умножение его элементов на 3
        
        int min_index = 0;
        int min_sum = INT_MAX;
        for (int i = 0; i < M; i++) {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                sum += a[j][i];
            }
            if (min_sum > sum) {
                min_sum = sum;
                min_index = i;
            }
            std::cout << std::endl;
        }
        for (int j = 0; j < N; j++) {
            a[j][min_index] *= 3;
        }
        std::cout << "Столбец с мин суммой элементов умножен на 3" << std::endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                std::cout << a[i][j] << "\t";
            std::cout << std::endl;
        }
    }

    return 0;
}
