#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Проверяем тип блюда
bool checkType(const string& type) {
    vector<string> validTypes = {"Закуски", "Основные блюда", "Десерты", "Напитки", "Для детей"};
    for (const string& validType : validTypes) {
        if (type == validType) {
            return true;
        }
    }
    return false;
}

// Функция для чтения данных из файла
vector<vector<string>> readFromFile(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);
    
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> dish;
            string temp = "";
            for (char c : line) {
                if (c == ';') {
                    dish.push_back(temp);
                    temp = "";
                } else {
                    temp += c;
                }
            }
            dish.push_back(temp);
            if (dish.size() == 3) {
                data.push_back(dish);
            }
        }
        file.close();
    }
    
    return data;
}

// Функция для записи данных в файл
void writeToFile(const string& filename, const vector<vector<string>>& data) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const vector<string>& dish : data) {
            file << dish[0] << ";" << dish[1] << ";" << dish[2] << "\n";
        }
        file.close();
    }
}

// Вывод
void printData(const vector<vector<string>>& data) {
    cout << "Содержимое файла:\n";
    for (const vector<string>& dish : data) {
        cout << "Название: " << dish[0] << ", Тип: " << dish[1] << ", Цена: " << dish[2] << "\n";
    }
}

// Добавление блюда
void addDish(const string& filename) {
    ofstream file(filename, ios::app);
    
    if (file.is_open()) {
        string name, type, price;
        
        cout << "Введите название блюда: " << endl;
        getline(cin, name);
        
        cout << "Введите тип блюда (Закуски/Основные блюда/Десерты/Напитки/Для детей): ";
        getline(cin, type);
        
        while (!checkType(type)) {
            cout << "Неверный тип блюда. Попробуйте снова: ";
            getline(cin, type);
        }
        
        cout << "Введите цену: ";
        getline(cin, price);
        
        file << name << ";" << type << ";" << price << endl;
        file.close();
        
        cout << "Блюдо успешно добавлено!\n";
    } else {
        cout << "Ошибка открытия файла!\n";
    }
}

// Пытаюсь найти блюдо по названию
void searchDish(const vector<vector<string>>& data) {
    string searchName;
    cout << "Введите название блюда для поиска: ";
    getline(cin, searchName);
    
    bool found = false;
    for (const vector<string>& dish : data) {
        if (dish[0] == searchName) {
            cout << "Найдено блюдо: " << dish[0] << ", Тип: " << dish[1] << ", Цена: " << dish[2] << "\n";
            found = true;
            break;
        }
    }
    
    if (found == false) {
        cout << "Блюдо с названием '" << searchName << "' не найдено.\n";
    }
}

// Сорт тип
bool compareByType(const vector<string>& a, const vector<string>& b) {
    return a[1] < b[1];
}

// Сорт цена
bool compareByPrice(const vector<string>& a, const vector<string>& b) {
    return stod(a[2]) < stod(b[2]); // stod я раньше не использовал, он преобразует строку в double
}

// Огр цена
void filterByPrice(const vector<vector<string>>& data) {
    double maxPrice;
    cout << "Введите максимальную цену: ";
    cin >> maxPrice;
    
    cout << "Блюда с ценой не более " << maxPrice << ":\n";
    for (const vector<string>& dish : data) {
        if (stod(dish[2]) <= maxPrice) {
            cout << "Название: " << dish[0] << ", Тип: " << dish[1] << ", Цена: " << dish[2] << "\n";
        }
    }
}

int main() {
    const string filename = "menu.txt";
    const string outputFile = "output.txt";
    int choice;
    
    do {
        cout << "1 - Добавление данных в файл" << endl;
        cout << "2 - Поиск блюда по названию" << endl;
        cout << "3 - Сортировка блюд по типу" << endl;
        cout << "4 - Сортировка блюд по цене" << endl;
        cout << "5 - Ограничение цены" << endl;
        cout << "6 - Вывод всех данных" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore(); // Очищаю буффер ввода, чтобы все работало нормально
        
        ofstream out("output.txt", ios::app); // ios - говорит что будет добавлять записи в конец нового файла
        
        switch (choice) {
            case 1: {
                addDish(filename);
                cout << "Добавлено новое блюдо в файл" << endl;
                out << "Добавлено новое блюдо в файл" << endl; // добавляет записи в конец output.txt 
                break;
            }
            
            case 2: {
                vector<vector<string>> data = readFromFile(filename);
                if (data.size() == 0) {
                    cout << "Файл пуст или не существует!" << endl;
                } else {
                    searchDish(data);
                    cout << "Выполнен поиск блюда" << endl;
                    out << "Выполнен поиск блюда" << endl; 
                }
                break;
            }
            
            case 3: {
                vector<vector<string>> data = readFromFile(filename);
                if (data.size() == 0) {
                    cout << "Файл пуст или не существует!" << endl;
                } else {
                    sort(data.begin(), data.end(), compareByType);
                    writeToFile(filename, data);
                    cout << "Данные отсортированы по типу!" << endl;
                    out << "Данные отсортированы по типу!" << endl;
                }
                break;
            }
            
            case 4: {
                vector<vector<string>> data = readFromFile(filename);
                if (data.size() == 0) {
                    cout << "Файл пуст или не существует!" << endl;
                } else {
                    sort(data.begin(), data.end(), compareByPrice);
                    writeToFile(filename, data);
                    cout << "Данные отсортированы по цене!" << endl;
                    out << "Данные отсортированы по цене!" << endl;
                }
                break;
            }
            
            case 5: {
                vector<vector<string>> data = readFromFile(filename);
                if (data.size() == 0) {
                    cout << "Файл пуст или не существует!" << endl;
                } else {
                    filterByPrice(data);
                    cout << "Выполнен вывод по цене" << endl;
                    out << "Выполнен вывод по цене" << endl;
                }
                break;
            }
            
            case 6: {
                vector<vector<string>> data = readFromFile(filename);
                if (data.size() == 0) {
                    cout << "Файл пуст или не существует!" << endl;
                } else {
                    printData(data);
                    cout << "Выведены все данные" << endl;
                    out << "Выведены все данные" << endl;
                }
                break;
            }
            
            case 0: {
                cout << "Завершение работы программы" << endl;
                out << "Завершение работы программы" << endl;
                break;
            }
            
            default: {
                cout << "Неверный выбор!" << endl;
                out << "Неверный выбор!" << endl;
                break;
            }
        }
        
        out.close();
        
    } while (choice != 0);
    
    return 0;
}