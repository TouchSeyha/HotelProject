#include <iostream>
#include "HotelManagement.cpp"
using namespace std;

int main() {
    HotelManagement hotel;
    int opt;
    string pname;

    do {
    cout << "\n----------------------------------------";
    cout << "\n        Welcome to Hotel Management";
    cout << "\n----------------------------------------";
    cout << "\n1. Manage Rooms";
    cout << "\n2. Check-In Room";
    cout << "\n3. Available Rooms";
    cout << "\n4. Search Customer";
    cout << "\n5. Check-Out Room";
    cout << "\n6. Guest Summary Report";
    cout << "\n7. Exit";
    cout << "\n----------------------------------------";
    cout << "\nEnter Option: ";
        cin >> opt;

        switch (opt) {
            case 1:
                hotel.manageRooms();
                break;
            case 2:
                hotel.checkIn();
                break;
            case 3:
                hotel.getAvailRoom();
                break;
            case 4:
                cout << "Enter Customer Name: ";
                cin >> pname;
                hotel.searchCustomer(pname);
                break;
            case 5:
                int rno;
                cout << "Enter Room Number : ";
                cin >> rno;
                hotel.checkOut(rno);
                break;
            case 6:
                hotel.guestSummaryReport();
                break;
            case 7:
                cout << "\nTHANK YOU!";
                break;
            default:
                cout << "\nInvalid Option. Please try again.\n";
                break;
        }
    } while (opt != 7);

    return 0;
}
