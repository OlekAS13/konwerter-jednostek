#include <iostream>
#include <fstream>

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

string menu_favorites[] = {
    "[ULUBIONE KONWERSJE]",
    "Puste",
    "Puste",
    "Puste",
    "Puste",
    "Puste",
    "Dodaj / Modyfikuj",
    "Usun",
    "Wyjscie"
};

int favourites_conversions[5][2] = { // 5 ulubionych pozycji jako tablica 2-elementowa: {kategoria, konwersja}
    {1, 1},
    {2, 3},
    {0, 0},
    {0, 0},
    {3, 2}
};

void save_history(string line) {
    ofstream history("historia_konwersji.txt", ios::app);
    history << line << endl;
}

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

    save_history("[KONWERSJA - " + unit + "] Metry: " + to_string(lengths[0]) + "; Cale: " + to_string(lengths[1]) + "; Mile: " + to_string(lengths[2]) + "; Kilometry: " + to_string(lengths[3]));
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

    save_history("[KONWERSJA - " + unit + "] Gramy: " + to_string(masses[0]) + "; Uncje: " + to_string(masses[1]) + "; Funty: " + to_string(masses[2]) + "; Kilogramy: " + to_string(masses[3]));
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

    save_history("[KONWERSJA - " + unit + "] Celsjusz: " + to_string(temperatures[0]) + "; Farenheit: " + to_string(temperatures[1]) + "; Kelvin: " + to_string(temperatures[2]));
    cin.ignore();
    cin.get();
}

void convert_time() {

}

int getMenu(string menu[], int max_pos, string prompt = ">> ") {
	int choice;

    do {
        cout << "\033[2J\033[H";
        cout << "======================\n";
        cout << menu[0] << endl << endl;

        for (int i = 1; i < max_pos; i++) {
            cout << i << ". " << menu[i] << endl;
        }

        cout << "\n\n======================";
        cout << "\033[1A\r";
        cout << prompt;

        cin >> choice;

        if (choice < 1 || choice >= max_pos) {
            cout << "\a";
        }
    } while (choice < 1 || choice >= max_pos);

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

void conversion_lenghts(int choice = -1) {
    double value;
    double lengths[4];

    if (choice == -1) {
        choice = getMenu(menu_length, 5);
    }

    value = getValue(menu_length[choice]);

    convert_length(value, choice, lengths);
    display_lengths(lengths, menu_length[choice]);
}

void conversion_masses(int choice = -1) {
    double value;
    double masses[4];

    if (choice == -1) {
        choice = getMenu(menu_mass, 5);
    }

    value = getValue(menu_mass[choice]);

    convert_mass(value, choice, masses);
    display_masses(masses, menu_mass[choice]);
}

void conversion_temperatures(int choice = -1) {
    double value;
    double temperatures[3];

    if (choice == -1) {
        choice = getMenu(menu_temperature, 4);
    }

    value = getValue(menu_temperature[choice]);

    convert_temperature(value, choice, temperatures);
    display_temperatures(temperatures, menu_temperature[choice]);
}

void history() {

}

void update_favorites_menu() {
    for (int i = 0; i < 5; i++) {
        switch (favourites_conversions[i][0]) {
            case 1:
                menu_favorites[i + 1] = menu_length[favourites_conversions[i][1]];
                break;
            case 2:
                menu_favorites[i + 1] = menu_mass[favourites_conversions[i][1]];
                break;
            case 3:
                menu_favorites[i + 1] = menu_temperature[favourites_conversions[i][1]];
                break;
            default:
                menu_favorites[i + 1] = "Puste";
                break;
        }
    }
}

void modify_favorites() {
    int choice;

    choice = getMenu(menu_favorites, 6, "Modyfikuj >> ");

    if (choice >= 1 && choice <= 5) {
        int category = getMenu(menu_conversion, 10, "Kategoria >> ");
        int conversion;

        switch (category) {
            case 1:
                conversion = getMenu(menu_length, 5, "Konwersja >> ");
                break;
            case 2:
                conversion = getMenu(menu_mass, 5, "Konwersja >> ");
                break;
            case 3:
                conversion = getMenu(menu_temperature, 4, "Konwersja >> ");
                break;
            default:
                cout << "\a";
                return;
        }

        favourites_conversions[choice - 1][0] = category;
        favourites_conversions[choice - 1][1] = conversion;
    }

    update_favorites_menu();
}

void delete_favorites() {
    int choice;

    choice = getMenu(menu_favorites, 6, "Usun >> ");

    if (choice >= 1 && choice <= 5) {
        favourites_conversions[choice - 1][0] = 0;
        favourites_conversions[choice - 1][1] = 0;
    }

    update_favorites_menu();
}

void favourites_main() {
    int menu;

    // aktualizujemy menu ulubionych
    update_favorites_menu();

    do {
        menu = getMenu(menu_favorites, 9);
        switch(menu) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                if (favourites_conversions[menu - 1][0] == 0) {
                    cout << "\a";
                    break;
                }
                switch (favourites_conversions[menu - 1][0]) {
                    case 1:
                        conversion_lenghts(favourites_conversions[menu - 1][1]);
                        break;
                    case 2:
                        conversion_masses(favourites_conversions[menu - 1][1]);
                        break;
                    case 3:
                        conversion_temperatures(favourites_conversions[menu - 1][1]);
                        break;
                    default:
                        cout << "\a";
                        break;
                }
                break;
            case 6:
                // Dodaj / Modyfikuj
                modify_favorites();
                break;
            case 7:
                // Usun
                delete_favorites();
                break;
            case 8:
                break;
            default:
                cout << "\a";
                break;
        }
    } while (menu != 8);
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

void save_favorites() {
    ofstream favourites_file("favourites.txt");

    for (int i = 0; i < 5; i++) {
        favourites_file << favourites_conversions[i][0] << " " << favourites_conversions[i][1] << endl;
    }
}

void load_favourites() {
    ifstream favourites_file("favourites.txt");

    for (int i = 0; i < 5; i++) {
        favourites_file >> favourites_conversions[i][0] >> favourites_conversions[i][1];
    }
}

int main() {
    int menu;

    load_favourites();

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
                favourites_main();
                break;
            case 4:
                break;
            default:
                cout << "\a";
                break;
        }
    } while (menu != 4);

    save_favorites();
}
