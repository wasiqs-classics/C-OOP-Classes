#include <iostream>
#include <string>
#include <cctype>


using namespace std;

class Err_Rpt
{
public:
    string msg;
    Err_Rpt(const char* m) : msg(m){}
};

class Account
{
private:
    string name;
    double bal;

    // private method as helper function
    bool isNameValid(const string& str){
        for(char ch : str){
            if(!isalpha(ch)) return false;
        } return true;
    }

public:
    void create_acnt(const string& acc_name, double initial_bal){
        if (!isNameValid(acc_name)){
            throw Err_Rpt("The names must be alphabats only.");
        }
        if (initial_bal < 0) {
            throw Err_Rpt("Initial Balance must be greater than zero");
        }

        name = acc_name;
        bal = initial_bal;

    }

    void deposit(double amount) {
        if (amount <= 0){
            throw Err_Rpt("Positive deposits only!)");
        }
        bal += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0){
            throw Err_Rpt("Positive withdrawals only!)");
        }
        if (amount > bal) {
            throw Err_Rpt("Insufficient balance");
        }
        bal -= amount;
    }
    void show() const {
        cout << "Account Holder's Name: " << name << endl;
        cout << "Account Balance: " << bal << endl;
    }

};


int main(){

    Account account;
    string account_name;
    double initial_balance;

    while (true)
    {
        try
        {
            cout << "What is account holder's name? " << endl;
            cin >> account_name;

            cout << "What balance do you want to start with? " << endl;
            cin >> initial_balance;

            account.create_acnt(account_name, initial_balance);
            break;
        }
        catch(const Err_Rpt& e)
        {
            cout << "Error caught: " << e.msg << endl;
            cout << "Please try again!" << endl;
        }
        
    }

    while (true)
    {
        try
        {
           cout << "\nEnter amount to deposit: ";
           double deposit_amount;
           cin >> deposit_amount;
           account.deposit(deposit_amount);

           cout << "\nEnter amount to withdraw: ";
           double withdrawal_amount;
           cin >> withdrawal_amount;
           account.withdraw(withdrawal_amount);

           account.show();
           break;
        }
        catch(const Err_Rpt& e)
        {
            cout << "Error caught: " << e.msg << endl;
            cout << "Please try again!" << endl;
        }
        
    }
    

    return 0;
}




