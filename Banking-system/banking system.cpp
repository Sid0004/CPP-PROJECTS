#include<iostream>
#include<string>
#include<map>
using namespace std;

// Class to represent a bank account
class Account {
public:
    string name;
    string jointName;
    int Balance;
    int accountNumber;
    string accountType;
    string pin;

    Account(string n, string jName, string pinCode, int accNum, string accType, int initialBalance) {
        name = n;
        jointName = jName;
        pin = pinCode;
        accountNumber = accNum;
        accountType = accType;
        balance = initialBalance;
    }

    // Function to deposit money into the account
    void deposit(int amount) {
        balance += amount;
    }

    // Function to withdraw money from the account
    bool withdraw(int amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    // Function to change the account PIN
    void changePin(string newPin) {
        pin = newPin;
    }

    // Function to display account details
    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Type: " << accountType << endl;
        if (!jointName.empty()) {
            cout << "Joint Holder: " << jointName << endl;
        }
    }
};

// Global map to hold all the accounts, indexed by account number
map<int, Account> accounts;

// Function to generate a unique account number
int generateAccountNumber() {
    static int accountNumber = 1000;  // Start account numbers from 1000
    return accountNumber++;
}

// Function for user menu
void userMenu() {
    int choice;
    string name, jointName, pin, accountType;
    int initialBalance, amount, accNum;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Do you want a joint account (YES/NO)? ";
    cin >> jointName;
    if (jointName == "YES") {
        cout << "Enter joint holder's name: ";
        cin >> jointName;
    } else {
        jointName = "";
    }

    cout << "Enter your PIN: ";
    cin >> pin;
    cout << "Enter the type of account (1 for Savings, 2 for Current): ";
    int accTypeInput;
    cin >> accTypeInput;
    accountType = (accTypeInput == 1) ? "Savings" : "Current";
    
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    int accNumber = generateAccountNumber();
    Account newAccount(name, jointName, pin, accNumber, accountType, initialBalance);
    accounts[accNumber] = newAccount;

    cout << "Account successfully created!" << endl;
    cout << "Account Number: " << accNumber << endl;
}

// Function to handle administrator menu
void adminMenu() {
    cout << "Administrator Menu" << endl;
    cout << "1. View all accounts" << endl;
    cout << "2. View total number of accounts" << endl;
    int adminChoice;
    cin >> adminChoice;

    switch (adminChoice) {
    case 1:
        for (auto& acc : accounts) {
            acc.second.displayDetails();
            cout << "--------------------" << endl;
        }
        break;
    case 2:
        cout << "Total number of accounts: " << accounts.size() << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}

// Function for user to interact with their account
void handleUserAccount(int accNumber) {
    int userChoice;
    Account& userAccount = accounts[accNumber];

    do {
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Change PIN" << endl;
        cout << "4. View Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
        case 1:
            cout << "Enter amount to deposit: ";
            int depositAmount;
            cin >> depositAmount;
            userAccount.deposit(depositAmount);
            cout << "Deposit successful!" << endl;
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            int withdrawAmount;
            cin >> withdrawAmount;
            if (userAccount.withdraw(withdrawAmount)) {
                cout << "Withdrawal successful!" << endl;
            }
            break;
        case 3:
            cout << "Enter new PIN: ";
            string newPin;
            cin >> newPin;
            userAccount.changePin(newPin);
            cout << "PIN changed successfully!" << endl;
            break;
        case 4:
            userAccount.displayDetails();
            break;
        case 5:
            cout << "Exiting account." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (userChoice != 5);
}

// Function to login as user or admin
void login() {
    int choice;
    cout << "Welcome to Siddhant's Banking System" << endl;
    cout << "1. Admin Login" << endl;
    cout << "2. User Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        adminMenu();
        break;
    case 2:
        cout << "Enter account number: ";
        int accNumber;
        cin >> accNumber;

        if (accounts.find(accNumber) != accounts.end()) {
            handleUserAccount(accNumber);
        } else {
            cout << "Account not found!" << endl;
        }
        break;
    case 3:
        cout << "Exiting system." << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}

// Main function to start the program
int main() {
    int exitFlag = 0;

    do {
        login();
        cout << "Do you want to continue? (1 for Yes, 0 for No): ";
        cin >> exitFlag;
    } while (exitFlag == 1);

    return 0;
}
