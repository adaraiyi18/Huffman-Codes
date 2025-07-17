/*
File name: HuffmanCode.hpp
Author: IyiOluwa Adaramola  
Last Updated: 04/02/2025
Creation Date: 03/29/2025
Description: Declarations and implementations for the Huffman Code algorithm
*/

#pragma once
#include <iostream>
#include <queue>
using namespace std;

class HuffNode {
    public:
    char character;
    int freq;
    HuffNode *left, *right;

    //=============================================================
    // constructor
    // Description:
    //      - creates a new ndoe for the huffman tree
    // Parameters:
    //      - None
    // Returns:
    //      - None
    //=============================================================
    HuffNode(void) {
        character = '\0';
        freq = 0;
        left = right = nullptr;
    }

    //=============================================================
    // setCharacter
    // Description:
    //      - sets a node's character value to inputted node
    // Parameters:
    //      - char c: 
    // Returns:
    //      - None
    //=============================================================
    void setCharacter(char c) {
        character = c;
    }

    //=============================================================
    // setLeftChild
    // Description:
    //      - sets a node's left child to inputted node
    // Parameters:
    //      - HuffNode* node: node whose left child is going to be set
    // Returns:
    //      - None
    //=============================================================
    void setLeftChild(HuffNode *node) {
        left = node;
    }

    //=============================================================
    // setRightChild
    // Description:
    //      - sets a node's right child to inputted node
    // Parameters:
    //      - HuffNode* node: node whose right child is going to be set
    // Returns:
    //      - None
    //=============================================================
    void setRightChild(HuffNode *node) {
        right = node;
    }

    //=============================================================
    // Destructor
    // Description:
    //      - cleans ups dynamic data
    // Parameters:
    //      - None
    // Returns:
    //      - None
    //=============================================================
    ~HuffNode() {}
};

struct HuffComparator {
    //=============================================================
    // comparator (operator)
    // Description:
    //      - comapres nodes a and b based on frequencies
    // Parameters:
    //      - HuffNode* a: first node
    //      - HuffNode* b: second node
    // Returns:
    //      - True - if a has a higher frequency
    //      - False - if b has a higher frequency
    //=============================================================
    bool operator()(HuffNode* a, HuffNode* b) {
        return a->freq > b-> freq;
    }
};

//=============================================================
// huffmanCode
// Description:
//      - Creates a Huffman tree that encodes the characters
//        in a string using their frequencies in the string
// Parameters:
//      - string s: 
// Returns:
//      - Q.top(): the first element in the min-priority queue
//        which would be the top of the Huffman treee
//=============================================================
HuffNode* huffmanCode(string s) {
    priority_queue<HuffNode*, vector<HuffNode*>, HuffComparator> Q;
    int freq[256] = {0};

    for (char c: s) {
        freq[(int)c]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            HuffNode* u = new HuffNode();
            u->setCharacter(i);
            u->freq = freq[i];
            Q.push(u);
        }
    }    
    int n = Q.size();
    for (int i = 0; i < n - 1; i++) {
        HuffNode* z = new HuffNode();
        z->setLeftChild(Q.top());
        Q.pop();
        z->setRightChild(Q.top());
        Q.pop();
        z->freq = z->left->freq + z->right->freq;
        Q.push(z);
    }
    return Q.top();
}

//=============================================================
// calculateTreeHelper
// Description:
//      - calculates the code length for a particular character in
//        a string
// Parameters:
//      - HuffNode* node: node in tree being inputted
//      - string code: code inputted
//      - vector<int>& code_lengths: reference to the code_lengths vector
// Returns:
//      - None
//=============================================================
void calculateTreeHelper(HuffNode* node, string code, vector<int>& code_lengths) {
    if (node == nullptr) return;

    if (node->left == nullptr && node->right == nullptr) {
        code_lengths[node->character] = code.length();
        return;
    }

    calculateTreeHelper(node->left, code + "0", code_lengths);
    calculateTreeHelper(node->right, code + "1", code_lengths);
}

//=============================================================
// getCompressedSize
// Description:
//      - 
// Parameters:
//      - const string &s: const reference to a string object, the
//        string object which we would find the compressed size for
// Returns:
//      - compressed size: the size fo the bits of the inputted
//        string s
//=============================================================
int getCompressedSize(const string &s) {
    if (s.empty()) return 0;

    if(s.size() == 1) {
        return 8;
    }

    HuffNode* root = huffmanCode(s);
    vector<int> code_lengths(256, 0);

    calculateTreeHelper(root, "", code_lengths);

    int compressed_size = 0;
    for (char c : s) {
        compressed_size += code_lengths[(int)c];
    }
    return compressed_size;
}







