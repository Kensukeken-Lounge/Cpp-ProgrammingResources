#include <iostream>

struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    Node *front;

    LinkedList() : front(nullptr) {}
};

LinkedList* create() {
    LinkedList *list = new LinkedList();
    if (list == nullptr) {
        // Handle allocation failure
        return nullptr;
    }
    return list;
}

int main() {
    LinkedList *list = create();
    if (list != nullptr) {
        std::cout << "List created successfully" << std::endl;
    } else {
        std::cout << "Failed to create list" << std::endl;
    }
    return 0;
}