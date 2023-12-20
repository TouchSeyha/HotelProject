#include <iostream>
#include <string>
using namespace std;

bool login() {
    string username, password;

    do {
        cout << "-------------------------\n";
        cout << "      Admin Login\n";
        cout << "-------------------------\n";
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "Seyha" && password == "123") {
            return true;  // Login successful
        } else {
            cout << "Invalid username or password. Please try again.\n";
        }
    } while (true);
}
