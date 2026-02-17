# Console Banking System (C++)

Hey!  This is my first major project using **Object-Oriented Programming (OOP)** in C++. 

I built this to practice separating logic from the UI, managing file data, and building a secure system with permissions. It’s a fully functional console application where you can manage clients, users, and transactions.

# Key Features
* **Secure Login System:** You can't just open the app; you need a username and password.
* **Role-Based Permissions:** I used **Bitwise Operators** so I can give specific admins access to *only* what they need (e.g., "Can only list clients" vs. "Full Access").
* **CRUD Operations:** Create, Read, Update, and Delete clients and users.
* **Transactions:** Deposit and Withdraw funds (with balance validation).
* **Data Persistence:** Everything is saved to `Clients.txt` and `Users.txt`, so you don't lose data when you close the app.

# Technical Stuff (Architecture)

I tried to keep the code clean by separating the **Data Layer** from the **Presentation Layer**.

* **`clsBankClient` & `clsUser`**: These handle the business logic (saving to file, validation, updating objects).
* **`clsScreen` & `clsMainMenu`**: These handle the printing to the console. The logic classes don't know about `cout` or `cin`.
* **`clsInputValidate`**: A library I wrote to stop the app from crashing if someone types a string instead of a number.

# How to Run

1.  Clone the repo:
    ```bash
    git clone https://github.com/CIS-YousefNasser/Object-Oriented-Banking-Project.git
    ```
2.  Open the project in **Visual Studio** (or any C++ IDE).
3.  Compile and Run `main.cpp`.
4.  **Login with the default Admin:**
    * **User:** `Admin`
    * **Pass:** `1234`
