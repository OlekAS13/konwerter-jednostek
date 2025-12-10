#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double meters, inches, miles;

void drawMenu() {
    cout << "\033[2J\033[H";
    cout << "======================\n";
    cout << "[KONWERTER JEDNOSTEK]\n\n";
    cout << "1. - Konwertuj\n";
    cout << "2. - Wyswietl historie\n";
    cout << "3. - Ulubione\n\n\n";
    cout << "======================";

    cout << "\033[1A";
    cout << "\r>> ";
}

void drawChoice() {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[WYBOR JEDNOSTKI]\n\n";
    cout << "1. - Metr\n";
    cout << "2. - Cal\n";
    cout << "3. - Mila\n\n\n";
    cout << "======================";

    cout << "\033[1A";
    cout << "\r>> ";
}

void drawGetValue(string which) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[WARTOSC - " << which << "]\n\n";
    cout << "======================";

    cout << "\033[1A";
    cout << "\r>> ";
}

void drawOutputValues() {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - metry]\n\n";
    cout << "Metry: " << meters << " m\n";
    cout << "Cale: " << inches << " in\n";
    cout << "Mile: " << miles << " mi\n\n";
    cout << "======================";

    cout << "\033[1A";
}

int main() {
    int choice;

    drawMenu();

    cin >> choice;

    // Konwertowanie
    if (choice == 1) {
        
        drawChoice();

        cin >> choice;

        // Konwertowanie z metrow
        if (choice == 1) {
            int value;

            drawGetValue("metry");

            cin >> value;

            meters = value;
            inches = meters * 0.0254;
            miles = meters * 0.0006213712;
            
            drawOutputValues();
        }

        else if (choice == 2) {
            int value;

            drawGetValue("cale");

            cin >> value;
        }

        else if (choice == 3) {
            int value;

            drawGetValue("mile");

            cin >> value;
        }
    }
}