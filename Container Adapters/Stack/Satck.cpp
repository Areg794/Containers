#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& item) {
        elements.push_back(item);
    }

    T pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    T top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << "Top element: " << intStack.top() << std::endl;
    std::cout << "Stack size: " << intStack.size() << std::endl;

    while (!intStack.empty()) {
        std::cout << "Popped element: " << intStack.pop() << std::endl;
    }

    return 0;
}
