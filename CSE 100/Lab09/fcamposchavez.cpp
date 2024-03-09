#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Node {
public:
    char character;
    int f;
    Node* left;
    Node* right;

    Node(char ch, int freq) : character(ch), f(freq), left(nullptr), right(nullptr) {}
};

struct NodeComparator {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

Node* buildHufTree(map<char, int> fs) {
    priority_queue<Node*, vector<Node*>, NodeComparator> minHeap;

    for (const auto& entry : fs) {
        minHeap.push(new Node(entry.first, entry.second));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        Node* parent = new Node(0, left->f + right->f);
        parent->left = left;
        parent->right = right;
        minHeap.push(parent);
    }

    return minHeap.top();
}

void genHuffCode(Node* root, string code, map<char, string>& huffCode) {
    if (!root) {
        return;
    }

    if (root->character) {
        huffCode[root->character] = code;
    }

    genHuffCode(root->left, code + "0", huffCode);
    genHuffCode(root->right, code + "1", huffCode);
}

int main() {
    map<char, int> fs;
    char letter = 'A';

    for (int i = 0; i < 6; i++) {
        int f;
        cin >> f;
        fs[letter] = f;
        letter++;
    }

    Node* root = buildHufTree(fs);
    map<char, string> huffCode;
    genHuffCode(root, "", huffCode);

    for (const auto& entry : huffCode) {
        cout << entry.first << ":" << entry.second << endl;
    }

    return 0;
}

