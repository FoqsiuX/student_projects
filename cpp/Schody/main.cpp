#include <iostream>
#include <iomanip>
#include "functions.cpp"
 
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