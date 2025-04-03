import unittest
from collections import deque, defaultdict
from symulacja import Kierunek, Pojazd, Skrzyzowanie


class TestSkrzyzowanie(unittest.TestCase):
    def test_pojazd_przejezdza_na_zielonym(self):
        skrzyzowanie = Skrzyzowanie()

        pojazd = Pojazd(Kierunek.N, Kierunek.S)
        skrzyzowanie.kolejki[Kierunek.N].append(pojazd)

        class TestSwiatla:
            zielone = [Kierunek.N, Kierunek.S]

        zielone_swiatla = TestSwiatla()
        
        for kierunek in zielone_swiatla.zielone:
            if skrzyzowanie.kolejki[kierunek]:
                przejechal = skrzyzowanie.kolejki[kierunek].popleft()
                break

        self.assertEqual(len(skrzyzowanie.kolejki[Kierunek.N]), 0)
        self.assertEqual(przejechal, pojazd)


if __name__ == '__main__':
    unittest.main()
