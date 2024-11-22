#include <iostream>
#include <Windows.h>



template<typename NodeData>
class List {
public:
    List();
    ~List();

    void push_back(NodeData data);
    int GetSize() {return Size;}

    NodeData& operator[](const int index);

private:
    
    //template<typename NodeData>
    class Node {


        public:
        Node *pNext;
        NodeData data;
        Node(NodeData data = NodeData(), Node *pNext = nullptr) {
            this->pNext = pNext;
            this->data = data;
        }
    };

    int Size;
    Node *head;
};

template<typename NodeData>
List<NodeData>::List() {
    Size = 0;
    head = nullptr;
}

template<typename NodeData>
List<NodeData>::~List() {

}

template<typename NodeData>
void List<NodeData>::push_back(NodeData data) {
    if (head == nullptr) {
        head = new Node(data);
    } else {
        Node *current = this->head;
        while(current->pNext != nullptr ){
            current = current->pNext;
        }
        current->pNext = new Node(data);

    }
    ++Size;
}

template<typename NodeData>
NodeData& List<NodeData>::operator[](const int index) {
    int counter = 0;
    Node *current = this->head;
    while(current != nullptr) {
        if (counter == index) {
            return current->data;
        }

        current = current->pNext;
        ++counter;
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    List<int> lst;

    lst.push_back(15);
    lst.push_back(10);
    lst.push_back(123213);

    std::cout << lst[2] << std::endl;


    std::cout << lst.GetSize() << std::endl;
    return 0;

}