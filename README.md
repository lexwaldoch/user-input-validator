# User Input Validation Library

A C application that validates usernames, email addresses, and passwords according to a set of predefined formatting rules. This project demonstrates low-level string parsing, character validation, and modular software design in C without relying on regular expressions or external libraries.

---

## Features

- Username validation
  - Must begin with a letter
  - Maximum length of 32 characters
  - Letters, numbers, and underscores only

- Email validation
  - Verifies username, domain, and top-level domain
  - Supports `.com`, `.edu`, and `.net`
  - Detects invalid formatting and missing components

- Password validation
  - Requires 8–16 characters
  - Requires at least one uppercase letter
  - Requires at least one lowercase letter
  - Rejects passwords containing spaces

- Password confirmation
  - Confirms matching password entries

---

## Technologies

- C
- Standard C Library
- Character-by-character string parsing
- Modular programming using header and source files

---

## Project Structure

```
user-input-validator/
├── README.md
├── src/
│   ├── functions.c
│   ├── functions.h
│   └── main.c
├── tests/
└── LICENSE
```

---

## Building

Compile using GCC:

```bash
gcc src/main.c src/functions.c -o validator
```

Run the program:

```bash
./validator
```

---

## Example

```
Username: Lex123
✓ Username valid

Email: lex123@example.com
✓ Email valid

Password: SecurePass1
✓ Password valid

Confirm Password: SecurePass1
✓ Passwords match
```

---

## Skills Demonstrated

- String manipulation in C
- ASCII character validation
- Modular program design
- Input validation
- Error handling
- Function decomposition
- Working with header files and multiple source files

---

## Future Improvements

- Replace manual ASCII comparisons with `<ctype.h>` functions
- Support additional valid email formats
- Reduce repetitive validation logic with helper functions
- Add automated unit tests
- Improve code readability through refactoring

---

## About

This project was originally developed as part of a university systems programming course and has been cleaned up and documented as a portfolio project.
