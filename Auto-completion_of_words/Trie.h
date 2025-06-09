#pragma once
#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* createNode();
void insert(TrieNode* root, const char* word);
bool isLeafNode(TrieNode* node);
void suggestHelper(TrieNode* node, char* prefix, int length);
int printSuggestions(TrieNode* root, const char* query);
void initializeDictionary(TrieNode* root);
void deleteTrie(TrieNode* node);
