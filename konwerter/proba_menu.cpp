#include <iostream>
#include <fstream>

using namespace std;

bool batch_mode = false;

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

string menu_time[] = {
    "[KONWERSJA CZASU]",
    "Sekundy",
    "Minuty",
    "Godziny",
    "Dni"
};

string menu_speed[] = {
    "[KONWERSJA PREDKOSCI]",
    "Metry na sekunde",
    "Mile na godzine",
    "Kilometry na godzine"
};

string menu_pressure[] = {
    "[KONWERSJA CISNIENIA]",
    "Paskale",
    "Hektopaskale",
    "Bary",
    "Atmosfery"
};

string menu_energy[] = {
    "[KONWERSJA ENERGII]",
    "Dzule",
    "Kilodzule",
    "Kalorie",
    "Watogodziny"
};

string menu_power[] = {
    "[KONWERSJA MOCY]",
    "Waty",
    "Kilowaty",
    "Konie mechaniczne",
    "BTU na godzine"
};

string menu_currency[] = {
    "[KONWERSJA WALUT]",
    "Zloty (PLN)",
    "Dolar amerykanski (USD)",
    "Euro (EUR)",
    "Funt szterling (GBP)",
    "Frank szwajcarski (CHF)"
};

string menu_main[] = {
    "[KONWERTER JEDNOSTEK]",
    "Konwertowanie",
    "Historia",
    "Ulubione",
    "Tryb wsadowy: WYL",
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
    ofstream history_file("conversion_history.txt", ios::app);
    history_file << line << endl;

    history_file.close();
}

void history_main() {
    ifstream history_file("conversion_history.txt");
    string line;

    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[HISTORIA KONWERSJI]\n\n";
    
    while (getline(history_file, line)) {
        cout << line << endl;
    }

    cout << "\n\n======================\n";
    cout << "\033[2A";
    cout << "\rEnter aby wyjsc... ";

    cin.ignore();
    cin.get();

    history_file.close();
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

void convert_time(double value, int unit, double out[4]) {
    double time_factor[4] = {1.0, 60.0, 3600.0, 86400.0};
    unit--;
    double seconds = value * time_factor[unit];

    for (int i = 0; i < 4; i++) {
        out[i] = seconds / time_factor[i];
    }
}

void display_time(double time[], string unit) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - " << unit << "]\n\n";
    cout << "Sekundy: " << time[0] << endl;
    cout << "Minuty: " << time[1] << endl;
    cout << "Godziny: " << time[2] << endl;
    cout << "Dni: " << time[3] << endl;
    cout << "\n\n======================\n";
    cout << "\033[2A";
    cout << "\rEnter aby wyjsc... ";

    save_history("[KONWERSJA - " + unit + "] Sekundy: " + to_string(time[0]) + "; Minuty: " + to_string(time[1]) + "; Godziny: " + to_string(time[2]) + "; Dni: " + to_string(time[3]));
    cin.ignore();
    cin.get();
}

void convert_speed(double value, int unit, double out[3]) {
    double speed_factor[3] = {3.6, 1.609344, 1};
    unit--;
    double kph = value * speed_factor[unit];

    for (int i = 0; i < 3; i++) {
        out[i] = kph / speed_factor[i];
    }
}

void display_speed(double speed[], string unit) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - " << unit << "]\n\n";
    cout << "Metry na sekunde: " << speed[0] << endl;
    cout << "Mile na godzine: " << speed[1] << endl;
    cout << "Kilometry na godzine: " << speed[2] << endl;
    cout << "\n\n======================\n";
    cout << "\033[2A";
    cout << "\rEnter aby wyjsc... ";

    save_history("[KONWERSJA - " + unit + "] Metry na sekunde: " + to_string(speed[0]) + "; Mile na godzine: " + to_string(speed[1]) + "; Kilometry na godzine: " + to_string(speed[2]));
    cin.ignore();
    cin.get();
}

void convert_pressure(double value, int unit, double out[4]) {
    double pressure_factor[4] = {1.0, 100.0, 100000.0, 101325.0};
    unit--;
    double pascals = value * pressure_factor[unit];

    for (int i = 0; i < 4; i++) {
        out[i] = pascals / pressure_factor[i];
    }
}

