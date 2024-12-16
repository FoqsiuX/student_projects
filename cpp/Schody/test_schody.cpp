#include <gtest/gtest.h>
#include "schody.cpp"

TEST(SchodyTest, ErgonomiczneSchody) {
    Schody wynik = oblicz_schody(400, 535);
    EXPECT_EQ(wynik.liczba_stopni, 20);
    EXPECT_NEAR(wynik.wysokosc_stopnia, 20.0, 0.1);
    EXPECT_NEAR(wynik.glebokosc_stopnia, 26.75, 0.1);
}

TEST(SchodyTest, NieergonomiczneSchody) {
    Schody wynik = oblicz_schody(350, 400);
    EXPECT_EQ(wynik.liczba_stopni, 18);
    EXPECT_NEAR(wynik.wysokosc_stopnia, 19.44, 0.1);
    EXPECT_NEAR(wynik.glebokosc_stopnia, 22.22, 0.1);
}

TEST(SchodyTest, MinimalnaWysokosc) {
    Schody wynik = oblicz_schody(320, 400);
    EXPECT_GE(wynik.wysokosc_stopnia, 16.0);
}

TEST(SchodyTest, MaksymalnaGlebokosc) {
    Schody wynik = oblicz_schody(500, 620);
    EXPECT_LE(wynik.glebokosc_stopnia, 31.0);
}

TEST(SchodyTest, WarunekErgonomiczny) {
    Schody wynik = oblicz_schody(400, 535);
    double parametr = 2 * wynik.wysokosc_stopnia + wynik.glebokosc_stopnia;
    EXPECT_GE(parametr, 62.0);
    EXPECT_LE(parametr, 63.0);
}

TEST(SchodyTest, MalaKlatkaSchodowa) {
    Schody wynik = oblicz_schody(100, 200);
    EXPECT_GT(wynik.liczba_stopni, 0);
    EXPECT_GE(wynik.wysokosc_stopnia, 16.0);
    EXPECT_LE(wynik.wysokosc_stopnia, 20.5);
}
