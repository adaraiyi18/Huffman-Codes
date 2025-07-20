## Huffman Coding Compression Project
CS 271 — Spring 2025  
Author: IyiOluwa Adaramola  
Project: Huffman Coding Algorithm Implementation and Testing

## Overview
This project implements Huffman Coding, a lossless data compression algorithm. It builds a binary tree based on the frequency of characters in a given string and calculates the compressed size of that string using optimal binary encodings.

## What This Project Does
Encodes strings using Huffman coding

Computes the compressed size (in bits) of a string

Includes unit tests for correctness

Provides a simple CLI to input a string and view its compressed size

## Files
File Name	Description
HuffmanCode.hpp	Contains all the class definitions and algorithm logic for Huffman coding.
studentTests.cpp	Contains test cases and the main driver function for running the program.

## How It Works
Example Flow:
You enter a string like "banana".

The algorithm counts the frequency of each character.

It constructs a Huffman tree using a min-heap priority queue.

Each character gets a unique binary encoding based on its frequency.

The program calculates the total bit-length of the compressed string.

Special Cases:
An empty string returns 0.

A single-character string always returns 8 bits (standard ASCII).

## Test Cases
The following test functions are defined in studentTests.cpp:

test_empty_string()

test_single_character()

test_multiple_different_characters()

test_string_with_duplicates()

Uncomment them in main() to run individually and validate correctness via assert.

## How to Run
Requirements: C++ compiler (like g++) (C++11 or later)

## Compile & Run
```bash
g++ studentTests.cpp -o huffman
./huffman
```

## Example Usage
```
Input string to get the huffman conversion
>> hello
Compressed size: 13
```

## Notes
This implementation is a simplified simulation and does not output the actual binary code or encode/decode files.

It focuses on educational understanding of Huffman Coding and frequency-based tree construction.

## References
Huffman, D. A. "A Method for the Construction of Minimum-Redundancy Codes." Proceedings of the IRE, 1952.