void display_pressure(double pressure[], string unit) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - " << unit << "]\n\n";
    cout << "Paskale: " << pressure[0] << endl;
    cout << "Hektopaskale: " << pressure[1] << endl;
    cout << "Bary: " << pressure[2] << endl;
    cout << "Atmosfery: " << pressure[3] << endl;
    cout << "\n\n======================\n";
    cout << "\033[2A";
    cout << "\rEnter aby wyjsc... ";

    save_history("[KONWERSJA - " + unit + "] Paskale: " + to_string(pressure[0]) + "; Hektopaskale: " + to_string(pressure[1]) + "; Bary: " + to_string(pressure[2]) + "; Atmosfery: " + to_string(pressure[3]));
    cin.ignore();
    cin.get();
}

void convert_energy(double value, int unit, double out[4]) {
    double energy_factor[4] = {1.0, 1000.0, 4184.0, 3600.0};
    unit--;
    double joules = value * energy_factor[unit];

    for (int i = 0; i < 4; i++) {
        out[i] = joules / energy_factor[i];
    }
}

void display_energies(double energies[], string unit) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - " << unit << "]\n\n";
    cout << "Dzule: " << energies[0] << endl;
    cout << "Kilodzule: " << energies[1] << endl;
    cout << "Kilokalorie: " << energies[2] << endl;
    cout << "Watogodziny: " << energies[3] << endl;
    cout << "\n\n======================\n";
    cout << "\033[2A";
    cout << "\rEnter aby wyjsc... ";

    save_history("[KONWERSJA - " + unit + "] Dzule: " + to_string(energies[0]) + "; Kilodzule: " + to_string(energies[1]) + "; Kalorie: " + to_string(energies[2]) + "; Watogodziny: " + to_string(energies[3]));
    cin.ignore();
    cin.get();
}

void convert_power(double value, int unit, double out[4]) {
    double power_factor[4] = {1.0, 1000.0, 745.7, 0.293};
    unit--;
    double watts = value * power_factor[unit];

    for (int i = 0; i < 4; i++) {
        out[i] = watts / power_factor[i];
    }
}

void display_powers(double powers[], string unit) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - " << unit << "]\n\n";
    cout << "Waty: " << powers[0] << endl;
    cout << "Kilowaty: " << powers[1] << endl;
    cout << "Konie mechaniczne: " << powers[2] << endl;
    cout << "BTU na godzine: " << powers[3] << endl;
    cout << "\n\n======================\n";
    cout << "\033[2A";
    cout << "\rEnter aby wyjsc... ";

    save_history("[KONWERSJA - " + unit + "] Waty: " + to_string(powers[0]) + "; Kilowaty: " + to_string(powers[1]) + "; Konie mechaniczne: " + to_string(powers[2]) + "; BTU na godzine: " + to_string(powers[3]));
    cin.ignore();
    cin.get();
}

void convert_currency(double value, int unit, double out[5]) {
    // Przeliczniki na podstawie przykładowych wartosci (stan na 2026-01-04)
    double currency_factor[5] = {1.0, 3.59, 4.21, 4.84, 4.53}; // PLN, USD, EUR, GBP, CHF
    unit--;
    double pln = value * currency_factor[unit];

    for (int i = 0; i < 5; i++) {
        out[i] = pln / currency_factor[i];
    }
}

void display_currencies(double currencies[], string unit) {
    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[KONWERSJA - " << unit << "]\n\n";
    cout << "Zloty (PLN): " << currencies[0] << endl;
    cout << "Dolar amerykanski (USD): " << currencies[1] << endl;
    cout << "Euro (EUR): " << currencies[2] << endl;
    cout << "Funt szterling (GBP): " << currencies[3] << endl;
    cout << "Frank szwajcarski (CHF): " << currencies[4] << endl;
    cout << "\n\n======================\n";
    cout << "\033[2A";
    cout << "\rEnter aby wyjsc... ";

    save_history("[KONWERSJA - " + unit + "] PLN: " + to_string(currencies[0]) + "; USD: " + to_string(currencies[1]) + "; EUR: " + to_string(currencies[2]) + "; GBP: " + to_string(currencies[3]) + "; CHF: " + to_string(currencies[4]));
    cin.ignore();
    cin.get();
}

