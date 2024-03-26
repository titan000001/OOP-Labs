#include<bits/stdc++.h>
using namespace std;

class Account{
private:
    int accountNumber;
    double balance;
    
public:
    Account(int accNum,double bal) : accountNumber(accNum), balance(bal){}

    double getbalance() const{
        return balance;
    }

    void deposit(double amount){
        balance += amount;
        cout << "Deposited: " << amount << ". New balance: " << balance << endl;
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New balance: " << balance << endl;
        }else{
            cout << "Insufficient balace, cannot withdraw" << endl;
        }
    }
};

class SavingsAccount :virtual public Account{
private:
    double interestRate;
public:
    SavingsAccount(int accNum,double bal, int intRate) : Account(accNum,bal), interestRate(intRate){};

    void calculateInterest(){
        double interest = getbalance() * interestRate;
        cout << "Interest earned: " << interest << endl;
        deposit(interest);
    }
};

class CurrentAccount :virtual public Account {
public: 
    CurrentAccount(int accNum, double bal): Account(accNum,bal){}

    void deductServiceCharge(double charge){
        withdraw(charge);
        cout << "Service charge " << charge << " deducted" << endl;
    }
};

class JointAccount : public CurrentAccount, public SavingsAccount{
private:
    string primaryOwner;
    string secondaryOwner;
public:
    JointAccount(int accNum, double bal, double rate, const string& owner1, const string& owner2)
    :Account(accNum, bal) ,SavingsAccount(accNum, bal,rate), CurrentAccount(accNum, bal),primaryOwner(owner1),secondaryOwner(owner2){};

    void displayOwners() const{
        cout << "Primary owner: " << primaryOwner << endl;
        cout << "Secondary owner: " << secondaryOwner << endl;
    }

    void deposit(double amount){
        Account::deposit(amount);
    }

    void withdraw(double amount){
        Account::withdraw(amount);
    }

};

int main() {
    SavingsAccount savings(1001, 5000.0, 0.05);
    savings.deposit(1000.0);
    savings.calculateInterest();

    CurrentAccount current(2001, 10000.0);
    current.withdraw(2000.0);
    current.deductServiceCharge(25.0);

    JointAccount joint(3001, 20000.0, 0.07, "Tawhidul Islam", "Nirjhara Gharami");
    joint.displayOwners();
    joint.deposit(5000.0);
    joint.withdraw(10000.0);
    joint.calculateInterest();

    return 0;
}
                                                                                                                                            