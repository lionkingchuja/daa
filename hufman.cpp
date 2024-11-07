#include<bits/stdc++.h>
using namespace std;

// Huffman Tree Node
struct HuffmanNode {
    char character;
    int frequency;
    HuffmanNode *left, *right;
    
    HuffmanNode(char character, int frequency) {
        this->character = character;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->frequency > right->frequency;
    }
};

// Function to build the Huffman Tree
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencyMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;
    
    // Step 1: Create a leaf node for each character and add it to the priority queue
    for (auto pair : frequencyMap) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }
    
    // Step 2: Build the tree
    while (minHeap.size() != 1) {
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();
        
        int sum = left->frequency + right->frequency;
        HuffmanNode* parent = new HuffmanNode('\0', sum); // Internal node
        parent->left = left;
        parent->right = right;
        
        minHeap.push(parent);
    }
    
    return minHeap.top(); // Root of the Huffman Tree
}

// Function to generate Huffman Codes from the Huffman Tree
void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) return;
    
    // Leaf node contains the character
    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code;
    }
    
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to print Huffman Codes
void printHuffmanCodes(const unordered_map<char, string>& huffmanCodes) {
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}

// Main function to perform Huffman Encoding
void huffmanEncoding(const string& text) {
    // Step 1: Count frequency of each character
    unordered_map<char, int> frequencyMap;
    for (char ch : text) {
        frequencyMap[ch]++;
    }
    
    // Step 2: Build Huffman Tree
    HuffmanNode* root = buildHuffmanTree(frequencyMap);
    
    // Step 3: Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);
    
    // Step 4: Print the Huffman Codes
    printHuffmanCodes(huffmanCodes);
    
    // Step 5: Encode the text
    string encodedText = "";
    for (char ch : text) {
        encodedText += huffmanCodes[ch];
    }
    
    cout << "\nEncoded Text:\n" << encodedText << "\n";
}

// Main
int main() {
    string text;
    cout << "Enter text to encode: ";
    getline(cin, text);
    
    huffmanEncoding(text);
    return 0;
}
