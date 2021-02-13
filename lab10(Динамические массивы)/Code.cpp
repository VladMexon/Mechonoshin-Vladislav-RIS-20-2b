#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "Rus");
    int size;
    int min = 999;
    int minIND;
    string safe;
    cout << "Введите размерность массива: ";
    cin >> size;
    string* str = new string[size];
    cout << "Введите " << size << " слов:" << endl;
    for (int i = 0; i < size; i++) { //Ввод
        cin >> str[i];
    }
    cout << "Вывод" << endl;
    for (int i = 0; i < size; i++) {//Вывод
        cout << str[i] << endl;
    }
    for (int i = 0; i < size; i++) {//Нахождение самого короткого слова
        if (str[i].length() < min) {
            min = str[i].length();
            minIND = i;
        }
    }
    for (int i = minIND; i < size - 1; i++) { //Сдвиг самого короткого слова в конец массива(для удобства)
        safe = str[i + 1];
        str[i + 1] = str[i];
        str[i] = safe;
    }
    size--;
    string* str2 = new string[size]; //Создание нового массива
    for (int i = 0; i < size; i++) { //Копирование строго массива в новый(без последнего слова)
        str2[i] = str[i];
    }
    delete[] str; //Удалеине старого массива
    cout << "Вывод" << endl;
    for (int i = 0; i < size; i++) {//Вывод нового массива
        cout << str2[i] << endl;
    }
}

