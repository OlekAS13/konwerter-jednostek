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

string menu_temperature[] = {
    "[KONWERSJA TEMPERATUR]",
    "Celsjusz",
    "Farenheit",
    "Kelvin"
};

string menu_main[] = {
    "[KONWERTER JEDNOSTEK]",
    "Konwertowanie",
    "Historia",
    "Ulubione",
    "Wyjscie"
};

string menu_conversion[] = {
    "[KATEGORIA KONWERSJI]",
    "Dlugosc",
    "Masa",
    "Temperatura",
    "Czas",
    "Predkosc",
    "Cisnienie",
    "Energia",
    "Moc",
    "Waluty",
    "Wyjscie"
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
    cout << "\rEnter aby wyjsc... ";

    cin.ignore();
    cin.get();
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
    cout << "\rEnter aby wyjsc... ";

    cin.ignore();
    cin.get();
}

void convert_temperature(double value, int unit, double out[3]) {
    double a_factor[3] = {1.0, 5.0/9.0, 1.0};
    double b_factor[3] = {0.0, -160.0/9.0, -273.15};
    unit--;
    double celsius = value * a_factor[unit] + b_factor[unit];

    for (int i = 0; i < 3; i++) {
        out[i] = (celsius - b_factor[i]) / a_factor[i];
    }
}

void display_temperatures(double temperatures[], string unit) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - " << unit << "]\n\n";
    cout << "Celsjusz: " << temperatures[0] << endl;
    cout << "Farenheit: " << temperatures[1] << endl;
    cout << "Kelvin: " << temperatures[2] << endl;
    cout << "\n\n======================\n";
    cout << "\033[2A";
    cout << "\rEnter aby wyjsc... ";

    cin.ignore();
    cin.get();
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

void conversion_lenghts() {
    int choice;
    double value;
    double lengths[4];

    choice = getMenu(menu_length, 5);

    value = getValue(menu_length[choice]);

    convert_length(value, choice, lengths);
    display_lengths(lengths, menu_length[choice]);
}

void conversion_masses() {
    int choice;
    double value;
    double masses[4];

    choice = getMenu(menu_mass, 5);

    value = getValue(menu_mass[choice]);

    convert_mass(value, choice, masses);
    display_masses(masses, menu_mass[choice]);
}

void conversion_temperatures() {
    int choice;
    double value;
    double temperatures[3];

    choice = getMenu(menu_temperature, 4);

    value = getValue(menu_temperature[choice]);

    convert_temperature(value, choice, temperatures);
    display_temperatures(temperatures, menu_temperature[choice]);
}

void history() {

}

void favourites() {

}

void conversion_main() {
    int menu;

    do {
        menu = getMenu(menu_conversion, 11);
        switch(menu) {
            case 1:
                conversion_lenghts();
                break;
            case 2:
                conversion_masses();
                break;
            case 3:
                conversion_temperatures();
            case 10:
                break;
            default:
                cout << "\a";
                break;
        }
    } while (menu != 10);
}

int main() {
    int menu;

    do {
        menu = getMenu(menu_main, 5);
        switch(menu) {
            case 1:
                conversion_main();
                break;
            case 2:
                history();
                break;
            case 3:
                favourites();
                break;
            case 4:
                break;
            default:
                cout << "\a";
                break;
        }
    } while (menu != 4);

}

