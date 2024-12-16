# Dokumentacja programu **Schody**

##Opis programu
Program **Schody** oblicza optymalną liczbę stopni, ich wysokość oraz głębokość na podstawie zadanej wysokości i głębokości klatki schodowej. Program uwzględnia światowe normy ergonomiczne, które określają:

- **Wysokość stopnia (h):** od 16 cm do 20,5 cm
- **Głębokość stopnia (s):** od 22 cm do 31 cm
- **Warunek ergonomiczny:** `62 cm < (2h + s) < 63 cm`

Jeśli wynik nie spełnia normy ergonomicznej, program informuje użytkownika, że schody nie są ergonomiczne.

---

## Funkcjonalności

### 1. Obliczanie liczby stopni
Program dzieli zadaną wysokość klatki schodowej przez średnią wartość wysokości stopnia i iteracyjnie dopasowuje wynik, aby spełniał warunki ergonomiczne.

### 2. Dostosowanie parametrów stopni
Wysokość oraz głębokość stopni są obliczane i ograniczane do zadanych zakresów:
- **Wysokość stopnia (h):** 16 - 20,5 cm
- **Głębokość stopnia (s):** 22 - 31 cm

### 3. Sprawdzanie normy ergonomicznej
Program sprawdza wzór: `62 cm < (2h + s) < 63 cm`.
- Jeśli schody nie spełniają normy, użytkownik otrzymuje ostrzeżenie: _"Te schody nie są ergonomiczne!"_

### 4. Obsługa sytuacji awaryjnych
Jeśli nie uda się znależć idealnego dopasowania, program proponuje rozwiązanie przybliżone.

---

## Przykładowe dane wejściowe i wyniki

| **Wysokość klatki (cm)** | **Głębokość klatki (cm)** | **Liczba stopni** | **Wysokość stopnia (cm)** | **Głębokość stopnia (cm)** | **2h + s** | **Ergonomiczne** |
|--------------------------|--------------------------|------------------|--------------------------|---------------------------|-----------|-----------------|
| 400			   | 535		      | 20		 | 20.00		    | 26.75			| 62.75	    | TAK	      |
| 350			   | 400		      | 18		 | 19.44		    | 22.22			| 61.10     | NIE	      |

---

## Struktura kodu

### Funkcja `oblicz_schody`
- **Parametry wejściowe:** wysokość i głębokość klatki schodowej.
- **Zwraca:** strukturę zawierającą liczbę stopni, wysokość i głębokość stopnia.

### Funkcja `main`
- Pobiera dane wejściowe od użytkownika
- Wyświetla wyniki


