#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Login.cpp"
#include "Room.cpp"

using namespace std;

class HotelManagement {
private:
    vector<Room> rooms;

public:    
    void manageRooms() {
        int opt, rno;

        do {
            cout << "\n-------------------------";
            cout << "\n      Manage Rooms";
            cout << "\n-------------------------";
            cout << "\n1. Add Room";
            cout << "\n2. Back to Main Menu";
            cout << "\n-------------------------";
            cout << "\n\nEnter Option: ";
            cin >> opt;

            switch (opt) {
                case 1:
                    cout << "\n----------------------------------------";
                    cout << "\nEnter Room Number: ";
                    cin >> rno;
                    rooms.push_back(Room(rno));
                    rooms.back().addRoom();
                    break;
                case 2:
                    // Go back to the main menu
                    break;
                default:
                    cout << "\nPlease Enter correct option";
                    break;
            }
        } while (opt != 2);
    }

    void checkIn() {
        int i, found = 0, rno;

        cout << "\nEnter Room number : ";
        cin >> rno;

        for (i = 0; i < rooms.size(); i++) {
            if (rooms[i].roomNumber == rno) {
                found = 1;
                break;
            }
        }

        if (found == 1) {
            if (rooms[i].status == 1) {
                cout << "\nRoom is already Booked";
            } else {
                cout << "\nEnter booking id: ";
                cin >> rooms[i].customer.booking_id;

                cout << "\nEnter Customer Name: ";
                cin >> rooms[i].customer.name;

                cout << "\nEnter Customer Age: ";
                cin >> rooms[i].customer.age;

                cout << "\nEnter Address: ";
                cin >> rooms[i].customer.address;

                cout << "\nEnter Phone: ";
                cin >> rooms[i].customer.phone;

                cout << "\nEnter From Date: ";
                cin >> rooms[i].customer.from_date;

                cout << "\nEnter to  Date: ";
                cin >> rooms[i].customer.to_date;

                cout << "\nEnter Advance Payment: ";
                cin >> rooms[i].customer.payment_advance;

                rooms[i].status = 1;

                cout << "\n Customer Checked-in Successfully..";
            }
        } else {
            cout << "\nRoom not found!";
        }
    }

    void getAvailRoom() {
        int i, found = 0;

        for (i = 0; i < rooms.size(); i++) {
            if (rooms[i].status == 0) {
                rooms[i].displayRoom();
                cout << "\n\nPress enter for next room";
                found = 1;
            }
        }

        if (found == 0) {
            cout << "\nAll rooms are reserved";
        }
    }

    void searchCustomer(const string& pname) {
        int i, found = 0;

        for (i = 0; i < rooms.size(); i++) {
            if (rooms[i].status == 1 && rooms[i].customer.name == pname) {
                cout << "\nCustomer Name: " << rooms[i].customer.name;
                cout << "\nRoom Number: " << rooms[i].roomNumber;

                cout << "\n\nPress enter for next record";
                found = 1;
            }
        }

        if (found == 0) {
            cout << "\nPerson not found.";
        }
    }

    void checkOut(int roomNum) {
        int i, found = 0, days, rno;
        float billAmount = 0;

        for (i = 0; i < rooms.size(); i++) {
            if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum) {
                found = 1;
                break;
            }
        }

        if (found == 1) {
            cout << "\nEnter Number of Days:\t";
            cin >> days;
            billAmount = days * rooms[i].rent;

            cout << "\n\t######## CheckOut Details ########\n";
            cout << "\nCustomer Name : " << rooms[i].customer.name;
            cout << "\nRoom Number : " << rooms[i].roomNumber;
            cout << "\nAddress : " << rooms[i].customer.address;
            cout << "\nPhone : " << rooms[i].customer.phone;
            cout << "\nTotal Amount Due : " << billAmount << "$";
            cout << "\nAdvance Paid: " << rooms[i].customer.payment_advance << "$";
            cout << "\n*** Total Payable: " << billAmount - rooms[i].customer.payment_advance << "$ only";

            rooms[i].status = 0;
        }
    }

    void guestSummaryReport() {
        if (rooms.empty()) {
            cout << "\n No Guest in Hotel !!";
        } else {
            for (int i = 0; i < rooms.size(); i++) {
                if (rooms[i].status == 1) {
                    cout << "\n Customer Name : " << rooms[i].customer.name;
                    cout << "\n Room Number : " << rooms[i].roomNumber;
                    cout << "\n Address : " << rooms[i].customer.address;
                    cout << "\n Phone : " << rooms[i].customer.phone;
                    cout << "\n---------------------------------------";
                }
            }
        }
    }

    void saveToFile(){
        string filename;
        cout << "Enter File name to save: ";
        cin >> filename;

        ofstream file(filename);
        if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }
     for (const auto &rooms : rooms)
    {
        file << rooms.customer.booking_id << ","
             << rooms.customer.name << ","
             
             << rooms.customer.age << ","
             << rooms.customer.address << ","
             << rooms.customer.phone << ","
             << rooms.customer.from_date << ","
             << rooms.customer.to_date << ","
             << rooms.customer.payment_advance << endl;
    }

    file.close();
    cout << "File saved successfully!" << endl;
    }

};
