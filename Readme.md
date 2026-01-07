# Bank Management System (C)

A console-based bank management system written in C that simulates basic banking operations such as account management, transactions, and administrative control using file handling.

## Features
- Admin and User authentication
- Account creation and deletion
- Deposit, withdrawal, and fund transfer
- Mini statement tracking
- ATM simulation
- Loan application system
- Currency exchange calculator
- Persistent storage using binary files

## Tech Stack
- Language: C
- Concepts:
  - Structures
  - File Handling (Binary Files)
  - Functions
  - Conditional Logic
  - Arrays

## How to Run
1. Compile the program:
   gcc bank.c -o bank

2. Run:
   ./bank

## Data Storage
- User data is stored in a binary file (`users.dat`)
- Data persists across program executions

## Limitations
- Passwords are stored in plain text (for learning purposes)
- Uses `conio.h`, so the program is Windows-specific
- No encryption or hashing implemented

## What I Learned
- Designing structured programs in C
- Implementing file-based persistence
- Handling user roles and permissions
- Managing state in a console application
