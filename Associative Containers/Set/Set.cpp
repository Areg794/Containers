#include <iostream>
#include <vector>

template <typename T>
class Set {
private:
    std::vector<T> elements;

public:
    void insert(const T& value) {
        if (!contains(value)) {
            elements.push_back(value);
        }
    }

    
    void remove(const T& value) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == value) {
                elements.erase(it);
                break; 
            }
        }
    }

   
    bool contains(const T& value) const {
        for (const T& element : elements) {
            if (element == value) {
                return true;
            }
        }
        return false;
    }

  
    size_t size() const {
        return elements.size();
    }


    void print() const {
        std::cout << "Set elements:";
        for (const T& element : elements) {
            std::cout << " " << element;
        }
        std::cout << std::endl;
    }
};

int main() {
    Set<int> mySet;

    mySet.insert(5);
    mySet.insert(10);
    mySet.insert(15);

    mySet.print();

    mySet.remove(10);
    mySet.print();

    std::cout << "Size of the set: " << mySet.size() << std::endl;

    bool contains15 = mySet.contains(15);
    bool contains20 = mySet.contains(20);

    std::cout << "Contains 15: " << contains15 << std::endl;
    std::cout << "Contains 20: " << contains20 << std::endl;

    return 0;
}