int get_menu(string menu[], int max_pos, string prompt = ">> ") {
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

double get_value(string unit) {
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

string get_filename() {
    string filename;

    cout << "\033[2J\033[H";

    cout << "======================\n";
    cout << "[NAZWA PLIKU]\n\n";
    cout << "======================";

    cout << "\033[1A";
    cout << "\rPodaj nazwe pliku >> ";

    cin >> filename;

    return filename;
}

void conversion_lenghts(int choice = -1) {
    string filename;
    double value;
    double lengths[4];

    if (choice == -1) {
        choice = get_menu(menu_length, 5);
    }

    if (!batch_mode) {
        value = get_value(menu_length[choice]);

        convert_length(value, choice, lengths);
        display_lengths(lengths, menu_length[choice]);
    }
    else {
        filename = get_filename();

        ifstream batch_file_input(filename);
        ofstream batch_file_output("out_" + filename);

        string line;
        
        while (getline(batch_file_input, line)) {
            value = stod(line);

            convert_length(value, choice, lengths);
            batch_file_output << lengths[0] << ";" << lengths[1] << ";" << lengths[2] << ";" << lengths[3] << endl;
            save_history("[KONWERSJA WSADOWA - " + menu_length[choice] + "] Metry: " + to_string(lengths[0]) + "; Cale: " + to_string(lengths[1]) + "; Mile: " + to_string(lengths[2]) + "; Kilometry: " + to_string(lengths[3]));
        }

        batch_file_input.close();
        batch_file_output.close();
    }
}

void conversion_masses(int choice = -1) {
    double value;
    double masses[4];

    if (choice == -1) {
        choice = get_menu(menu_mass, 5);
    }

    if (!batch_mode) {
        value = get_value(menu_mass[choice]);

        convert_mass(value, choice, masses);
        display_masses(masses, menu_mass[choice]);
    }
    else {
        string filename = get_filename();

        ifstream batch_file_input(filename);
        ofstream batch_file_output("out_" + filename);

        string line;

        while (getline(batch_file_input, line)) {
            value = stod(line);

            convert_mass(value, choice, masses);
            batch_file_output << masses[0] << ";" << masses[1] << ";" << masses[2] << ";" << masses[3] << endl;
            save_history("[KONWERSJA WSADOWA - " + menu_mass[choice] + "] Gramy: " + to_string(masses[0]) + "; Uncje: " + to_string(masses[1]) + "; Funty: " + to_string(masses[2]) + "; Kilogramy: " + to_string(masses[3]));
        }

        batch_file_input.close();
        batch_file_output.close();
    }
}

void conversion_temperatures(int choice = -1) {
    double value;
    double temperatures[3];

    if (choice == -1) {
        choice = get_menu(menu_temperature, 4);
    }

    if (!batch_mode) {
        value = get_value(menu_temperature[choice]);

        convert_temperature(value, choice, temperatures);
        display_temperatures(temperatures, menu_temperature[choice]);
    }
    else {
        string filename = get_filename();

        ifstream batch_file_input(filename);
        ofstream batch_file_output("out_" + filename);

        string line;

        while (getline(batch_file_input, line)) {
            value = stod(line);

            convert_temperature(value, choice, temperatures);
            batch_file_output << temperatures[0] << ";" << temperatures[1] << ";" << temperatures[2] << endl;
            save_history("[KONWERSJA WSADOWA - " + menu_temperature[choice] + "] Celsjusz: " + to_string(temperatures[0]) + "; Farenheit: " + to_string(temperatures[1]) + "; Kelvin: " + to_string(temperatures[2]));
        }

        batch_file_input.close();
        batch_file_output.close();
    }
}

void conversion_time(int choice = -1) {
    double value;
    double time[4];

    if (choice == -1) {
        choice = get_menu(menu_time, 5);
    }

    if (!batch_mode) {
        value = get_value(menu_time[choice]);

        convert_time(value, choice, time);
        display_time(time, menu_time[choice]);
    }
    else {
        string filename = get_filename();

        ifstream batch_file_input(filename);
        ofstream batch_file_output("out_" + filename);

        string line;

        while (getline(batch_file_input, line)) {
            value = stod(line);

            convert_time(value, choice, time);
            batch_file_output << time[0] << ";" << time[1] << ";" << time[2] << ";" << time[3] << endl;
            save_history("[KONWERSJA WSADOWA - " + menu_time[choice] + "] Sekundy: " + to_string(time[0]) + "; Minuty: " + to_string(time[1]) + "; Godziny: " + to_string(time[2]) + "; Dni: " + to_string(time[3]));
        }

        batch_file_input.close();
        batch_file_output.close();
    }
}

void conversion_speed(int choice = -1) {
    double value;
    double speed[3];

    if (choice == -1) {
        choice = get_menu(menu_speed, 4);
    }

    if (!batch_mode) {
        value = get_value(menu_speed[choice]);

        convert_speed(value, choice, speed);
        display_speed(speed, menu_speed[choice]);
    }
    else {
        string filename = get_filename();

        ifstream batch_file_input(filename);
        ofstream batch_file_output("out_" + filename);

        string line;

        while (getline(batch_file_input, line)) {
            value = stod(line);

            convert_speed(value, choice, speed);
            batch_file_output << speed[0] << ";" << speed[1] << ";" << speed[2] << endl;
            save_history("[KONWERSJA WSADOWA - " + menu_speed[choice] + "] Metry na sekunde: " + to_string(speed[0]) + "; Mile na godzine: " + to_string(speed[1]) + "; Kilometry na godzine: " + to_string(speed[2]));
        }

        batch_file_input.close();
        batch_file_output.close();
    }
}

void conversion_pressure(int choice = -1) {
    double value;
    double pressure[4];

    if (choice == -1) {
        choice = get_menu(menu_pressure, 5);
    }

    if (!batch_mode) {
        value = get_value(menu_pressure[choice]);

        convert_pressure(value, choice, pressure);
        display_pressure(pressure, menu_pressure[choice]);
    }
    else {
        string filename = get_filename();

        ifstream batch_file_input(filename);
        ofstream batch_file_output("out_" + filename);

        string line;

        while (getline(batch_file_input, line)) {
            value = stod(line);

            convert_pressure(value, choice, pressure);
            batch_file_output << pressure[0] << ";" << pressure[1] << ";" << pressure[2] << ";" << pressure[3] << endl;
            save_history("[KONWERSJA WSADOWA - " + menu_pressure[choice] + "] Paskale: " + to_string(pressure[0]) + "; Hektopaskale: " + to_string(pressure[1]) + "; Bary: " + to_string(pressure[2]) + "; Atmosfery: " + to_string(pressure[3]));
        }

        batch_file_input.close();
        batch_file_output.close();
    }
}

void conversion_energies(int choice = -1) {
    double value;
    double energies[4];

    if (choice == -1) {
        choice = get_menu(menu_energy, 5);
    }

    if (!batch_mode) {
        value = get_value(menu_energy[choice]);

        convert_energy(value, choice, energies);
        display_energies(energies, menu_energy[choice]);
    }
    else {
        string filename = get_filename();

        ifstream batch_file_input(filename);
        ofstream batch_file_output("out_" + filename);

        string line;

        while (getline(batch_file_input, line)) {
            value = stod(line);

            convert_energy(value, choice, energies);
            batch_file_output << energies[0] << ";" << energies[1] << ";" << energies[2] << ";" << energies[3] << endl;
            save_history("[KONWERSJA WSADOWA - " + menu_energy[choice] + "] Dzule: " + to_string(energies[0]) + "; Kilodzule: " + to_string(energies[1]) + "; Kalorie: " + to_string(energies[2]) + "; Watogodziny: " + to_string(energies[3]));
        }

        batch_file_input.close();
        batch_file_output.close();
    }
}

void conversion_powers(int choice = -1) {
    double value;
    double powers[4];

    if (choice == -1) {
        choice = get_menu(menu_power, 5);
    }

    if (!batch_mode) {
        value = get_value(menu_power[choice]);

        convert_power(value, choice, powers);
        display_powers(powers, menu_power[choice]);
    }
    else {
        string filename = get_filename();

        ifstream batch_file_input(filename);
        ofstream batch_file_output("out_" + filename);

        string line;

        while (getline(batch_file_input, line)) {
            value = stod(line);

            convert_power(value, choice, powers);
            batch_file_output << powers[0] << ";" << powers[1] << ";" << powers[2] << ";" << powers[3] << endl;
            save_history("[KONWERSJA WSADOWA - " + menu_power[choice] + "] Waty: " + to_string(powers[0]) + "; Kilowaty: " + to_string(powers[1]) + "; Konie mechaniczne: " + to_string(powers[2]) + "; BTU na godzine: " + to_string(powers[3]));
        }

        batch_file_input.close();
        batch_file_output.close();
    }
}

void conversion_currencies(int choice = -1) {
    double value;
    double currencies[5];

    if (choice == -1) {
        choice = get_menu(menu_currency, 6);
    }

    if (!batch_mode) {
    value = get_value(menu_currency[choice]);

        convert_currency(value, choice, currencies);
        display_currencies(currencies, menu_currency[choice]);
    }
    else {
        string filename = get_filename();

        ifstream batch_file_input(filename);
        ofstream batch_file_output("out_" + filename);

        string line;

        while (getline(batch_file_input, line)) {
            value = stod(line);

            convert_currency(value, choice, currencies);
            batch_file_output << currencies[0] << ";" << currencies[1] << ";" << currencies[2] << ";" << currencies[3] << ";" << currencies[4] << endl;
            save_history("[KONWERSJA WSADOWA - " + menu_currency[choice] + "] Zlotowki: " + to_string(currencies[0]) + "; Dolar: " + to_string(currencies[1]) + "; Euro: " + to_string(currencies[2]) + "; Frank szwajcarski: " + to_string(currencies[3]) + "; Funty brytyjskie: " + to_string(currencies[4]));
        }

        batch_file_input.close();
        batch_file_output.close();
    }
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
            case 4:
                menu_favorites[i + 1] = menu_time[favourites_conversions[i][1]];
                break;
            case 5:
                menu_favorites[i + 1] = menu_speed[favourites_conversions[i][1]];
                break;
            case 6:
                menu_favorites[i + 1] = menu_pressure[favourites_conversions[i][1]];
                break;
            case 7:
                menu_favorites[i + 1] = menu_energy[favourites_conversions[i][1]];
                break;
            case 8:
                menu_favorites[i + 1] = menu_power[favourites_conversions[i][1]];
                break;
            case 9:
                menu_favorites[i + 1] = menu_currency[favourites_conversions[i][1]];
                break;
            default:
                menu_favorites[i + 1] = "Puste";
                break;
        }
    }
}

