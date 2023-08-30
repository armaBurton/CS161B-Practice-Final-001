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
        getInt(option);

    } while (option != 5);

    // addItem(item, count);

    return 0;
}