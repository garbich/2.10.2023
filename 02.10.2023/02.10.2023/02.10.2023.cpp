#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    std::vector<std::list<int>> table;

public:
    HashTable() : table(TABLE_SIZE) {}

   
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    
    bool search(int key) {
        int index = hashFunction(key);
        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

   
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

   
    void displayTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "Bucket " << i << ": ";
            for (int value : table[i]) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable myHashTable;

    
    myHashTable.insert(5);
    myHashTable.insert(15);
    myHashTable.insert(25);
    myHashTable.insert(6);

   
    cout << "Initial Hash Table:" << endl;
    myHashTable.displayTable();

   
    int searchKey = 15;
    cout << "\nSearching for key " << searchKey << ": " << (myHashTable.search(searchKey) ? "Found" : "Not Found") << endl;

    
    int removeKey = 25;
    myHashTable.remove(removeKey);

    
   cout << "\nHash Table after removing key " << removeKey << ":" << endl;
    myHashTable.displayTable();

    
}