#include "AccountsManager.h"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

string filename = "lemon.lad";
AccountsManager manager(filename);

void show_all_accounts();
void add_account();
void remove_account();

int main()
{
    bool flag = true;
    while (flag)
    {
        cout << "All the accounts in " << filename << ":" << endl;
        show_all_accounts();
        cout << "Input an option( 1.show all accounts  2.add an account  3.remove an account  4.quit ):" << endl;
        int option;
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1:
            show_all_accounts();
            break;
        case 2:
            add_account();
            break;
        case 3:
            try
            {
                remove_account();
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        case 4:
            cout << "Good bye!" << endl;
            flag = false;
            break;
        default:
            cout << "Invalid input." << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}

void show_all_accounts()
{
    size_t n = 1;
    for (Account account : manager.all_accounts())
    {
        cout << n << ".website:" << account.website << " username:" << account.username << " password:" << account.password << endl;
        ++n;
    }
}

void add_account()
{
    Account account;
    cout << "Input the website:";
    cin >> account.website;
    cout << "Input the username:";
    cin >> account.username;
    cout << "Input the password:";
    cin >> account.password;
    manager.write_account(account);
    cout << "Successfully added the account!" << endl;
}

void remove_account()
{
    cout << "Input the index of the account you want to remove:";
    size_t index;
    cin >> index;
    manager.erase_account(index);
    cout << "Successfully removed the account!" << endl;
}