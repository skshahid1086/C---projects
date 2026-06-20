# Banking Management System in C

A simple console-based Banking Management System built using the C programming language. This project demonstrates the use of structures, functions, arrays, file handling, and menu-driven programming.

The application allows users to create bank accounts, deposit money, withdraw money, and store account information permanently using binary file storage.

---

## Features

### Account Creation

* Generates a unique account number automatically.
* Stores account holder name.
* Accepts an opening balance.
* Prevents invalid opening balances.

### Deposit Money

* Deposit funds into an existing account.
* Updates account balance immediately.
* Saves updated information to disk.

### Withdraw Money

* Withdraw funds from an existing account.
* Prevents withdrawals exceeding available balance.
* Prevents invalid withdrawal amounts.
* Saves updated information to disk.

### View All Accounts (Admin Only)

* Protected by an admin password.
* Displays all customer accounts and balances.

### Persistent Storage

* Uses binary file handling.
* Account data remains available even after the program is closed.
* Automatically loads saved accounts on startup.

---

## Concepts Used

This project demonstrates the following C programming concepts:

* Structures (`struct`)
* Arrays of Structures
* Functions
* Loops
* Conditional Statements
* File Handling (`fopen`, `fwrite`, `fread`, `fclose`)
* Random Number Generation
* Menu Driven Programming
* Data Persistence

---

## Project Structure

```text
Banking-System/
│
├── bank.c
├── accounts.dat
└── README.md
```

### File Description

| File         | Purpose                                |
| ------------ | -------------------------------------- |
| bank.c       | Source code                            |
| accounts.dat | Stores account information permanently |
| README.md    | Project documentation                  |

---

## Account Structure

```c
typedef struct bank
{
    int acc;
    char name[50];
    float balance;
} Bank;
```

Each account contains:

* Account Number
* Account Holder Name
* Account Balance

---

## How Account Numbers Are Generated

The program generates a random 5-digit number and combines it with a fixed bank prefix:

```c
1100xxxxx
```

Example:

```text
110034567
110078912
110045621
```

The system checks existing accounts to avoid duplicate account numbers.

---

## File Handling

### Saving Accounts

Whenever an account is created, deposited into, or withdrawn from, the application saves all account information to:

```text
accounts.dat
```

using:

```c
fwrite()
```

### Loading Accounts

When the program starts, it loads existing account data from:

```text
accounts.dat
```

using:

```c
fread()
```

This ensures that account information persists between program executions.

---

## Menu

```text
1. Create Account
2. Deposit Money
3. Withdraw Money
4. List All Accounts
0. Exit
```

---

## Sample Run

```text
1. Create Account
2. Deposit Money
3. Withdraw Money
4. List All Accounts
0. Exit

Choose operation: 1

Enter Account Holder Name: Sahid
Enter opening balance: 5000

Account created successfully!

Account Number: 110045678
Name: Sahid
Balance: 5000.00
```

---

## Admin Access

The account listing feature is restricted to bank staff.

Default admin password:

```text
1234
```

To view all accounts:

1. Select option 4
2. Enter admin password
3. View stored account information

---

## Compilation

### GCC

```bash
gcc main.c -o bank
```

### Run

Linux / macOS:

```bash
./bank
```

Windows:

```bash
bank.exe
```

---

## Current Limitations

* Maximum of 500 accounts.
* Password is hardcoded.
* No account deletion.
* No account search functionality.
* No transaction history.
* No account editing feature.
* Data is stored locally only.

---

## Future Improvements

Planned enhancements:

* Search Account by Account Number
* Delete Account
* Edit Account Information
* Change Admin Password
* Transaction History
* Mini Statement Generation
* Interest Calculation
* CSV Export
* Multiple Branch Support
* Login System for Customers
* Database Integration (MySQL/PostgreSQL)

---

## Learning Outcomes

This project helped in understanding:

* Data structures in C
* Modular programming using functions
* Binary file handling
* Data persistence
* Input validation
* Menu-driven application design
* Real-world CRUD operations

---

## Author

Shahid

A beginner-friendly banking management system built in C to practice core programming concepts and file handling.

