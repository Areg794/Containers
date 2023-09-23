#include <iostream>

template<typename T>
class FList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {

        }
    };
    Node* head;
public:
    FList() : head(nullptr) {}
    ~FList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(const T& value) {
        Node* newnode = new Node(value); 
        newnode->next = head;
        head = newnode;
    }

    void pop_front() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int count = 0;
        Node* current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
};

int main() {
    FList<int> list;
    list.push_front(5);
    list.push_front(10);
    list.push_front(374);

    list.print();
    list.pop_front();
    list.print();
    std::cout << "the size of the list: " << list.size() << std::endl;
    return 0;
}
