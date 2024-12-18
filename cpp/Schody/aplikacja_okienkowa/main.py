import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QGraphicsScene, QGraphicsView, QGraphicsRectItem, QVBoxLayout, QLabel, QLineEdit, QPushButton, QWidget
from PyQt5.QtGui import QBrush
from PyQt5.QtCore import Qt
 
 
class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Schody - Wizualizacja")
 
        self.init_ui()
 
    def init_ui(self):
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        layout = QVBoxLayout(central_widget)
 
        self.height_label = QLabel("Wysokość klatki schodowej (cm):")
        self.height_input = QLineEdit()
        self.depth_label = QLabel("Głębokość klatki schodowej (cm):")
        self.depth_input = QLineEdit()
        self.generate_button = QPushButton("Generuj schody")
        self.generate_button.clicked.connect(self.generate_stairs)
 
        self.scene = QGraphicsScene(self)
        self.view = QGraphicsView(self.scene)
 
        layout.addWidget(self.height_label)
        layout.addWidget(self.height_input)
        layout.addWidget(self.depth_label)
        layout.addWidget(self.depth_input)
        layout.addWidget(self.generate_button)
        layout.addWidget(self.view)
 
    def generate_stairs(self):
        height = float(self.height_input.text())
        depth = float(self.depth_input.text())
 
        wynik = self.oblicz_schody(height, depth)
 
        self.scene.clear()
        self.draw_stairs(wynik['steps'], wynik['step_height'], wynik['step_depth'])
 
    def oblicz_schody(self, wysokosc_klatki, glebokosc_klatki):
        MIN_WYSOKOSC = 16.0
        MAX_WYSOKOSC = 20.5
        MIN_GLEBOKOSC = 22.0
        MAX_GLEBOKOSC = 31.0
 
        najlepsza_liczba_stopni = 0
        najlepsza_wysokosc_stopnia = 0.0
        najlepsza_glebokosc_stopnia = 0.0
        minimalny_blad = float('inf')
 
        for liczba_stopni in range(5, 51):
            wysokosc_stopnia = wysokosc_klatki / liczba_stopni
            if not (MIN_WYSOKOSC <= wysokosc_stopnia <= MAX_WYSOKOSC):
                continue
 
            glebokosc_stopnia = glebokosc_klatki / liczba_stopni
            if not (MIN_GLEBOKOSC <= glebokosc_stopnia <= MAX_GLEBOKOSC):
                continue
 
            blad = abs(wysokosc_klatki - liczba_stopni * wysokosc_stopnia) + abs(glebokosc_klatki - liczba_stopni * glebokosc_stopnia)
 
            if blad < minimalny_blad:
                minimalny_blad = blad
                najlepsza_liczba_stopni = liczba_stopni
                najlepsza_wysokosc_stopnia = wysokosc_stopnia
                najlepsza_glebokosc_stopnia = glebokosc_stopnia
 
        return {
            'steps': najlepsza_liczba_stopni,
            'step_height': najlepsza_wysokosc_stopnia,
            'step_depth': najlepsza_glebokosc_stopnia
        }
 
    def draw_stairs(self, steps, step_height, step_depth):
        current_x = 0
        current_y = 0
 
        for _ in range(steps):
            rect = QGraphicsRectItem(current_x, -current_y, step_depth, step_height)
            rect.setBrush(QBrush(Qt.gray))
            self.scene.addItem(rect)
            current_x += step_depth
            current_y += step_height
 
 
if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())