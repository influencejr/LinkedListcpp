#include <iostream>
#include <Windows.h>


template<typename NodeData>
class List {
public:
    List();
    ~List();

    void pop_front();
    void pop_back();
    void clear();
    void push_back(NodeData data);
    void push_front(NodeData data);
    void insert(NodeData data, int index);
    void removeAt(int index);
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
    clear();
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

template<typename NodeData>
void List<NodeData>::clear() {
    while(Size) {
        pop_front();
    }
}

template<typename NodeData>
void List<NodeData>::pop_front() {
    Node *temp = head;

    head = head->pNext;
    delete temp;

    --Size;
}

template <typename NodeData>
void List<NodeData>::pop_back() {
    removeAt(Size - 1);
}

template<typename NodeData>
void List<NodeData>::push_front(NodeData data) {
    head = new Node(data, head);
    ++Size;
}

template<typename NodeData>
void List<NodeData>::insert(NodeData data, int index) {
    if (index == 0) {
        push_front(data);
    }
    Node *previous = this->head;
    for (int i = 0; i < index - 1; ++i) {
        previous = previous->pNext;
    }

    Node *newNode = new Node(data, previous->pNext);
    previous->pNext = newNode;

    ++Size;
}

template <typename NodeData>
void List<NodeData>::removeAt(int index) {
    if (index == 0) {
        pop_front();
    }
    Node *previous = this->head;
    for (int i = 0; i < index - 1; ++i) {
        previous = previous->pNext;
    }
    Node *delElem = previous->pNext;
    previous->pNext = delElem->pNext;

    delete delElem;
    --Size;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    List<int> lst;

    lst.push_back(15);
    lst.push_back(10);
    lst.push_back(123213);

    std::cout << lst[2] << std::endl;

    lst.push_front(77);
    lst.push_front(177);

    lst.insert(127, 2);

    for(int i = 0; i < lst.GetSize(); ++i) {
        std::cout << lst[i] << std::endl;
    }

    std::cout << lst.GetSize() << std::endl;

    lst.pop_front();

    std::cout << lst.GetSize() << std::endl;

    lst.removeAt(2);

    std::cout << lst.GetSize() << std::endl;

    lst.clear();

    std::cout << lst.GetSize() << std::endl;

    return 0;

}