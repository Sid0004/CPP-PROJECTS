**Siddhant's Banking System**

Siddhant's Banking System is a console-based banking system built in C++ that allows administrators and users to manage accounts. It supports functionalities such as creating accounts, depositing and withdrawing money, changing PINs, balance inquiries, and more. The system supports both single and joint account holders, with different account types like Savings and Current accounts.

**Features**

Administrator Menu:
View total number of accounts.
View details of all accounts.
User Menu:
Create a new account (single or joint holder, savings or current).
Change the account PIN.
Deposit money into the account.
Withdraw money from the account.
Balance inquiry.
Close the account.
Display account details.
Prerequisites
C++ compiler (e.g., g++ for Linux or MinGW for Windows).
Basic understanding of C++ programming.
Installation
Clone or download the repository.
Open the terminal (or command prompt) in the project directory.
Compile the code using your C++ compiler. For example, with g++:
bash
Copy code
g++ main.cpp -o banking_system
Run the executable:
bash
Copy code
./banking_system  # On Linux/MacOS
banking_system.exe  # On Windows
Usage
Welcome Screen:

Upon launching, you will be presented with the option to choose between an Administrator or User interface.
Administrator Menu:

As an administrator, you can view the total number of accounts or view account details.
User Menu:

As a user, you can perform various banking operations like creating an account, depositing/withdrawing money, and checking your balance.
Example User Interaction



|-----------------------------------------------|
|                                               |
|     WELCOME TO siddhant BANKING SYSTEM        |
|                                               |
|-----------------------------------------------|
|     Choose your option:                       |
|-----------------------------------------------|
|                                               |
|     1) ADMINISTRATOR                          |
|     2) USER                                   |
|     3) EXIT                                   |
|-----------------------------------------------|


///////////////////////////////////////////////////////////////////


|-----------------------------------------------|
|   Choose your option:                         |
|-----------------------------------------------|
|                                               |
|     1) View Total Number of Accounts          |
|     2) View Account Details                   |
|-----------------------------------------------|


////////////////////////////////////////////////////////////////

|-----------------------------------------------|
|   Choose your option:                         |
|-----------------------------------------------|
|                                               |
|     1) Create a New Account                   |
|     2) Change your pin                        |
|     3) Deposit Money                          |
|     4) Withdraw Money                         |
|     5) Balance Inquiry                        |
|     6) Close Account                          |
|     7) Display Account                        |
|     8) Exit                                   |
|-----------------------------------------------|

///////////////////////////////////////////////////////////////////


|-----------------------------------------------|
|                                               |
|     ACCOUNT CREATED SUCCESSFULLY              |
|                                               |
|-----------------------------------------------|
|     Account Number: 1234567890                |
|     Account Holder: John Doe                  |
|     Balance: $5000                            |
|     Type of Account: Savings                  |
|     Joint Holder: N/A                         |
|-----------------------------------------------|


//////////////////////////////////////////////////////////////////


|-----------------------------------------------|
|                                               |
|     Your Updated Details:                     |
|                                               |
|     Account Number: 1234567890                |
|     Account Holder: John Doe                  |
|     Balance: $5500                            |
|     Type of Account: Savings                  |
|     Joint Holder: N/A                         |
|-----------------------------------------------|


//////////////////////////////////////////////////////////////////



The balance in your account is: $5500
