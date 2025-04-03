import random
from enum import Enum
from collections import deque, defaultdict


class Kierunek(Enum):
    N = "N"
    S = "S"
    E = "E"
    W = "W"


class Pojazd:
    def __init__(self, z_kierunku: Kierunek, do_kierunku: Kierunek):
        self.z_kierunku = z_kierunku
        self.do_kierunku = do_kierunku

    def __repr__(self):
        return f"{self.z_kierunku.value}->{self.do_kierunku.value}"


class Swiatla:
    def __init__(self):
        self.zielone = random.choice([[Kierunek.N, Kierunek.S], [Kierunek.W, Kierunek.E]])

    def pozwala(self, kierunek: Kierunek):
        return kierunek in self.zielone

    def __repr__(self):
        return f"Zielone: {[k.value for k in self.zielone]}"


class Skrzyzowanie:
    def __init__(self):
        self.kolejki = defaultdict(deque)

    def wykonaj_ture(self, nr_tury):
        print(f"\n--- Tura {nr_tury} ---")

        z_kierunku = random.choice(list(Kierunek))
        do_kierunku = random.choice([k for k in Kierunek if k != z_kierunku])

        pojazd = Pojazd(z_kierunku, do_kierunku)
        self.kolejki[z_kierunku].append(pojazd)
        print(f"Nowy pojazd: {pojazd}")

        swiatla = Swiatla()
        print(f"Swiatla: {swiatla}")

        for kierunek in swiatla.zielone:
            if self.kolejki[kierunek]:
                przejechal = self.kolejki[kierunek].popleft()
                print(f"Pojazd {przejechal} przejechal przez skrzyzowanie.")
                return

        print("Zaden pojazd nie mogl przejechac w tej turze.")

    def statystyki(self):
        print("\n--- Statystyki koncowe ---")
        for kierunek in Kierunek:
            dlugosc = len(self.kolejki[kierunek])
            if dlugosc > 0:
                print(f"Korek od strony {kierunek.value}: {dlugosc} pojazd(ów).")
            else:
                print(f"Brak korka od strony {kierunek.value}.")


if __name__ == "__main__":
    skrzyzowanie = Skrzyzowanie()
    for i in range(1, 6):
        skrzyzowanie.wykonaj_ture(i)
    skrzyzowanie.statystyki()