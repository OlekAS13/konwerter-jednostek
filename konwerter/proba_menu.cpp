#include <iostream>

using namespace std;

string menu_length[] = {
    "[KONWERSJA DLUGOSCI]",
	"Metry",
	"Cale",
	"Mile",
	"Kilometry"};

string menu_mass[] = {
    "[KONWERSJA MAS]",
    "Gramy",
    "Uncje",
    "Funty",
    "Kilogramy"
};

void convert_length(double value, int unit, double out[4]) {
    double length_factor[4] = {1.0, 0.0254, 1609.34, 1000};
    unit--; // bo przeliczniki indeksujemy od 0, natomiast menu mamy indeksowane od 1
    double meters = value * length_factor[unit];

    for (int i = 0; i < 4; i++) {
        out[i] = meters / length_factor[i];
    }
}

void display_lengths(double lengths[], string unit) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - " << unit << "]\n\n";
    cout << "Metry: " << lengths[0] << endl;
    cout << "Cale: " << lengths[1] << endl;
    cout << "Mile: " << lengths[2] << endl;
    cout << "Kilometry: " << lengths[3] << endl;
    cout << "\n\n======================\n";
    cout << "\033[2A";
}

void convert_mass(double value, int unit, double out[4]) {
    double mass_factor[4] = {1.0, 28.35, 453.59, 1000}; 
    unit--; // bo przeliczniki indeksujemy od 0, natomiast menu mamy indeksowane od 1
    double grams = value * mass_factor[unit];

    for (int i = 0; i < 4; i++) {
        out[i] = grams / mass_factor[i];
    }
}

void display_masses(double masses[], string unit) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - " << unit << "]\n\n";
    cout << "Gramy: " << masses[0] << endl;
    cout << "Uncje: " << masses[1] << endl;
    cout << "Funty: " << masses[2] << endl;
    cout << "Kilogramy: " << masses[3] << endl;
    cout << "\n\n======================\n";
    cout << "\033[2A";
}

int getMenu(string menu[], int max_pos) {
	int choice;

    cout << "\033[2J\033[H";
    cout << "======================\n";
    cout << menu[0] << endl << endl;

	for (int i = 1; i < max_pos; i++) {
		cout << i << ". " << menu[i] << endl;
	}

    cout << "\n\n======================";
	cout << "\033[1A";
    cout << "\r>> ";

	cin >> choice;

	return choice;
}

double getValue(string unit) {
    double value;

    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[WARTOSC - " << unit << "]\n\n";
    cout << "======================";

    cout << "\033[1A";
    cout << "\r>> ";

    cin >> value;

    return value;
}



int main() {
    double lengths[4];
    double masses[4];
    int choice;
    double value;

    choice = getMenu(menu_length, 5);

    value = getValue(menu_length[choice]);

    convert_length(value, choice, lengths);
    display_lengths(lengths, menu_length[choice]);
    cin >> choice;

    choice = getMenu(menu_mass, 5);

    value = getValue(menu_mass[choice]);

    convert_mass(value, choice, masses);
    display_masses(masses, menu_mass[choice]);


}

