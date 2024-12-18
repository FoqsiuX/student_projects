import tkinter as tk
from tkinter import ttk
from math import floor
 
 
class StairsApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Schody - Wizualizacja")
        self.root.geometry("800x600")
 
        self.frame_inputs = ttk.Frame(root)
        self.frame_inputs.pack(side=tk.TOP, pady=10)
 
        ttk.Label(self.frame_inputs, text="Wysokość klatki schodowej (cm):").grid(row=0, column=0, padx=5, pady=5)
        self.entry_height = ttk.Entry(self.frame_inputs)
        self.entry_height.grid(row=0, column=1, padx=5, pady=5)
 
        ttk.Label(self.frame_inputs, text="Głębokość klatki schodowej (cm):").grid(row=1, column=0, padx=5, pady=5)
        self.entry_depth = ttk.Entry(self.frame_inputs)
        self.entry_depth.grid(row=1, column=1, padx=5, pady=5)
 
        self.btn_generate = ttk.Button(self.frame_inputs, text="Generuj schody", command=self.generate_stairs)
        self.btn_generate.grid(row=2, column=0, columnspan=2, pady=10)
 
        self.canvas = tk.Canvas(root, bg="white")
        self.canvas.pack(fill=tk.BOTH, expand=True)
 
    def calculate_stairs(self, total_height, total_depth):
        MIN_HEIGHT = 16.0
        MAX_HEIGHT = 20.5
        MIN_DEPTH = 22.0
        MAX_DEPTH = 31.0
 
        steps = floor(total_height / ((MIN_HEIGHT + MAX_HEIGHT) / 2))
        step_height = total_height / steps
        step_depth = total_depth / steps
 
        if step_height < MIN_HEIGHT:
            step_height = MIN_HEIGHT
        elif step_height > MAX_HEIGHT:
            step_height = MAX_HEIGHT
 
        if step_depth < MIN_DEPTH:
            step_depth = MIN_DEPTH
        elif step_depth > MAX_DEPTH:
            step_depth = MAX_DEPTH
 
        return steps, step_height, step_depth
 
    def generate_stairs(self):
        self.canvas.delete("all")
 
        try:
            total_height = float(self.entry_height.get())
            total_depth = float(self.entry_depth.get())
        except ValueError:
            return
 
        steps, step_height, step_depth = self.calculate_stairs(total_height, total_depth)
 
        canvas_width = self.canvas.winfo_width()
        canvas_height = self.canvas.winfo_height()
 
        scale_x = canvas_width / (steps * step_depth + 100)
        scale_y = canvas_height / (steps * step_height + 100)
        scale = min(scale_x, scale_y, 1)
 
        step_height *= scale
        step_depth *= scale
 
        start_x = 50
        start_y = canvas_height - 50
 
        self.draw_stairs(steps, step_height, step_depth, start_x, start_y)
 
    def draw_stairs(self, steps, step_height, step_depth, start_x, start_y):
        current_x = start_x
        current_y = start_y
 
        for _ in range(steps):
            self.canvas.create_rectangle(
                current_x, current_y - step_height,
                current_x + step_depth, current_y,
                fill="gray", outline="black"
            )
            current_x += step_depth
            current_y -= step_height
 
        self.canvas.create_text(
            400, 20,
            text=f"Liczba stopni: {steps}",
            font=("Arial", 12),
            fill="black"
        )
        self.canvas.create_text(
            400, 40,
            text=f"Wysokość stopnia: {step_height:.2f} px",
            font=("Arial", 12),
            fill="black"
        )
        self.canvas.create_text(
            400, 60,
            text=f"Głębokość stopnia: {step_depth:.2f} px",
            font=("Arial", 12),
            fill="black"
        )
 
 
if __name__ == "__main__":
    root = tk.Tk()
    app = StairsApp(root)
    root.mainloop()