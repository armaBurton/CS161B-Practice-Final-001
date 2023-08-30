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

void menuOption(const char *prompt, int &num)
{
    int inputBuffer;
    do
    {
        cout << prompt;
        cin >> inputBuffer;
        cin.ignore(100, '\n');
        if (cin.fail())
        {
            cout << "You chose poorly\n";
            cout << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (inputBuffer < 1 || inputBuffer > 5)
        {
            cout << endl;
            cout << "User choice exceeds numerical bounds.\n";
            cout << endl;
        }
    } while (cin.fail() || inputBuffer < 1 || inputBuffer > 5);
    num = inputBuffer;
}

void handleOption(int option, Item item[], int &count)
{
    switch (option)
    {
    case 1:
        addItem(item, count);
        break;
    case 2:
        removeItem(item, count);
        break;
    case 3:
        cout << "3\n";
        break;
    case 4:
        printCart(item, count);
        break;
    case 5:
        cout << "5\n";
        break;

    default:
        break;
    }
}

void addItem(Item item[], int &count)
{
    char nameBuffer[LEN];
    double costBuffer;
    int quantityBuffer;

    cout << "Add item to the cart.\n\n";

    textualInput("Name: ", item[count].name);
    do
    {
        getDouble("Cost: $", item[count].cost);
        if (item[count].cost <= 0)
        {
            getDouble("Invalid value. Enter Cost: ", item[count].cost);
        }
    } while (item[count].cost <= 0);
    do
    {
        getInt("Quantity: ", item[count].quantity);
        if (item[count].quantity <= 0)
        {
            getInt("Invalid value. Enter Cost: ", item[count].quantity);
        }
    } while (item[count].cost <= 0);

    count++;
}

void textualInput(const char *prompt, char name[])
{
    cout << prompt;
    cin.getline(name, LEN, '\n');
}

void getDouble(const char *prompt, double &num)
{
    double inputBuffer = 0;

    do
    {
        cout << prompt;
        cin >> inputBuffer;
        if (cin.fail())
        {
            cout << "You chose poorly\n";
            cout << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail());
    cout << fixed << setprecision(2);
    num = inputBuffer;
}

void getInt(const char *prompt, int &num)
{
    int inputBuffer = 0;

    do
    {
        cout << prompt;
        cin >> inputBuffer;
        if (cin.fail())
        {
            cout << "You chose poorly\n";
            cout << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail());
    num = inputBuffer;
}

void printCart(Item item[], const int count)
{
    printMenu();
    for (int i = 0; i < count; i++)
    {
        cout << left << setw(5) << i + 1
             << setw(25) << item[i].name
             << setw(10) << item[i].cost
             << setw(5) << item[i].quantity
             << "$" << setw(12) << fixed << setprecision(2) << item[i].cost * item[i].quantity
             << endl;
    }
    cout << endl;
    system("pause");
    cout << endl;
}

void printMenu()
{
    cout << left << setw(5) << COLUMN_HEADERS[0]
         << setw(25) << COLUMN_HEADERS[1]
         << setw(10) << COLUMN_HEADERS[2]
         << setw(5) << COLUMN_HEADERS[3]
         << setw(12) << COLUMN_HEADERS[4]
         << endl;
    for (int i = 0; i < 57; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void removeItem(Item item[], int &count)
{
    printCart(item, count);
    int line;
    cout << endl;
    getInt("What item would you like to remove? ", line);
    cout << endl;

    for (int i = line - 1; i < count; i++)
    {
        item[i] = item[i + 1];
    }
    count--;
}
