# Dokumentacja programu **Schody - Wizualizacja**
 
## Opis programu
Program **Schody** jest aplikacją okienkową stworzoną w Pythonie z wykorzystaniem biblioteki **Tkinter**. Umożliwia ona obliczenie i wizualizację schodów na podstawie podanej wysokości oraz głębokości klatki schodowej. Program automatycznie skaluje rysunek schodów, aby zmieściły się w oknie aplikacji, niezależnie od liczby stopni.
 
---
 
## Funkcjonalności
1. **Wprowadzanie danych wejściowych**:
   - Użytkownik podaje wysokość klatki schodowej (w cm).
   - Użytkownik podaje głębokość klatki schodowej (w cm).
 
2. **Obliczanie parametrów schodów**:
   - Liczba stopni jest wyliczana na podstawie optymalnej wysokości stopnia (16 cm - 20,5 cm).
   - Głębokość stopni jest dopasowana do podanej głębokości klatki schodowej (22 cm - 31 cm).
   - Program automatycznie dostosowuje wielkość stopni, jeśli jest ich zbyt dużo, aby zmieściły się na ekranie.
 
3. **Wizualizacja schodów**:
   - Schody są rysowane w oknie aplikacji na podstawie wyliczonych parametrów.
   - Wyniki są wyświetlane nad wizualizacją:
     - Liczba stopni,
     - Wysokość i głębokość pojedynczego stopnia.
 
4. **Dynamiczne skalowanie**:
   - Program automatycznie zmniejsza wielkość schodów, aby zmieściły się w obszarze rysowania.
 
---
 
## Wymagania
- **Python 3
- **Tkinter**
 
### Instalacja brakujących pakietów na Ubuntu:
Jeśli pojawi się błąd związany z Tkinter, trzeba zainstalować go poleceniem:
```bash
sudo apt update
sudo apt install python3-tk
```
 
---
3. Wprowadź wysokość i głębokość klatki schodowej w odpowiednich polach.
4. Kliknij przycisk **"Generuj schody"**, aby zobaczyć wizualizację schodów.
 
---
 
## Przykładowe dane wejściowe i wyniki
| **Wysokość klatki (cm)** | **Głębokość klatki (cm)** | **Liczba stopni** | **Wysokość stopnia (px)** | **Głębokość stopnia (px)** |
|--------------------------|--------------------------|------------------|--------------------------|---------------------------|
| 400                      | 535                      | 20               | 20.0                     | 26.75                     |
| 350                      | 400                      | 18               | 19.44                    | 22.22                     |
| 800                      | 1000                     | 40               | 16.0                     | 25.0                      |
 
---
 
## Struktura kodu
1. **Obliczenia schodów**:
   - Funkcja `calculate_stairs` oblicza liczbę stopni oraz ich wysokość i głębokość na podstawie podanych wymiarów klatki schodowej.
 
2. **Generowanie wizualizacji**:
   - Funkcja `draw_stairs` rysuje schody na obszarze `Canvas` z odpowiednim skalowaniem, aby były widoczne w całości.
 
3. **Interfejs użytkownika**:
   - Zbudowany z użyciem widgetów Tkinter, takich jak `Label`, `Entry`, `Button` i `Canvas`.
 
---
 
## Uwagi końcowe
- Program automatycznie skaluje wizualizację schodów, aby zawsze były widoczne w całości.
- W przypadku dużej liczby schodów, ich rozmiar jest proporcjonalnie zmniejszany.
 
---