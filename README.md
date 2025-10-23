# Ride-Hailing Driver Dispatch Simulator

This is a simple console application written in **C** that demonstrates the use of a **Circular Linked List** data structure.

The project simulates a core feature of ride-hailing services: fairly dispatching drivers. It maintains a list of available drivers (by name) and assigns new rides to them in a continuous loop, ensuring every driver gets a turn.

---

## Core Concept

In a ride-hailing service, it's important to distribute ride requests fairly among available drivers. A circular linked list is a perfect data structure for this.

* A list of drivers is maintained in a circle, where the last node points back to the first.
* A single pointer (`start` in this code) keeps track of the *next* driver to receive a ride.
* When a ride is requested, it's assigned to the driver at `start`.
* The `start` pointer then simply moves to the `next` driver in the list.
* Because the list loops back on itself, this process can repeat indefinitely, creating a fair cycle.

---

## Features

This program is a simple, menu-driven simulation with the following functions:

* **Add Driver:** Dynamically add a new driver (by name) to the dispatch queue.
* **Assign Ride:** Assign the next ride to the driver currently in line and move the pointer to the next driver.
* **Display Drivers:** Show the complete list of all drivers currently in the dispatch circle.
* **Remove Driver:** Remove a specific driver (by name) from the queue.

---

## Tech Stack

* **Language:** C (Standard C libraries only)
* **Core Data Structure:** Circular Linked List (implemented from scratch using `struct` and `malloc`).
* **Environment:** Console (text-based) application. No database or external libraries are used.

---

## How to Compile and Run (Using Code::Blocks)

1.  **Create a New Project:**
    * Open Code::Blocks.
    * Go to `File` -> `New` -> `Project...`.
    * Select `Console application` and click `Go`.
    * Choose `C` as the language.
    * Give your project a title (e.g., `RideHailingSystem`) and choose a location to save it. Click `Next` and then `Finish`.

2.  **Add Your Code:**
    * In the `Projects` pane on the left, expand your project. Expand `Sources`.
    * Double-click on `main.c`.
    * **Delete** the default code that Code::Blocks put there.
    * **Copy and paste** the entire code from *this project's* `main.c` file into the editor.
    * Save the file (`File` -> `Save file`).

3.  **Build and Run:**
    * Click the **Build and Run** button in the toolbar (it looks like a green play button with a yellow gear ⚙️▶️). 
    * Code::Blocks will compile your code and then open a console window where your program will run.

4.  **Use the Program:**
    * The console window will display the main menu. Interact with the program by typing numbers and pressing Enter.
