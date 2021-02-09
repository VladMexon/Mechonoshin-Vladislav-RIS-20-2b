#include <iostream>
using namespace std;

struct Auto_owner {
    string fio[3]; // Фио
    int num; // Номер машины
    int phone_number; // Номер телефона
    int number_of_techpass; // Номер тех. паспорта
};

void output(Auto_owner base[], int elements) {
    for (int i = 0; i < elements; i++) { // Вывод
        if (base[i].num != NULL) {
            cout << "\nФИО: ";
            cout << base[i].fio[0] << " " << base[i].fio[1] << " " << base[i].fio[2];
            cout << "\nНомер машины: ";
            cout << base[i].num;
            cout << "\nНомер телефона: ";
            cout << base[i].phone_number;
            cout << "\nНомер тех. паспорта: ";
            cout << base[i].number_of_techpass;
        }
    }
}

int main()
{
    system("chcp 1251>nul");
    setlocale(0, "Rus");
    const int size = 30;
    Auto_owner base[size];
    int elements = 0;
    bool nExT = true;
    int safe = 999;

    for (int i = 0; nExT; i++) { //Ввод
        safe = 999;
        cout << "Введите фамилию: ";
        cin >> base[i].fio[0];
        cout << "Введите имя: ";
        cin >> base[i].fio[1];
        cout << "Введите отчество: ";
        cin >> base[i].fio[2];
        cout << "Введите номер машины: ";
        cin >> base[i].num;
        cout << "Введите номер телефона: ";
        cin >> base[i].phone_number;
        cout << "Введите номер тех. паспорта: ";
        cin >> base[i].number_of_techpass;
        elements++;
        while (!(safe > -1 and safe < 2)) {
            cout << "\nВведите 1 чтобы продолжить и 0 чтобы прекратить: ";
            cin >> safe;
            if (safe == 0) {
                nExT = false;
            }
            if (safe == 1) {
                nExT = true;
            }
        }
    }

    output(base, elements);
    
    cout << "\nВведите номер элемента, который надо удалить: ";
    int number_of_del;
    cin >> number_of_del; // C единицы
    while (number_of_del < 1) {
        cout << "\nНеверно. Введите номер элемента, который надо удалить: ";
        cin >> number_of_del;
    }
    if (number_of_del != elements) {
        for (int i = number_of_del; i < elements; i++) {
            base[i - 1] = base[i];
        }
        elements--;
    }
    else{
        base[number_of_del - 1].num = NULL;
    }

    output(base, elements);

    cout << "\nВведите фамлию, после которой надо вставить 2 элемента: ";
    string fam;
    cin >> fam;
    int safeelem = elements;
    bool flag = false;

    for (int i = 0; i < safeelem; i++) {
        if (base[i].fio[0] == fam) {
            for (int c = 0; c < 2; c++) { //Двойной сдвиг
                for (int d = elements + c; d > i; d--) {
                    base[d] = base[d - 1];
                }
            }
            for (int b = i + 1; b <= i + 2; b++) { //Ввод
                cout << "Введите фамилию: ";
                cin >> base[b].fio[0];
                cout << "Введите имя: ";
                cin >> base[b].fio[1];
                cout << "Введите отчество: ";
                cin >> base[b].fio[2];
                cout << "Введите номер машины: ";
                cin >> base[b].num;
                cout << "Введите номер телефона: ";
                cin >> base[b].phone_number;
                cout << "Введите номер тех. паспорта: ";
                cin >> base[b].number_of_techpass;
                elements++;
            }
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "Не было найдено такой фамилии";
    }

    output(base, elements);
}