void modify_favorites() {
    int choice;

    choice = get_menu(menu_favorites, 6, "Modyfikuj >> ");

    if (choice >= 1 && choice <= 5) {
        int category = get_menu(menu_conversion, 10, "Kategoria >> ");
        int conversion;

        switch (category) {
            case 1:
                conversion = get_menu(menu_length, 5, "Konwersja >> ");
                break;
            case 2:
                conversion = get_menu(menu_mass, 5, "Konwersja >> ");
                break;
            case 3:
                conversion = get_menu(menu_temperature, 4, "Konwersja >> ");
                break;
            case 4:
                conversion = get_menu(menu_time, 5, "Konwersja >> ");
                break;
            case 5:
                conversion = get_menu(menu_speed, 4, "Konwersja >> ");
                break;
            case 6:
                conversion = get_menu(menu_pressure, 5, "Konwersja >> ");
                break;
            case 7:
                conversion = get_menu(menu_energy, 5, "Konwersja >> ");
                break;
            case 8:
                conversion = get_menu(menu_power, 5, "Konwersja >> ");
                break;
            case 9:
                conversion = get_menu(menu_currency, 6, "Konwersja >> ");
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

    choice = get_menu(menu_favorites, 6, "Usun >> ");

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
        menu = get_menu(menu_favorites, 9);
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
                    case 4:
                        conversion_time(favourites_conversions[menu - 1][1]);
                        break;
                    case 5:
                        conversion_speed(favourites_conversions[menu - 1][1]);
                        break;
                    case 6:
                        conversion_pressure(favourites_conversions[menu - 1][1]);
                        break;
                    case 7:
                        conversion_energies(favourites_conversions[menu - 1][1]);
                        break;
                    case 8:
                        conversion_powers(favourites_conversions[menu - 1][1]);
                        break;
                    case 9:
                        conversion_currencies(favourites_conversions[menu - 1][1]);
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
        menu = get_menu(menu_conversion, 11);
        switch(menu) {
            case 1:
                conversion_lenghts();
                break;
            case 2:
                conversion_masses();
                break;
            case 3:
                conversion_temperatures();
                break;
            case 4:
                conversion_time();
                break;
            case 5:
                conversion_speed();
                break;
            case 6:
                conversion_pressure();
                break;
            case 7:
                conversion_energies();
                break;
            case 8:
                conversion_powers();
                break;
            case 9:
                conversion_currencies();
                break;
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

    favourites_file.close();
}

void load_favourites() {
    ifstream favourites_file("favourites.txt");

    for (int i = 0; i < 5; i++) {
        favourites_file >> favourites_conversions[i][0] >> favourites_conversions[i][1];
    }

    favourites_file.close();
}

int main() {
    int menu;

    load_favourites();

    do {
        menu = get_menu(menu_main, 6);
        switch(menu) {
            case 1:
                conversion_main();
                break;
            case 2:
                history_main();
                break;
            case 3:
                favourites_main();
                break;
            case 4:
                //if (batch_mode) menu_main[4] = "Tryb wsadowy: WYL"; else menu_main[4] = "Tryb wsadowy: WL";
                menu_main[4] = (batch_mode) ? "Tryb wsadowy: WYL" : "Tryb wsadowy: WL";
                batch_mode = !batch_mode;
                break;
            case 5:
                break;
            default:
                cout << "\a";
                break;
        }
    } while (menu != 5);

    save_favorites();
}
