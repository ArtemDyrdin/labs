// Провайдер и абонент

#include <iostream>
#include <vector>
using namespace std;

// объект второй - абонент
class Abonent {

private:
    unsigned int m_id; // id
    string m_name; // имя

public:
    Abonent(int id, string name) {
        m_id = id;
        m_name = name;
    }

    ~Abonent() {}

    // вернуть имя абонента
    string getName() {
        return m_name;
    }
};

// объект первый (главный) - провайдер
class Provider {

private:
    unsigned int m_id; // id
    string m_title; // название провайдера
    int m_tarifs; // кол-во тарифов
    double m_speed; // скорость связи
    vector<Abonent*> m_abonents; // создание дин. массива vector с указателем на класс Abonent

public:
    Provider(int id, string title, int tarifs, double speed) {
        m_id = id;
        m_title = title;
        m_tarifs = tarifs;
        m_speed = speed;
    }

    ~Provider(){}

    // вернуть венруть информацию о провайдере
    void getProviderInfo() {
        cout << "ID " << m_id << " " << m_title << endl \
            << "Кол-во доступных тарифов: " << m_tarifs << endl \
            << "Скорость связи: " << m_speed << endl << endl;
    }

    // добавить пользователя (абонента) к данному провайдеру
    void addAbonent(Abonent* abonent) {
        m_abonents.push_back(abonent);
    }

    // вывести список пользователей (абонентов) провайдера
    void showAbonents() {
        cout << "Пользователи " << m_title << ":" << endl;
        for (size_t i = 0; i < m_abonents.size(); i++) {
            cout << m_abonents[i]->getName() << endl;
        }
        cout << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    // создаем список доступных провайдеров
    Provider* provider1 = new Provider(0, "Tele2", 8, 50);
    Provider* provider2 = new Provider(1, "Билайн", 7, 55);
    Provider* provider3 = new Provider(2, "Мегафон", 4, 70);

    // выводим информацию о каждом из них
    provider1->getProviderInfo();
    provider2->getProviderInfo();
    provider3->getProviderInfo();

    // создаем абонентов
    Abonent* abonent1 = new Abonent(0, "Арсений Иванов");
    Abonent* abonent2 = new Abonent(1, "Никита Семенов");
    Abonent* abonent3 = new Abonent(2, "Федор Петров");

    // привязываем абонентов к провайдерам
    provider1->addAbonent(abonent1);
    provider1->addAbonent(abonent2);
    provider3->addAbonent(abonent3);

    // выводим список абонентов провайдеров
    provider1->showAbonents();
    provider2->showAbonents();
    provider3->showAbonents();

    // ощищаем кучу
    delete provider1;
    delete provider2;
    delete provider3;

    delete abonent1;
    delete abonent2;
    delete abonent3;

    return 0;
}
