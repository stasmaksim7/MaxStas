#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

// Базовый класс Building
class Building {
protected:
    string name;
    int floors;
    double area;
    vector<string> owners; // композиция: список собственников

public:
    Building(string n = "", int f = 0, double a = 0.0) 
        : name(n), floors(f), area(a) {}

    virtual ~Building() = default;

    virtual void display() const {
        cout << "Название: " << name 
             << ", Этажи: " << floors 
             << ", Площадь: " << area << " м²" << endl
             << "Собственники: ";
        for (const auto& owner : owners) {
            cout << owner << " ";
        }
        cout << endl;
    }

    virtual string getType() const = 0;
    virtual string getParamString() const = 0;

    void saveToFile(ofstream& file) const {
        file << getType() << ";"
             << name << ";"
             << floors << ";"
             << area << ";"
             << getParamString() << ";";
        for (size_t i = 0; i < owners.size(); ++i) {
            file << owners[i];
            if (i != owners.size() - 1) file << "|";
        }
        file << endl;
    }

    void loadFromFile(istringstream& iss) {
        getline(iss, name, ';');
        string temp;
        getline(iss, temp, ';');
        floors = stoi(temp);
        getline(iss, temp, ';');
        area = stod(temp);
        // Параметр обрабатывается в производных классах
        string ownersStr;
        getline(iss, ownersStr);
        
        owners.clear();
        istringstream ownersStream(ownersStr);
        string owner;
        while (getline(ownersStream, owner, '|')) {
            owners.push_back(owner);
        }
    }

    void addOwner(const string& owner) {
        owners.push_back(owner);
    }

    // Геттеры
    string getName() const { return name; }
    int getFloors() const { return floors; }
    double getArea() const { return area; }
    const vector<string>& getOwners() const { return owners; }

    // Сеттеры
    void setName(const string& n) { name = n; }
    void setFloors(int f) { floors = f; }
    void setArea(double a) { area = a; }
};

// Производный класс ResidentialBuilding
class ResidentialBuilding : public Building {
private:
    int numApartments;
    double avgApartmentArea;

public:
    ResidentialBuilding(string n = "", int f = 0, double a = 0.0, 
                       int na = 0, double avg = 0.0)
        : Building(n, f, a), numApartments(na), avgApartmentArea(avg) {}

    void display() const override {
        Building::display();
        cout << "Тип: Жилой дом" << endl
             << "Количество квартир: " << numApartments 
             << ", Средняя площадь квартиры: " << avgApartmentArea << " м²" << endl
             << "----------------------------------------" << endl;
    }

    string getType() const override { return "Residential"; }
    string getParamString() const override {
        return to_string(numApartments) + "-" + to_string(avgApartmentArea);
    }

    void loadFromFile(istringstream& iss) {
        Building::loadFromFile(iss);
        string param;
        getline(iss, param, ';');
        size_t dashPos = param.find('-');
        numApartments = stoi(param.substr(0, dashPos));
        avgApartmentArea = stod(param.substr(dashPos + 1));
    }

    // Геттеры
    int getNumApartments() const { return numApartments; }
    double getAvgApartmentArea() const { return avgApartmentArea; }

    // Сеттеры
    void setNumApartments(int na) { numApartments = na; }
    void setAvgApartmentArea(double avg) { avgApartmentArea = avg; }
};

// Производный класс OfficeBuilding
class OfficeBuilding : public Building {
private:
    int numOffices;
    double avgOfficeArea;

public:
    OfficeBuilding(string n = "", int f = 0, double a = 0.0, 
                  int no = 0, double avg = 0.0)
        : Building(n, f, a), numOffices(no), avgOfficeArea(avg) {}

    void display() const override {
        Building::display();
        cout << "Тип: Офисное здание" << endl
             << "Количество офисов: " << numOffices 
             << ", Средняя площадь офиса: " << avgOfficeArea << " м²" << endl
             << "----------------------------------------" << endl;
    }

    string getType() const override { return "Office"; }
    string getParamString() const override {
        return to_string(numOffices) + "-" + to_string(avgOfficeArea);
    }

    void loadFromFile(istringstream& iss) {
        Building::loadFromFile(iss);
        string param;
        getline(iss, param, ';');
        size_t dashPos = param.find('-');
        numOffices = stoi(param.substr(0, dashPos));
        avgOfficeArea = stod(param.substr(dashPos + 1));
    }

    // Геттеры
    int getNumOffices() const { return numOffices; }
    double getAvgOfficeArea() const { return avgOfficeArea; }

