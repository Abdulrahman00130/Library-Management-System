# Library Management System

A simple and efficient command-line Library Management System implemented in C++. 
This program allows users to manage a collection of books, offering features like adding, removing, updating, borrowing, returning, and searching for books. 
Additionally, it provides library status summaries, ensuring easy management and tracking.

---

## Features

- **Add Books**: Add single or multiple books with unique IDs, titles, and authors.
- **Remove Books**: Remove a book by its ID and free up its slot.
- **Borrow/Return Books**: Mark books as borrowed or returned, with borrow count tracking.
- **Update Books**: Edit book titles and authors based on the book's ID.
- **Search Books**: Locate books by their unique ID and display their details.
- **Library Overview**: View all books or specific statistics like capacity, borrowed books, and more.
- **User-Friendly Menu**: Simple menu system for easy navigation.
- **Dynamic Memory Usage**: Supports libraries of varying sizes based on user-defined capacity.

---

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Abdulrahman00130/Library-Management-System.git
   ```
2. **Navigate to the Project Directory**:
   ```bash
   cd Library-Management-System
   ```
3. **Compile the Code**:
   Use a C++ compiler (e.g., `g++`) to compile the project:
   ```bash
   g++ -o library-system "Library System Project.cpp"
   ```
4. **Run the Program**:
   ```bash
   ./library-system
   ```

---

## Usage

1. **Start the Program**:
   Run the executable and follow the prompts to set up the library's name and capacity.
   
2. **Main Menu Options**:
   - `1`: Add a single book.
   - `2`: Add multiple books.
   - `3`: Remove a book by ID.
   - `4`: Borrow a book by ID.
   - `5`: Return a borrowed book by ID.
   - `6`: Update a book's title or author by ID.
   - `7`: Search for a book by ID.
   - `8`: Check a book's borrow status.
   - `9`: Display all books.
   - `10`: View detailed information for a specific book by ID.
   - `11`: Display library statistics.
   - `12`: Exit the program.

3. **Interactive Prompts**:
   The program will guide you through entering book details, searching, and performing operations with appropriate messages.

---

## Example Interaction

```plaintext
Enter your library name: My Library
Enter your library book capacity: 10

        My Library
===================================================
-> Enter 1 to add a book
-> Enter 2 to add more than a book
-> Enter 3 to remove a book
...
===================================================
```

---

## Dependencies

- C++ Compiler (e.g., `g++`, `clang`)

---

## Contributing

Contributions are welcome! Feel free to fork this repository and submit a pull request with your improvements.

---

## Contact

For questions or suggestions, please reach out at [am9880375@gmail.com].

