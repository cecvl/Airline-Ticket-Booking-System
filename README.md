# Airline Ticket Booking System

Welcome to the Airline Ticket Booking System, a terminal crafted for flight bookings and reservations. This system is designed to cater to both self-service and teller-assisted booking scenarios.

## Features

- **CLI Interface:** The system uses a Command Line Interface (CLI).

- **Efficient Booking Process:** The main module, `main.c`, is dedicated to handling bookings and reservations.

- **Comprehensive Record Management:**
  - `manageoneway.c`: Search and delete records in the `onewaybooking.csv` file.
  - `managetwoway.c`: Search and delete records in the `twowaybooking.csv` file.
  - `managereserve.c`: Search and delete records in the `reservations.csv` file.

## How It Works

1. **Booking and Reservations:**

   - Utilize the `main.c` module to initiate bookings or reservations effortlessly.

2. **Record Management:**
   - Manage one-way bookings with the `manageoneway.c` module, allowing for efficient searching and deletion of records in the `onewaybooking.csv` file.
   - Employ the `managetwoway.c` module to handle two-way bookings, facilitating the search and deletion of records in the `twowaybooking.csv` file.
   - For reservation records, use the `managereserve.c` module to search and delete entries in the `reservations.csv` file.

## Getting Started

To get started with the Airline Ticket Booking System, follow these steps:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/yourusername/Airline-Ticket-Booking-System.git
   ```

2. **Navigate to the Project Directory:**

   ```bash
   cd Airline-Ticket-Booking-System
   ```

3. **Compile and Run:**
   - Use an appropriate compiler to build the system, considering your operating system and preferences.
   - Execute the compiled program to launch the Airline Ticket Booking System.
