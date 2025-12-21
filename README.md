# Fract-ol 🌀

A fractal visualization program built with MiniLibX, featuring multithreaded rendering for smooth performance.

---

## 🚀 How to Build & Run

```bash
# Build the bonus version (recommended)
make bonus

# Run with a fractal type
./fractol_bonus mandelbrot
./fractol_bonus julia
./fractol_bonus julia -0.8 0.156    # Custom Julia parameters
./fractol_bonus burning_ship
```

---

## 🎮 Controls

| Key / Action         | Description                  |
|----------------------|------------------------------|
| `Arrow Keys`         | Pan around the fractal       |
| `Scroll Up`          | Zoom in (towards cursor)     |
| `Scroll Down`        | Zoom out                     |
| `C`                  | Cycle through color schemes  |
| `ESC`                | Exit the program             |

---

## 🔢 Supported Fractals

### 1. Mandelbrot Set
The classic fractal. Each pixel is colored based on whether the sequence $z_{n+1} = z_n^2 + c$ escapes to infinity.

### 2. Julia Set
Similar to Mandelbrot, but uses a fixed constant `c` and iterates from the pixel position as `z`. You can provide custom real and imaginary parameters.

### 3. Burning Ship
A variation where absolute values are applied: $z_{n+1} = (|Re(z_n)| + i|Im(z_n)|)^2 + c$

---

## 🎨 Color Schemes

Press `C` to cycle through **6 different color schemes**, each using different mathematical mappings of iteration count to RGB values.

---

## ⚡ Multithreading Optimization

The bonus version uses **pthread** to parallelize rendering across **8 threads**.

### How it works:
1. The image height is divided into equal horizontal strips
2. Each thread renders its assigned strip independently
3. All threads work in parallel using `pthread_create`
4. Main thread waits for completion using `pthread_join`
5. Final image is displayed with `mlx_put_image_to_window`

```
Thread 0: rows 0 - 99
Thread 1: rows 100 - 199
Thread 2: rows 200 - 299
...
Thread 7: rows 700 - 799 (remaining rows)
```

This approach provides significant speedup on multi-core systems, especially when zooming deep into complex regions of the fractals.

---

## 📁 Project Structure

```
├── includes/           # Header files
├── srcs/               # Source files (*_bonus.c for bonus version)
├── minilibx-linux/     # Graphics library
└── Makefile
```

---

## 🛠️ Dependencies

- MiniLibX (included)
- X11, Xext libraries
- pthread library
- Math library (-lm)