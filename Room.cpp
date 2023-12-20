#include <iostream>
#include <string>
#include "Customer.cpp"
using namespace std;

class Room {
public:
    char type;
    char stype;
    char ac;
    int roomNumber;
    int rent;
    int status;
    Customer customer;

    Room(int rno) : roomNumber(rno), status(0) {}

    void addRoom() {
        cout << "\nType AC/Non-AC (A/N): ";
        cin >> ac;
        cout << "\nType Comfort (S/N): ";
        cin >> type;
        cout << "\nType Size (B/S): ";
        cin >> stype;
        cout << "\nDaily Rent: ";
        cin >> rent;
        status = 0;

        cout << "\n Room Added Successfully!";
    }

    void displayRoom() {
        cout << "\nRoom Number: \t" << roomNumber;
        cout << "\nType AC/Non-AC (A/N) " << ac;
        cout << "\nType Comfort (S/N) " << type;
        cout << "\nType Size (B/S) " << stype;
        cout << "\nRent: " << rent;
    }
};
