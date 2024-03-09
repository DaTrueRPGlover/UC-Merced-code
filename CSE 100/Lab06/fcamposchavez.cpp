#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {
private:
    vector<list<int>> myTable; //vector of linked list
    int stable;

public:
    HashTable(int size) : stable(size) {
        myTable.resize(size);
    }

    void insert(int key) {
        int index = key % stable;
        myTable[index].push_front(key);
    }

    void search(int item) {
        int index = item % stable;
        int position = 0;
        for (int k : myTable[index]) {
            if (k == item) {
                cout << item << ":FOUND_AT" << index << "," << position << ";" << endl;
                return;
            }
            position++;
        }
        cout << item << ":NOT_FOUND;" << endl;
    }

    void remove(int item) {
        int index = item % stable;
        int position = 0;
        for (auto it = myTable[index].begin(); it != myTable[index].end(); ++it) {
            if (*it == item) {
                myTable[index].erase(it);
                cout << item << ":DELETED;" << endl;
                return;
            }
            position++;
        }
        cout << item << ":DELETE_FAILED;" << endl;
    }

    void display() {
        for (int i = 0; i < stable; i++) {
            cout << i << ":";
            for (int item : myTable[i]) {
                cout << item << "->";
            }
            cout << ";" << endl;
        }
    }
};

int main() {
    int size;
    cin >> size;
    HashTable myHash(size);

    char operation;
    while (cin >> operation) {
        if (operation == 'i') {
            int item;
            cin >> item;
            myHash.insert(item);
        }
        else if (operation == 's') {
            int item;
            cin >> item;
            myHash.search(item);
        }
        else if (operation == 'd') {
            int item;
            cin >> item;
            myHash.remove(item);
        }
        else if (operation == 'o') {
            myHash.display();
        }
        else if (operation == 'e') {
            break;
        }
    }

    return 0;
}
