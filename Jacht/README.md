# 1. Wstęp

Dokument opisuje wymagania funkcjonalne i niefunkcjonalne dla aplikacji "Jacht". Celem dokumentu jest przedstawienie założeń i potrzeb, które mają posłużyć zespołowi programistów do implementacji aplikacji webowej.

# 2. Cel systemu

Celem aplikacji jest stworzenie realistycznej, edukacyjnej symulacji zachowania żaglówki w zależności od kierunku wiatru. System ma umożliwiać użytkownikowi sterowanie kierunkiem łodzi przy pomocy klawiatury oraz obserwację jej reakcji na aktualne warunki wiatrowe.

# 3. Wymagania funkcjonalne

## 3.1. Sterowanie żaglówką

**Opis:**
- Użytkownik steruje żaglówką za pomocą strzałek lewo/prawo na klawiaturze.
- Strzałki zmieniają kurs łódki (kąt jej obrotu).
- Żaglówka porusza się automatycznie do przodu z prędkością zależną od kąta względem wiatru.

**Dane wejściowe:**
- Naciśnięcie klawiszy ArrowLeft lub ArrowRight.

**Dane wyjściowe:**
- Aktualizacja pozycji łodzi i jej obrotu.
- Zmiana wizualna pozycji żagla.
- Aktualizacja informacji tekstowych: kurs, kierunek wiatru, kierunek łódki.

# 4. Przypadki użycia

## Przypadek 1: Sterowanie łodzią

**Aktorzy:**  
Użytkownik

**Opis:**
- Użytkownik używa strzałek lewo/prawo, aby zmieniać kierunek łodzi.
- System automatycznie przelicza nowy kurs względem kierunku wiatru.
- Prędkość łódki oraz odchylenie żagla aktualizowane są automatycznie.
- Jeśli łódka zostanie skierowana bezpośrednio "pod wiatr" – zatrzymuje się.

**Dane wejściowe:**
- Naciśnięcie strzałek lewo/prawo.

**Dane wyjściowe:**
- Zaktualizowana pozycja i orientacja łódki.
- Nowy kurs opisany tekstowo (np. bajdewind, półwiatr).
- Odświeżony wygląd żagla i strzałki wiatru.

# 5. Wymagania niefunkcjonalne

- Aplikacja powinna działać płynnie w przeglądarkach desktopowych.
- Reakcja na naciśnięcie klawisza powinna być natychmiastowa.
- Losowanie kierunku wiatru przy każdym odświeżeniu strony.

# 6. Technologie i ograniczenia

- Frontend: HTML5 + JavaScript
- Silnik logiki: Własna implementacja logiki fizyki żeglarskiej (brak frameworków).
- CSS: Stylowanie przez zewnętrzny plik style.css.
- Brak backendu. Aplikacja działa w pełni po stronie klienta.

# 7. Wymagania dotyczące bezpieczeństwa

- Aplikacja nie przechowuje danych użytkownika.
- Brak potrzeby uwierzytelniania ani szyfrowania danych.
- Możliwość swobodnego korzystania bez rejestracji i logowania.

# 8. Inne uwagi

- Symulacja nie posiada punktu końcowego – umożliwia ciągłą żeglugę.
- Interfejs zawiera przyciski do komend żeglarskich, które nie są istotne funkcjonalnie i mogą być rozwinięte w przyszłości.
- Kierunek wiatru i kurs łódki są stale widoczne na interfejsie.
