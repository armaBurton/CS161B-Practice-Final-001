#pragma once
#include <iostream>
#include <cstring>
#include <limits>
#include <iomanip>

using namespace std;

const int LEN = 50;
const int ARR_LEN = 50;
const char MENU_ITEM[5][LEN] = {
    "Add Item",
    "Remove Item",
    "Modify Item",
    "Print Cart",
    "Checkout"};

const char COLUMN_HEADERS[5][LEN] = {
    "#",
    "Item",
    "Price",
    "Qty",
    "Total Cost"};

struct Item
{
    char name[LEN];
    double cost;
    int quantity;
};

void greeting();
void menu();
void menuOption(const char *prompt, int &num);
void handleOption(int option, Item item[], int &count);
void addItem(Item item[], int &count);
void textualInput(const char *prompt, char name[]);
void getDouble(const char *prompt, double &num);
void getInt(const char *prompt, int &num);
void printCart(Item item[], const int count);
void printMenu();
void removeItem(Item item[], int &count);
void modifyItem(Item item[], int count);
void modify(Item &item);
void handleCheckout(Item item[], const int count);