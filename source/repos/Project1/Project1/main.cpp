#include <iostream>
using namespace std;

class Elevator {
private:
    int currentFloor;
    int minFloor;
    int maxFloor;
    bool isOperational;

public:
    // ����������� �� ���������
    Elevator() : currentFloor(0), minFloor(0), maxFloor(10), isOperational(false) {}

    // ����� ��� ��������� ��������� �������� �����
    void setRange(int min, int max) {
        minFloor = min;
        maxFloor = max;
    }

    // ����� ��� ��������� �����
    void turnOn() {
        isOperational = true;
    }

    // ����� ��� ���������� �����
    void turnOff() {
        isOperational = false;
    }

    // ����� ��� ��������� �������� ��������� �����
    bool getStatus() const {
        return isOperational;
    }

    // ����� ��� ��������� �������� ��������� �����
    int getCurrentFloor() const {
        return currentFloor;
    }

    // ����� ��� ��������� ������ �����
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

// �������� ���������
int main() {
    Elevator elevator;

    elevator.setRange(0, 10); // ��������� ��������� ������
    elevator.turnOn(); // ��������� �����

    cout << "Elevator status: " << (elevator.getStatus() ? "Operational" : "Not Operational") << endl;
    cout << "Current floor: " << elevator.getCurrentFloor() << endl;

    elevator.callElevator(5); // ����� ����� �� 5 ����
    cout << "Current floor: " << elevator.getCurrentFloor() << endl;

    elevator.callElevator(15); // ������� ������ ����� �� 15 ���� (��� ���������)

    elevator.turnOff(); // ���������� �����
    elevator.callElevator(2); // ������� ������ ����� ��� ����������� ���������

    return 0;
}
