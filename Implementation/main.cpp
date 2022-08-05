#include "Account.h"
#include "Bank.h"

#include <iostream>
using std::cin, std::cout, std::endl;


bool showMenu(Account *account){
    std::cout << "\nMenu" << endl;
    std::cout << "1: Wykonaj przelew" << endl;
    std::cout << "2: Wez pozyczke" << endl;
    std::cout << "3: Zmien nazwe uzytkownika" << endl;
    std::cout << "4: Zmien haslo" << endl;
    std::cout << "5: Sprawdz stan konta" << endl;
    std::cout << "6: Pokaz historie operacji" << endl;
    std::cout << "7: Wyjdz z aplikacji" << endl;

    int option;

    cin >> option;


    switch (option) {
        case 1: {
            account->makeTransfer();
            break;
        }
        case 2: {
            account->takeLoan();
            break;
        }
        case 3: {
            cout << "\nPodaj nowa nazwe uzytkownika: ";
            string username;
            cin >> username;
            account->setUsername(username);
            break;
        }
        case 4: {
            cout << "\nPodaj nowe haslo: ";
            string password;
            cin >> password;
            account->setPassword(password);
            break;
        }
        case 5: {
            cout << "\nAktualny stan konta: " << account->getBalance() << endl;
            break;
        }
        case 6: {
            account->showHistory();
            break;
        }
        case 7: {
            return false;
        }
        default: {
            cout << "\nNie ma takiej opcji" << endl;
            break;
        }
    }

    return true;
}

int main() {
    Bank bank;
    bank.addCustomer("01234567890", "Jan", "Kowalski", "jan@email.com", "123456789");
    bank.addAccount("01234567890", "login", "haslo", 500);
    Account *account;
    while(true) {
        string op;
        cout << "\nLogowanie\n\n";

        cout << "Login: ";
        string username;
        cin >> username;

        cout << "Haslo: ";
        string password;
        cin >> password;

        account = bank.findAccount(username, password);
        if(account == nullptr) {
            cout << "\nNieprawidlowy login lub haslo.\nSprobowac ponownie? Y/N\n";
            cin >> op;
            if(op == "Y" || op == "y") continue;
            return 0;
        }
        cout << "\nWitaj " << account->getCustomer()->getFullName() << "\n";
        break;
    }
    while (true){
        if(!showMenu(account)){
            break;
        }
    }
    std::cout << "\nWylogowano pomyslnie\n\n";
    return 0;
}