    // Сеттеры
    void setNumOffices(int no) { numOffices = no; }
    void setAvgOfficeArea(double avg) { avgOfficeArea = avg; }
};

// Глобальные переменные
list<unique_ptr<Building>> buildings;

// Функции для работы с данными
void loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }

    buildings.clear();
    string line;
    
    while (getline(file, line)) {
        istringstream iss(line);
        string type;
        getline(iss, type, ';');
        
        unique_ptr<Building> building;
        
        if (type == "Residential") {
            building = make_unique<ResidentialBuilding>();
            ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(building.get());
            rb->loadFromFile(iss);
        } else if (type == "Office") {
            building = make_unique<OfficeBuilding>();
            OfficeBuilding* ob = dynamic_cast<OfficeBuilding*>(building.get());
            ob->loadFromFile(iss);
        }
        
        if (building) {
            buildings.push_back(move(building));
        }
    }
    
    cout << "Загружено " << buildings.size() << " объектов из файла." << endl;
}

void saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка создания файла " << filename << endl;
        return;
    }
    
    for (const auto& building : buildings) {
        building->saveToFile(file);
    }
    
    cout << "Сохранено " << buildings.size() << " объектов в файл." << endl;
}

void displayAll() {
    if (buildings.empty()) {
        cout << "Список объектов пуст." << endl;
        return;
    }
    
    cout << endl << "=== Все объекты ===" << endl;
    for (const auto& building : buildings) {
        building->display();
    }
}

void filterByFloors(int minFloors) {
    cout << endl << "=== Здания с этажностью > " << minFloors << " ===" << endl;
    int count = 0;
    
    auto filterLambda = [minFloors](const unique_ptr<Building>& b) {
        return b->getFloors() > minFloors;
    };
    
    for (const auto& building : buildings) {
        if (filterLambda(building)) {
            building->display();
            count++;
        }
    }
    
    if (count == 0) {
        cout << "Таких зданий не найдено." << endl;
    }
}

void sortByAreaAndFloors() {
    cout << endl << "=== Сортировка по площади (убыв.) и этажности (убыв.) ===" << endl;
    
    buildings.sort([](const unique_ptr<Building>& a, const unique_ptr<Building>& b) {
        if (abs(a->getArea() - b->getArea()) > 0.001) {
            return a->getArea() > b->getArea(); // по убыванию площади
        }
        return a->getFloors() > b->getFloors(); // по убыванию этажности
    });
    
    displayAll();
}

void addBuilding() {
    cout << endl << "=== Добавление нового здания ===" << endl;
    cout << "Выберите тип (1 - жилой, 2 - офисный): ";
    int type;
    cin >> type;
    cin.ignore();
    
    string name;
    int floors;
    double area;
    
    cout << "Название: ";
    getline(cin, name);
    cout << "Количество этажей: ";
    cin >> floors;
    cout << "Общая площадь (м²): ";
    cin >> area;
    
    if (type == 1) {
        int numApartments;
        double avgArea;
        cout << "Количество квартир: ";
        cin >> numApartments;
        cout << "Средняя площадь квартиры (м²): ";
        cin >> avgArea;
        
        buildings.push_back(make_unique<ResidentialBuilding>(name, floors, area, numApartments, avgArea));
    } else {
        int numOffices;
        double avgArea;
        cout << "Количество офисов: ";
        cin >> numOffices;
        cout << "Средняя площадь офиса (м²): ";
        cin >> avgArea;
        
        buildings.push_back(make_unique<OfficeBuilding>(name, floors, area, numOffices, avgArea));
    }
    
    cout << "Здание добавлено!" << endl;
}

void editBuilding() {
    cout << endl << "=== Редактирование здания ===" << endl;
    string name;
    cin.ignore();
    cout << "Введите название здания для редактирования: ";
    getline(cin, name);
    
    auto it = find_if(buildings.begin(), buildings.end(),
        [&name](const unique_ptr<Building>& b) {
            return b->getName() == name;
        });
    
    if (it == buildings.end()) {
        cout << "Здание не найдено." << endl;
        return;
    }
    
    cout << "Текущие данные:" << endl;
    (*it)->display();
    
    cout << endl << "Новое название (или Enter для пропуска): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty()) (*it)->setName(newName);
    
    cout << "Новое количество этажей (или -1 для пропуска): ";
    int floors;
    cin >> floors;
    if (floors != -1) (*it)->setFloors(floors);
    
    cout << "Новая площадь (или -1 для пропуска): ";
    double area;
    cin >> area;
    if (area != -1) (*it)->setArea(area);
    
    // Добавление собственника
    cin.ignore();
    cout << "Добавить собственника (или Enter для пропуска): ";
    string owner;
    getline(cin, owner);
    if (!owner.empty()) {
        (*it)->addOwner(owner);
        cout << "Собственник добавлен." << endl;
    }
    
    cout << "Данные обновлены!" << endl;
}

