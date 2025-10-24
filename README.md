# Terminal Shortcut Maker (TSM)

**Author:** [Ramazan Kamilov] | **Language:** C++ | **Platform:** Windows

---

## 💻 Project Overview

The Terminal Shortcut Maker (TSM) is a compact **Command Line Utility** engineered in **C++** to streamline and automate user workflow on Windows systems.

This utility allows users to save, manage, and execute frequently used web links or commands directly from a simple command-line menu by entering a corresponding number. This demonstrates proficiency in system utility development, command-line interface design, **File I/O**, and **Automated Execution**.

## 🛠️ Technical Details & Functionality

This project is built around **File I/O** (Input/Output) to handle configuration and **Automated Execution** to interact with the operating system.

### Key Features

* **Persisted Configuration:** The application utilizes two local text files (`names.txt` and `links.txt`) to maintain a persistent, mapped configuration of all saved shortcuts.
* **Menu-Driven Interface:** Provides a clear, interactive CLI menu for all operations.
* **Shortcut Management:** Users can perform all necessary CRUD (Create, Read, Update, Delete) operations on their shortcuts.
* **Automated Execution:** The core feature allows the user to input a shortcut number, and the program automatically retrieves the associated URL and executes the standard OS command (`start chrome` or similar) to launch the link.

## 🚀 Getting Started

### Requirements

* A Windows machine (The application relies on Windows-specific execution commands).
* A C++ compiler (e.g., g++).

### Installation and Run

1.  Clone this repository to your local machine.
2.  Compile the source file `tsm.cpp` using your preferred C++ compiler:

    ```bash
    g++ tsm.cpp -o tsm.exe
    ```

3.  Run the executable from your terminal:

    ```bash
    ./tsm.exe
    ```

4.  The application will automatically create the necessary configuration files if they do not already exist. Follow the on-screen menu instructions.
