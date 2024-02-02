#pragma once

#include <fstream>
#include <string>
#include <vector>

struct Account
{
    std::string name;
    std::string username;
    std::string password;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem, _Traits>& operator<<(std::basic_ostream<_Elem, _Traits>& os, const Account& account)
{
    os << account.name << ' ' << account.username << ' ' << account.password;
    return os;
}

class AccountsManager
{
    std::vector<Account> accounts;
    std::string filename;
    std::fstream f;

public:
    void get_accounts();
    std::vector<Account> all_accounts();
    void write_account(const Account& account);
    void erase_account(size_t index);
    void edit_account(size_t index, const Account& new_account);

    static size_t countLines(const std::string& filename);
    explicit AccountsManager(const std::string& file = "accounts.lad");
    ~AccountsManager() = default;
};
