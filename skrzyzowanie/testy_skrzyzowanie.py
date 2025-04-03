import unittest
from symulacja import Kierunek, Pojazd, Skrzyzowanie

class TestSkrzyzowanie(unittest.TestCase):
    def test_n_i_s_do_e(self):
        skrzyzowanie = Skrzyzowanie()

        pojazd1 = Pojazd(Kierunek.N, Kierunek.E)
        pojazd2 = Pojazd(Kierunek.S, Kierunek.E)

        skrzyzowanie.kolejki[Kierunek.N].append(pojazd1)
        skrzyzowanie.kolejki[Kierunek.S].append(pojazd2)

        zielone = [Kierunek.N, Kierunek.S]

        przejechal = None
        for kierunek in zielone:
            if skrzyzowanie.kolejki[kierunek]:
                przejechal = skrzyzowanie.kolejki[kierunek].popleft()
                print(f"[test_n_i_s_do_e] Pojazd {przejechal} przejechał przez skrzyżowanie.")
                break

        print(f"[test_n_i_s_do_e] Kolejka N: {list(skrzyzowanie.kolejki[Kierunek.N])}")
        print(f"[test_n_i_s_do_e] Kolejka S: {list(skrzyzowanie.kolejki[Kierunek.S])}")

        self.assertEqual(przejechal, pojazd1)
        self.assertEqual(len(skrzyzowanie.kolejki[Kierunek.N]), 0)
        self.assertEqual(len(skrzyzowanie.kolejki[Kierunek.S]), 1)
        self.assertEqual(skrzyzowanie.kolejki[Kierunek.S][0], pojazd2)

    def test_w_i_e_do_n(self):
        skrzyzowanie = Skrzyzowanie()

        pojazd1 = Pojazd(Kierunek.W, Kierunek.N)
        pojazd2 = Pojazd(Kierunek.E, Kierunek.N)

        skrzyzowanie.kolejki[Kierunek.W].append(pojazd1)
        skrzyzowanie.kolejki[Kierunek.E].append(pojazd2)

        zielone = [Kierunek.W, Kierunek.E]

        przejechal = None
        for kierunek in zielone:
            if skrzyzowanie.kolejki[kierunek]:
                przejechal = skrzyzowanie.kolejki[kierunek].popleft()
                print(f"[test_w_i_e_do_n] Pojazd {przejechal} przejechał przez skrzyżowanie.")
                break

        print(f"[test_w_i_e_do_n] Kolejka W: {list(skrzyzowanie.kolejki[Kierunek.W])}")
        print(f"[test_w_i_e_do_n] Kolejka E: {list(skrzyzowanie.kolejki[Kierunek.E])}")

        self.assertEqual(przejechal, pojazd1)
        self.assertEqual(len(skrzyzowanie.kolejki[Kierunek.W]), 0)
        self.assertEqual(len(skrzyzowanie.kolejki[Kierunek.E]), 1)
        self.assertEqual(skrzyzowanie.kolejki[Kierunek.E][0], pojazd2)

if __name__ == '__main__':
    unittest.TextTestRunner(verbosity=2).run(
        unittest.TestLoader().loadTestsFromTestCase(TestSkrzyzowanie)
    )
