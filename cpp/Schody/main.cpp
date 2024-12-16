#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

struct Schody {
    int liczba_stopni;
    double wysokosc_stopnia;
    double glebokosc_stopnia;
};

double clamp(double value, double min_val, double max_val) {
    if (value < min_val) return min_val;
    if (value > max_val) return max_val;
    return value;
}

Schody oblicz_schody(double wysokosc_klatki, double glebokosc_klatki) {
    const double MIN_WYSOKOSC = 16.0;
    const double MAX_WYSOKOSC = 20.5;
    const double MIN_GLEBOKOSC = 22.0;
    const double MAX_GLEBOKOSC = 31.0;
    const double MIN_PARAMETR = 62.0;
    const double MAX_PARAMETR = 63.0;

    int najlepsza_liczba_stopni = 0;
    double najlepsza_wysokosc_stopnia = 0.0;
    double najlepsza_glebokosc_stopnia = 0.0;
    double minimalny_blad = std::numeric_limits<double>::max();

    for (int liczba_stopni = 5; liczba_stopni <= 50; ++liczba_stopni) {
        double wysokosc_stopnia = wysokosc_klatki / liczba_stopni;
        if (wysokosc_stopnia < MIN_WYSOKOSC || wysokosc_stopnia > MAX_WYSOKOSC) continue;

        double glebokosc_stopnia = glebokosc_klatki / liczba_stopni;
        if (glebokosc_stopnia < MIN_GLEBOKOSC || glebokosc_stopnia > MAX_GLEBOKOSC) continue;

        double parametr_schodow = 2 * wysokosc_stopnia + glebokosc_stopnia;
        if (parametr_schodow < MIN_PARAMETR || parametr_schodow > MAX_PARAMETR) continue;

        double blad = std::abs(wysokosc_klatki - (wysokosc_stopnia * liczba_stopni)) +
                      std::abs(glebokosc_klatki - (glebokosc_stopnia * liczba_stopni));

        if (blad < minimalny_blad) {
            minimalny_blad = blad;
            najlepsza_liczba_stopni = liczba_stopni;
            najlepsza_wysokosc_stopnia = wysokosc_stopnia;
            najlepsza_glebokosc_stopnia = glebokosc_stopnia;
        }
    }

    if (najlepsza_liczba_stopni == 0) { // Awaryjne dopasowanie
        najlepsza_liczba_stopni = std::round(wysokosc_klatki / 17.0);
        najlepsza_wysokosc_stopnia = wysokosc_klatki / najlepsza_liczba_stopni;
        najlepsza_glebokosc_stopnia = glebokosc_klatki / najlepsza_liczba_stopni;
    }

    return {najlepsza_liczba_stopni, najlepsza_wysokosc_stopnia, najlepsza_glebokosc_stopnia};
}

int main() {
    double wysokosc_klatki, glebokosc_klatki;

    std::cout << "Podaj wysokosc klatki schodowej (cm): ";
    std::cin >> wysokosc_klatki;
    std::cout << "Podaj glebokosc klatki schodowej (cm): ";
    std::cin >> glebokosc_klatki;

    Schody wynik = oblicz_schody(wysokosc_klatki, glebokosc_klatki);

    double parametr_schodow = 2 * wynik.wysokosc_stopnia + wynik.glebokosc_stopnia;
    bool ergonomiczne = (parametr_schodow >= 62.0 && parametr_schodow <= 63.0);

    std::cout << "\nLiczba stopni: " << wynik.liczba_stopni << "\n"
              << "Wysokosc stopnia: " << std::fixed << std::setprecision(2) << wynik.wysokosc_stopnia << " cm\n"
              << "Glebokosc stopnia: " << wynik.glebokosc_stopnia << " cm\n"
              << "(2h + s) = " << std::fixed << std::setprecision(2) << parametr_schodow << " cm\n";

    if (!ergonomiczne) {
        std::cout << "UWAGA: Te schody nie sa ergonomiczne!\n";
    }

    return 0;
}
