#include "Cart.h"

int main()
{
    Item item[ARR_LEN];
    int count = 0;
    int option = 0;

    greeting();
    do
    {
        menu();

        cout << endl;

        menuOption("What would you like to do? ", option);

        cout << endl;

        handleOption(option, item, count);
    } while (option != 5);

    // addItem(item, count);

    return 0;
}