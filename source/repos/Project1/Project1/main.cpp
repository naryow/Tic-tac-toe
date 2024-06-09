#include <iostream>
using namespace std;

class Elevator {
private:
    int currentFloor;
    int minFloor;
    int maxFloor;
    bool isOperational;

public:
    // Конструктор по умолчанию
    Elevator() : currentFloor(0), minFloor(0), maxFloor(10), isOperational(false) {}

    // Метод для установки диапазона движения лифта
    void setRange(int min, int max) {
        minFloor = min;
        maxFloor = max;
    }

    // Метод для включения лифта
    void turnOn() {
        isOperational = true;
    }

    // Метод для выключения лифта
    void turnOff() {
        isOperational = false;
    }

    // Метод для получения текущего состояния лифта
    bool getStatus() const {
        return isOperational;
    }

    // Метод для получения текущего положения лифта
    int getCurrentFloor() const {
        return currentFloor;
    }

    // Метод для обработки вызова лифта
    void callElevator(int floor) {
        if (isOperational && floor >= minFloor && floor <= maxFloor) {
            cout << "Moving from floor " << currentFloor << " to floor " << floor << endl;
            currentFloor = floor;
        }
        else if (!isOperational) {
            cout << "Elevator is not operational." << endl;
        }
        else {
            cout << "Floor out of range." << endl;
        }
    }
};

// Тестовая программа
int main() {
    Elevator elevator;

    elevator.setRange(0, 10); // Установка диапазона этажей
    elevator.turnOn(); // Включение лифта

    cout << "Elevator status: " << (elevator.getStatus() ? "Operational" : "Not Operational") << endl;
    cout << "Current floor: " << elevator.getCurrentFloor() << endl;

    elevator.callElevator(5); // Вызов лифта на 5 этаж
    cout << "Current floor: " << elevator.getCurrentFloor() << endl;

    elevator.callElevator(15); // Попытка вызова лифта на 15 этаж (вне диапазона)

    elevator.turnOff(); // Выключение лифта
    elevator.callElevator(2); // Попытка вызова лифта при выключенном состоянии

    return 0;
}
