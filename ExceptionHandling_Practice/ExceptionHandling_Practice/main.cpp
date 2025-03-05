#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include <vector>
#include <string>

using namespace Practice;

int main()
{
    Item item1("Apple");
    Item item2("Pear");
    Item item3("Watermelon");
    Item item4("Mouse");
    Item item5("Comp");
    Item item6("Key");
    Item item7("Sugar");
    Item item8("Donut");
    Item item9("Coke");
    Item item10("Chips");
    Item item11("Blueberry");

    Inventory storage;

    storage.AddItem(item1);
    storage.AddItem(item2);
    storage.AddItem(item3);
    storage.AddItem(item4);
    storage.AddItem(item5);
    storage.AddItem(item6);
    storage.AddItem(item7);
    storage.AddItem(item8);
    storage.AddItem(item9);
    storage.AddItem(item10);
    storage.AddItem(item11);

    storage.DisplayInventory();

    storage.RemoveItem("F");

    storage.DisplayInventory();
}
