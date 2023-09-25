#include <iostream>
#include <vector>

class UnorderedSet {
private:
    static const int TABLE_SIZE = 128;
    std::vector<std::vector<int>> table;

    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    UnorderedSet() {
        table.resize(TABLE_SIZE);
    }

    void insert(int key) {
        int index = hash(key);
        for (int value : table[index]) {
            if (value == key) {
                return; 
            }
        }
        table[index].push_back(key);
    }

    void erase(int key) {
        int index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int index = hash(key);
        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i].empty()) {
                for (int value : table[i]) {
                    std::cout << value << " ";
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    UnorderedSet mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    mySet.print();

    if (mySet.contains(2)) {
        std::cout << "Set contains 2." << std::endl;
    }

    mySet.erase(2);
    mySet.print();

    return 0;
}
