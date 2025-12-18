#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Класс Light (управление освещением)
class Light {
private:
    bool isOn;

public:
    Light() : isOn(false) {} // Конструктор по умолчанию

    void turnOn() { isOn = true; }
    void turnOff() { isOn = false; }
    string getStatus() const { return isOn ? "On(Включен)" : "Off(Выключен)"; }
    bool getState() const { return isOn; }
    void setState(bool state) { isOn = state; }
};

// Класс Thermostat (управление термостатом)
class Thermostat {
private:
    int temperature;

public:
    Thermostat() : temperature(20) {} // Конструктор по умолчанию

    void setTemperature(int t) { temperature = t; }
    int getTemperature() const { return temperature; }
};

// Класс SecuritySystem (управление системой безопасности)
class SecuritySystem {
private:
    bool isArmed;

public:
    SecuritySystem() : isArmed(false) {} // Конструктор по умолчанию

    void arm() { isArmed = true; }
    void disarm() { isArmed = false; }
    string getStatus() const { return isArmed ? "Armed(Включена)" : "Disarmed(Выключена)"; }
    bool getState() const { return isArmed; }
    void setState(bool state) { isArmed = state; }
};

// Класс Curtains (управление шторами)
class Curtains {
private:
    bool isUp;

public:
    Curtains() : isUp(false) {} // Конструктор по умолчанию

    void raise() { isUp = true; }
    void lower() { isUp = false; }
    string getStatus() const { return isUp ? "Raised(Подняты)" : "Lowered(Опущены)"; }
    bool getState() const { return isUp; }
    void setState(bool state) { isUp = state; }
};

// Класс AirConditioner (управление кондиционером)
class AirConditioner {
private:
    bool isOn;

public:
    AirConditioner() : isOn(false) {} // Конструктор по умолчанию

    void turnOn() { isOn = true; }
    void turnOff() { isOn = false; }
    string getStatus() const { return isOn ? "On(Включен)" : "Off(Выключен)"; }
    bool getState() const { return isOn; }
    void setState(bool state) { isOn = state; }
};

// Основной класс SmartHome
class SmartHome {
private:
    Light light;
    Thermostat thermostat;
    SecuritySystem securitySystem;
    Curtains curtains;
    AirConditioner airConditioner;
    string stateFile;

public:
    SmartHome(string filename = "home_state.txt") : stateFile(filename) {}

    // Управление компонентами
    void controlLight(bool state) { light.setState(state); }
    void setTemperature(int temp) { thermostat.setTemperature(temp); }
    void controlSecurity(bool state) { securitySystem.setState(state); }
    void controlCurtains(bool state) { curtains.setState(state); }
    void controlAirConditioner(bool state) { airConditioner.setState(state); }

    // Вывод состояния всех систем
    void displayStatus() const {
        cout << "Current State(Текущее состояние):" << endl;
        cout << "Light(Освещение): " << light.getStatus() << endl;
        cout << "Temperature(Температура): " << thermostat.getTemperature() << "°C" << endl;
        cout << "Security System(Система безопасности): " << securitySystem.getStatus() << endl;
        cout << "Curtains(Шторы): " << curtains.getStatus() << endl;
        cout << "Air Conditioner(Кондиционер): " << airConditioner.getStatus() << endl;
    }

    // Сохранение состояния в файл
    void saveState() {
        ofstream file(stateFile);
        if (file.is_open()) {
            file << light.getState() << endl;
            file << thermostat.getTemperature() << endl;
            file << securitySystem.getState() << endl;
            file << curtains.getState() << endl;
            file << airConditioner.getState() << endl;
            file.close();
            cout << "State saved to " << stateFile << ". Exiting...(Состояние сохранено в файл. Выход...)" << endl;
        } else {
            cout << "Error saving state to file(Ошибка сохранения состояния в файл)!" << endl;
        }
    }

    // Загрузка состояния из файла
    void loadState() {
        ifstream file(stateFile);
        if (file.is_open()) {
            bool lightState, securityState, curtainsState, acState;
            int temp;
            file >> lightState >> temp >> securityState >> curtainsState >> acState;
            light.setState(lightState);
            thermostat.setTemperature(temp);
            securitySystem.setState(securityState);
            curtains.setState(curtainsState);
            airConditioner.setState(acState);
            file.close();
            cout << "State loaded from file.(Состояние загружено из файла.)" << endl;
        } else {
            cout << "No previous state file found. Using default settings.(Файл предыдущего состояния не найден. Используются настройки по умолчанию.)" << endl;
        }
    }

    // Геттеры для получения текущего состояния
    bool getLightState() const { return light.getState(); }
    int getTemperature() const { return thermostat.getTemperature(); }
    bool getSecurityState() const { return securitySystem.getState(); }
    bool getCurtainsState() const { return curtains.getState(); }
    bool getAirConditionerState() const { return airConditioner.getState(); }
};

int main() {
    SmartHome smartHome;
    smartHome.loadState(); // Загружаем состояние при запуске

    int choice;
    bool exit = false;

    while (!exit) {
        cout << "\n";
        smartHome.displayStatus();
        cout << "\nChoose an action(Выберите действие):" << endl;
        cout << "1. Turn on light(Включить свет)" << endl;
        cout << "2. Turn off light(Выключить свет)" << endl;
        cout << "3. Set temperature(Установить температуру)" << endl;
        cout << "4. Arm security system(Включить систему безопасности)" << endl;
        cout << "5. Disarm security system(Выключить систему безопасности)" << endl;
        cout << "6. Raise curtains(Поднять шторы)" << endl;
        cout << "7. Lower curtains(Опустить шторы)" << endl;
        cout << "8. Turn on air conditioner(Включить кондиционер)" << endl;
        cout << "9. Turn off air conditioner(Выключить кондиционер)" << endl;
        cout << "10. Exit(Выход)" << endl;
        cout << "Enter your choice(Введите ваш выбор): ";
        cin >> choice;

        switch (choice) {
            case 1:
                smartHome.controlLight(true);
                break;
            case 2:
                smartHome.controlLight(false);
                break;
            case 3:
                int temp;
                cout << "Enter temperature(Введите температуру): ";
                cin >> temp;
                smartHome.setTemperature(temp);
                break;
            case 4:
                smartHome.controlSecurity(true);
                break;
            case 5:
                smartHome.controlSecurity(false);
                break;
            case 6:
                smartHome.controlCurtains(true);
                break;
            case 7:
                smartHome.controlCurtains(false);
                break;
            case 8:
                smartHome.controlAirConditioner(true);
                break;
            case 9:
                smartHome.controlAirConditioner(false);
                break;
            case 10:
                smartHome.saveState();
                exit = true;
                break;
            default:
                cout << "Invalid choice(Неверный выбор). Try again(Попробуйте еще раз)." << endl;
        }
    }

    return 0;
}