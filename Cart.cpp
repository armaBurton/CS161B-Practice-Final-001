#include "Cart.h"

void greeting()
{
    cout << "Welcome to my Online Shopping program\n"
         << endl;
}

void menu()
{
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << MENU_ITEM[i] << endl;
    }
}

void getInt(int &option)
{
    int inputBuffer;
    do
    {
        cout << endl;
        cout << "What would you like to do? ";
        cin >> inputBuffer;
        cin.ignore(100, '\n');
        cout << endl;
        if (cin.fail())
        {
            cout << "You chose poorly\n";
            cout << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (inputBuffer < 1 || inputBuffer > 5)
        {
            cout << "User choice exceeds numerical bounds.\n";
        }
    } while (!cin.fail() && (inputBuffer < 1 || inputBuffer > 5));
    option = inputBuffer;
}

void addItem(Item item[], int &count)
{
    cout << "Add item to the cart.\n";
}
