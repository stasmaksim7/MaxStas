#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(string accNum, string owner, double initialBalance){
        accountNumber = accNum;
        ownerName = owner;
        balance = initialBalance;
    }

    void deposit(double amount){
        if(amount > 0){
            balance += amount;
            cout << "Пополнено: +" << amount << " руб." << endl;
        } else {
            cout << "Ошибка: сумма должна быть положительной!" << endl;
        }
    }

    bool withdraw(double amount){
        if(amount > 0 && amount <= balance){
            balance -= amount;
            cout << "Снято: -" << amount << " руб." << endl;
            return true;
        } else {
            cout << "Ошибка: недостаточно средств или неверная сумма!" << endl;
            return false;
        }
    }

    void displayInfo(){
        cout << "Счет: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << balance << " руб." << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string owner, double initialBalance, double rate)
        : BankAccount(accNum, owner, initialBalance){
        interestRate = rate;
    }

    void applyInterest(){
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Начислены проценты: +" << interest << " руб. (ставка: " << interestRate << "%)" << endl;
    }

    void displayInfo(){
        BankAccount::displayInfo();
        cout << "Процентная ставка: " << interestRate << "%" << endl;
    }
};

int main(){
    cout << "===== Работа банка =====" << endl;
    
    BankAccount regular("1234567890", "Иван Иванов", 5000.0);
    cout << "\nОбычный счет:" << endl;
    regular.displayInfo();
    regular.deposit(1500.0);
    regular.withdraw(2000.0);
    regular.displayInfo();
    
    cout << "\nСберегательный счет:" << endl;
    SavingsAccount savings("0987654321", "Петр Петров", 10000.0, 5.0);
    savings.displayInfo();
    savings.deposit(3000.0);
    savings.withdraw(1000.0);
    savings.applyInterest();
    savings.displayInfo();
    
    return 0;
}