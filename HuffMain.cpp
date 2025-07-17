//========================================================
// IyiOluwa Adaramola
// CS 271
// Spring 2025
// studentTests.cpp
// This file tests the HuffmanCode algorithm
//========================================================

#include <iostream>
#include <bits/stdc++.h>
#include <cassert>
#include "HuffmanCode.hpp"
using namespace std;

void test_empty_string() {
    string str1 = "";
    assert(getCompressedSize(str1) == 0);
}

void test_single_character() {
    string str2 = "a";
    assert(getCompressedSize(str2) == 8);
}

void test_multiple_different_characters(){
    string str3 = "abc";
    assert(getCompressedSize(str3) > 0);
}

void test_string_with_duplicates(){
    string str4 = "aabbcc";
    assert(getCompressedSize(str4) > 0);
}


int main() {
    // test_empty_string();
    // test_single_character();
    // test_multiple_different_characters();
    // test_string_with_duplicates();
    // cout << "All tests have been passed" << endl;

    string input;
    cout << "Input string to get the huffman conversion " << endl;
    cin >> input;
    int answer = getCompressedSize(input);
    cout << "Compressed size: " << answer;

    return 0;
}