void removeBuilding() {
    cout << endl << "=== Удаление здания ===" << endl;
    string name;
    cin.ignore();
    cout << "Введите название здания для удаления: ";
    getline(cin, name);
    
    auto it = find_if(buildings.begin(), buildings.end(),
        [&name](const unique_ptr<Building>& b) {
            return b->getName() == name;
        });
    
    if (it == buildings.end()) {
        cout << "Здание не найдено." << endl;
        return;
    }
    
    buildings.erase(it);
    cout << "Здание удалено!" << endl;
}

void countResidentialWithManyApartments() {
    int count = count_if(buildings.begin(), buildings.end(),
        [](const unique_ptr<Building>& b) {
            if (auto rb = dynamic_cast<ResidentialBuilding*>(b.get())) {
                return rb->getNumApartments() > 100;
            }
            return false;
        });
    
    cout << endl << "=== Статистика ===" << endl;
    cout << "Жилых зданий с >100 квартирами: " << count << endl;
}

void findLargestOfficeBuilding() {
    auto it = max_element(buildings.begin(), buildings.end(),
        [](const unique_ptr<Building>& a, const unique_ptr<Building>& b) {
            auto oa = dynamic_cast<OfficeBuilding*>(a.get());
            auto ob = dynamic_cast<OfficeBuilding*>(b.get());
            if (!oa) return true;
            if (!ob) return false;
            return oa->getArea() < ob->getArea();
        });
    
    if (it != buildings.end() && dynamic_cast<OfficeBuilding*>((*it).get())) {
        cout << endl << "=== Самое большое офисное здание ===" << endl;
        (*it)->display();
    } else {
        cout << endl << "Офисные здания не найдены." << endl;
    }
}

void searchByOwner(const string& owner) {
    cout << endl << "=== Поиск по собственнику: " << owner << " ===" << endl;
    int count = 0;
    
    auto searchLambda = [&owner](const unique_ptr<Building>& b) {
        const auto& owners = b->getOwners();
        return find(owners.begin(), owners.end(), owner) != owners.end();
    };
    
    for (const auto& building : buildings) {
        if (searchLambda(building)) {
            building->display();
            count++;
        }
    }
    
    if (count == 0) {
        cout << "Зданий с таким собственником не найдено." << endl;
    }
}

// Основное меню
void showMenu() {
    cout << endl << "========== МЕНЮ ==========" << endl;
    cout << "1. Загрузить данные из файла" << endl;
    cout << "2. Сохранить данные в файл" << endl;
    cout << "3. Вывести все объекты" << endl;
    cout << "4. Фильтр: здания с этажностью > N" << endl;
    cout << "5. Сортировка по площади и этажности" << endl;
    cout << "6. Добавить новое здание" << endl;
    cout << "7. Редактировать существующее здание" << endl;
    cout << "8. Удалить здание" << endl;
    cout << "9. Статистика: жилые здания с >100 квартир" << endl;
    cout << "10. Найти самое большое офисное здание" << endl;
    cout << "11. Поиск по собственнику" << endl;
    cout << "0. Выход" << endl;
    cout << "==========================" << endl;
    cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "RU");
    
    int choice;
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                loadFromFile("city.txt");
                break;
            case 2:
                saveToFile("city_saved.txt");
                break;
            case 3:
                displayAll();
                break;
            case 4: {
                int minFloors;
                cout << "Введите минимальную этажность: ";
                cin >> minFloors;
                filterByFloors(minFloors);
                break;
            }
            case 5:
                sortByAreaAndFloors();
                break;
            case 6:
                addBuilding();
                break;
            case 7:
                editBuilding();
                break;
            case 8:
                removeBuilding();
                break;
            case 9:
                countResidentialWithManyApartments();
                break;
            case 10:
                findLargestOfficeBuilding();
                break;
            case 11: {
                string owner;
                cin.ignore();
                cout << "Введите имя собственника: ";
                getline(cin, owner);
                searchByOwner(owner);
                break;
            }
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);
    
    return 0;
}