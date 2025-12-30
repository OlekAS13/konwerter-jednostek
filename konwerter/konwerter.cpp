#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long double meters, inches, miles, kilometers;

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
    cout << "3. - Mila\n";
    cout << "4. - Kilometry\n\n\n";
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

void drawOutputValues(string which) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - " << which << "]\n\n";
    cout << "Metry: " << meters << " m\n";
    cout << "Cale: " << inches << " in\n";
    cout << "Mile: " << miles << " mi\n";
    cout << "Kilometry: " << kilometers << " km\n\n";
    cout << "======================";

    cout << "\033[1A";
}

int main() {
    int choice;

    drawMenu();

    cin >> choice;

    // Konwertowanie
    if (choice == 1) {
        
        fstream history;
        history.open ("HistoriaKonwersji.txt",ios::out|ios::app);
        
        drawChoice();

        cin >> choice;

        // Konwertowanie z metrow
        if (choice == 1) {
            
            int value;

            drawGetValue("metry");

            cin >> value;

            meters = value;
            inches = meters * 39.3700787;
            miles = meters * 0.0006213712; 
            kilometers = meters * 1000;
            
            drawOutputValues("metry");
            
            history << "Konwertowanie z " << value << " metrów\n";
        }

        // Konwertowanie z cali
        else if (choice == 2) {

            int value;

            drawGetValue("cale");

            cin >> value;
            
            inches = value;
            meters = inches * 0.0254;
            miles = inches * 0.0000158;  
            kilometers = meters * 1000;
            
            drawOutputValues("cale");
            
            history << "Konwertowanie z " << value << " cali\n";
        }

        // Konwertowanie z mil
        else if (choice == 3) {
            
            int value;

            drawGetValue("mile");

            cin >> value;
            
            miles = value;
            meters = miles * 1609.344;
            inches = miles * 63360; 
            kilometers = meters * 1000;
            
            drawOutputValues("mile");
            
            history << "Konwertowanie z " << value << " mil\n";
        }
        
        // Konwertowanie z kilometrow
        else if (choice == 4) {
            
            int value;

            drawGetValue("kilometry");

            cin >> value;
            
            kilometers = value;
            meters = kilometers * 0.001;
            inches = meters * 39.3700787;
            miles = meters * 0.0006213712; 
            
            drawOutputValues("kilometry");
            
            history << "Konwertowanie z " << value << " kilometrów\n";
        }
        history.close();
    }
    if (choice == 2) {

        ifstream history ("HistoriaKonwersji.txt");
        if (history.is_open())
        {
            cout << "\033[2J\033[H";

            cout << "======================\n";
            cout << "[HISTORIA KONWERSJI]\n\n";
            char row[10000];
            while (history.getline(row,10000))
            {
                cout << row << endl;
            }
            cout << "\n======================";
        }
        else cout << "Zadna konwersja nie zostala jeszcze wykonana";

    }
}
