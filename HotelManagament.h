#ifndef HOTELMANAGEMENT_H
#define HOTELMANAGEMENT_H

#include "Room.cpp"

using namespace std;

class HotelManagement {
private:
   vector<Room> rooms;

public:
    void manageRooms();

    void checkIn() {
        // Implementation
        // You can access Room functions here since it includes Room.cpp
    }

    // Add other member functions as needed
};

#endif
