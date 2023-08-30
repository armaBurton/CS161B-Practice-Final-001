#pragma once
#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

const int LEN = 50;
const int ARR_LEN = 50;
const char MENU_ITEM[5][LEN] = {
    "Add Item",
    "Remove Item",
    "Modify Item",
    "Print Cart",
    "Checkout"};

struct Item
{
    char name[LEN];
    double cost;
    int quantity;
};

void greeting();
void menu();
void getInt(int &option);
void addItem(Item item[], int &count);