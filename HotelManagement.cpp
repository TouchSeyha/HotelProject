#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <limits>
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
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNum](const Room& room) {
        return room.status == 1 && room.roomNumber == roomNum;
    });

    if (it != rooms.end()) {
        int days;
        float billAmount = 0;

        cout << "\nEnter Number of Days:\t";
        cin >> days;
        billAmount = days * it->rent;

        cout << "\n\t######## CheckOut Details ########\n";
        cout << "\nCustomer Name : " << it->customer.name;
        cout << "\nRoom Number : " << it->roomNumber;
        cout << "\nAddress : " << it->customer.address;
        cout << "\nPhone : " << it->customer.phone;
        cout << "\nTotal Amount Due : " << billAmount << "$";
        cout << "\nAdvance Paid: " << it->customer.payment_advance << "$";
        cout << "\n*** Total Payable: " << billAmount - it->customer.payment_advance << "$ only";

        // Set the status to 0 and erase the room from the vector
        it->status = 0;
        rooms.erase(it);

        cout << "\n Customer Checked-out Successfully..";
    } else {
        cout << "\nRoom not found or not checked-in!";
    }
}

    void displayGuestreport() {
    if (rooms.empty()) {
        cout << "\n No Guest in Hotel !!";
    } else {
        cout << "\nNumber of Rooms: " << rooms.size() << endl;

        for (const auto &room : rooms) {
            cout << "\nRoom Number: " << room.roomNumber << endl;
            cout << "Status: " << room.status << endl;

            if (room.status == 1) {
                cout << "\n Customer Name : " << room.customer.name;
                cout << "\n Room Number : " << room.roomNumber;
                cout << "\n Address : " << room.customer.address;
                cout << "\n Phone : " << room.customer.phone;
                cout << "\n---------------------------------------";
            }
        }
    }
}

 void saveToFile() {
    string filename;
    cout << "Enter File name to save: ";
    cin >> filename;

    ofstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    for (const auto &room : rooms) {
        file << room.roomNumber << ","  
             << room.customer.booking_id << ","
             << room.customer.name << ","
             << room.customer.age << ","
             << room.customer.address << ","
             << room.customer.phone << ","
             << room.customer.from_date << ","
             << room.customer.to_date << ","
             << room.customer.payment_advance << ","
             << room.rent << endl;  
    }

    file.close();
    cout << "File saved successfully!" << endl;
}




 void uploadFile() {
    string fileName;
    cout << "Enter File name to upload: ";
    cin >> fileName;

    ifstream file(fileName);

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Clear existing room data
    rooms.clear();

    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        lineNumber++;

        cout << "Reading line: " << line << endl;

        stringstream ss(line);
        string item;

        int roomNumber, bookingId, age;
        string name, address, phone, fromDate, toDate;
        float paymentAdvance, rent;

        // Read roomNumber from the beginning of the line
        getline(ss, item, ',');
        try {
            roomNumber = stoi(item);
        } catch (const invalid_argument& e) {
            cout << "Error reading roomNumber (line " << lineNumber << "): " << e.what() << endl;
            continue;
        }

        // Continue reading other data
        getline(ss, item, ',');
        try {
            bookingId = stoi(item);
        } catch (const invalid_argument& e) {
            cout << "Error reading bookingId (line " << lineNumber << "): " << e.what() << endl;
            continue;
        }

        getline(ss, name, ',');

        getline(ss, item, ',');
        try {
            age = stoi(item);
        } catch (const invalid_argument& e) {
            cout << "Error reading age: " << e.what() << endl;
            continue;
        }

        getline(ss, address, ',');

        getline(ss, phone, ',');

        getline(ss, fromDate, ',');

        getline(ss, toDate, ',');

        getline(ss, item, ',');
        try {
            paymentAdvance = stof(item);
        } catch (const invalid_argument& e) {
            cout << "Error reading paymentAdvance: " << e.what() << endl;
            continue;
        }

        getline(ss, item);
        try {
            rent = stof(item);
        } catch (const invalid_argument& e) {
            cout << "Error reading rent: " << e.what() << endl;
            continue;
        }

        Room room(roomNumber);
        room.customer.booking_id = bookingId;
        room.customer.name = name;
        room.customer.age = age;
        room.customer.address = address;
        room.customer.phone = phone;
        room.customer.from_date = fromDate;
        room.customer.to_date = toDate;
        room.customer.payment_advance = paymentAdvance;
        room.rent = rent;

        room.status = 1;

        rooms.push_back(room);
    }

    file.close();
    cout << "File loaded successfully!" << endl;
}












};
