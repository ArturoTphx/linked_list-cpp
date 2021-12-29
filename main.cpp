#include "List.h"

int main() {
    auto * list = new List<string>();
    list->insert("Pointers");
    list->insert("World");
    list->insert("Tellphex");
    list->insert("Hello");
    cout << list->toList() << "\n";
    delete list;
    return 0;
}
