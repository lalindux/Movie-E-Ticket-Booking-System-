# 🎬 Movie E-Ticket Booking System (C Language)

A lightweight CLI-based **Movie E-Ticket Booking System** built in C. This application allows users to view available movies, inspect theater seat maps, manage bookings with automated discount logic, cancel bookings with real-time refunds, search existing reservations, and generate daily revenue reports.

---

## 🚀 Features

- **Movie Directory & Showtimes**: Browse movies and view detailed schedule times.
- **Interactive Seat Map**: Real-time display of booked and available seats.
- **Seat Booking Logic**: Supports single and group bookings with automatic student, senior, and group discounts.
- **Booking Cancellation**: Instantly frees reserved seats, calculates accurate refund amounts, and updates active revenue.
- **Search System**: Find reservations instantly by seat number or customer name.
- **Revenue Reporting**: View total tickets sold and gross sales metrics.

---

## 🛠️ How to Clone & Run

### Method 1: Using Code::Blocks (Recommended)

1. **Clone the Repository**
   Open your terminal/Git Bash and clone the project:
   ```bash
   git clone [https://github.com/lalindux/Movie-E-Ticket-Booking-System.git](https://github.com/lalindux/Movie-E-Ticket-Booking-System.git) 

2. **Open the Project**
   - Launch **Code::Blocks**.
   - Go to **File ➔ Open...** (or press `Ctrl + O`).
   - Navigate to the cloned folder and select the **`.cbp`** project file.

3. **Build & Run**
   - Press **`F9`** (or click **Build and Run**) to start the application.

├── main.c              # Core menu logic and loop control
├── display.c / .h      # UI menus, movie showtimes, and seat map renders, and revenue trackers
├── calculation.c / .h  # Ticket pricing, discount calculations
└── *.cbp               # Code::Blocks project configuration file



