#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    unordered_map<char, int> frequency;
    for (char c : input) {
        frequency[c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto& pair : frequency) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    Node* root = pq.top();
    unordered_map<char, string> huffmanCodes;
    string code = "";
    queue<pair<Node*, string>> q;
    q.push({root, code});

    while (!q.empty()) {
        Node* node = q.front().first;
        string currentCode = q.front().second;
        q.pop();

        if (node->left == nullptr && node->right == nullptr) {
            huffmanCodes[node->data] = currentCode;
        }

        if (node->left) {
            q.push({node->left, currentCode + "0"});
        }
        if (node->right) {
            q.push({node->right, currentCode + "1"});
        }
    }

    cout << "Huffman Encoding:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
