#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int choice;

    cout << "\033[2J\033[H";
    cout << "======================\n";
    cout << "[KONWERTER JEDNOSTEK]\n\n";
    cout << "1. - Konwertuj\n";
    cout << "2. - Wyswietl historie\n";
    cout << "3. - Ulubione\n\n\n";
    cout << "======================";

    cout << "\033[1A";
    cout << "\r>> ";

    cin >> choice;

    // Konwertowanie
    if (choice == 1) {
        cout << "\033[2J\033[H";

        cout << "======================\n";
        cout << "[WYBOR JEDNOSTKI]\n\n";
        cout << "1. - Metr\n";
        cout << "2. - Cal\n";
        cout << "3. - Mila\n\n\n";
        cout << "======================";

        cout << "\033[1A";
        cout << "\r>> ";

        cin >> choice;

        // Konwertowanie z metrow
        if (choice == 1) {
            int value;

            cout << "\033[2J\033[H";

            cout << "======================\n";
            cout << "[WARTOSC]\n\n";
            cout << "======================";
            cout << "\033[1A";
            cout << "\r>> ";

            cin >> value;
        }
    }
}