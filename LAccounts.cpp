#include "AccountsManager.h"
#include <iostream>
#include <memory>

using namespace std;

void show_all_accounts(AccountsManager*);
void add_account(AccountsManager*);
void remove_account(AccountsManager*);
void update_account(AccountsManager*);

int main()
{
    string filename;
    cout << "Input the file name to store your accounts." << endl;
    cin >> filename;
    auto manager = make_unique<AccountsManager>(filename);
    bool flag = true;
    while (flag)
    {
        cout << "All the accounts in " << filename << ":" << endl;
        show_all_accounts(manager.get());
        cout << "Input an option( 1.show all accounts  2.add an account  3.remove an account  4.update an account  5.quit ):" << endl;
        int option;
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1:
            show_all_accounts(manager.get());
            break;
        case 2:
            add_account(manager.get());
            break;
        case 3:
            try
            {
                remove_account(manager.get());
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        case 4:
            try
            {
                update_account(manager.get());
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        case 5:
            cout << "Good bye!";
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

void show_all_accounts(AccountsManager* manager)
{
    size_t n = 1;
    for (Account account : manager->all_accounts())
    {
        cout << n << ".name:" << account.name << " username:" << account.username << " password:" << account.password << endl;
        ++n;
    }
}

void add_account(AccountsManager* manager)
{
    Account account;
    cout << "Input the name:";
    cin >> account.name;
    cout << "Input the username:";
    cin >> account.username;
    cout << "Input the password:";
    cin >> account.password;
    manager->write_account(account);
    cout << "Successfully added the account!" << endl;
}

void remove_account(AccountsManager* manager)
{
    cout << "Input the index of the account you want to remove:";
    size_t index;
    cin >> index;
    manager->erase_account(index);
    cout << "Successfully removed the account!" << endl;
}

void update_account(AccountsManager* manager)
{
    cout << "Input the index of the account you want to update:";
    size_t index;
    cin >> index;
    Account account;
    cout << "Input the new name:";
    cin >> account.name;
    cout << "Input the new username:";
    cin >> account.username;
    cout << "Input the new password:";
    cin >> account.password;
    manager->edit_account(index, account);
    cout << "Successfully updated the account!" << endl;
}