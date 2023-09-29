#include <iostream>
#include <list>

template <typename T>
class Queue {
private:
    std::list<T> elements;

public:
    void enqueue(const T& element) {
        elements.push_back(element);
    }

    void dequeue() {
        if (!empty()) {
            elements.pop_front();
        }
    }


    T front() const {
        if (!empty()) {
            return elements.front();
        }
        throw std::runtime_error("Queue is empty");
    }

    bool empty() const {
        return elements.empty();
    }

    // Get the size of the queue
    size_t size() const {
        return elements.size();
    }
};

int main() {
    Queue<int> myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element: " << myQueue.front() << std::endl;
    myQueue.dequeue();
    std::cout << "Front element after dequeue: " << myQueue.front() << std::endl;

    return 0;
}
