#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser();
bool login();
bool checkCredentials(const string& username, const string& password);

int main() {
    int choice;

    do {
        cout << "\n*** Login and Registration System ***\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (login()) {
                    cout << "Login successful!\n";
                } else {
                    cout << "Invalid username or password!\n";
                }
                break;
            case 3:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}

void registerUser() {
    string username, password;
    cout << "\n--- Register User ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("registrationcredentials.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error: Could not open file for writing.\n";
    }
}

bool login() {
    string username, password;
    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    return checkCredentials(username, password);
}

bool checkCredentials(const string& username, const string& password) {
    ifstream file("Registrationcredentials.txt");  
    string storedUsername, storedPassword;

    if (file.is_open()) {  
        while (file >> storedUsername >> storedPassword) {  
            if (storedUsername == username && storedPassword == password) {
                file.close();  
                return true;  
            }
        }
    }
    file.close(); 
    return false;  
}