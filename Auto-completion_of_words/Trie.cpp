#include <iostream>
#include <cstring>
#include "Trie.h"

using namespace std;

// �������� ������ ����
TrieNode* createNode() {
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = nullptr;
    }

    return node;
}

// ������� ����� � ������
void insert(TrieNode* root, const char* word) {
    TrieNode* current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (!current->children[index]) {
            current->children[index] = createNode();
        }

        current = current->children[index];
    }

    current->isEndOfWord = true;
}

// ��������, �������� �� ���� ������ (��� �������� �����)
bool isLeafNode(TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            return false;
        }
    }
    return true;
}

// ����������� ������� ��� ��������������
void suggestHelper(TrieNode* node, char* prefix, int length) {
    if (node->isEndOfWord) {
        prefix[length] = '\0';
        std::cout << prefix << std::endl;
    }

    if (isLeafNode(node)) {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            prefix[length] = 'a' + i;
            suggestHelper(node->children[i], prefix, length + 1);
        }
    }
}

// ������� ��� ������ � ������ ��������������
int printSuggestions(TrieNode* root, const char* query) {
    TrieNode* current = root;

    int length = strlen(query);
    char prefix[100]; // ������������ ����� ����� - 100 ��������

    for (int i = 0; i < length; i++) {
        prefix[i] = query[i];
    }

    for (int i = 0; i < length; i++) {
        int index = query[i] - 'a';

        if (!current->children[index]) {
            return 0; // ��� ���� � ����� ���������
        }

        current = current->children[index];
    }

    // ���� ������� ���� � �������, ������� ��� ����� � ����� ���������
    suggestHelper(current, prefix, length);
    return 1;
}

// ������������� �������
void initializeDictionary(TrieNode* root) {
    const char* dictionary[] = {
        "apple", "application", "appetite", "banana", "ball",
        "cat", "car", "dog", "elephant", "zebra",
        "hello", "world", "program", "computer", "algorithm"
    };

    int dictionarySize = sizeof(dictionary) / sizeof(dictionary[0]);

    for (int i = 0; i < dictionarySize; i++) {
        insert(root, dictionary[i]);
    }
}

// ������� ������
void deleteTrie(TrieNode* node) {
    if (!node) return;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        deleteTrie(node->children[i]);
    }

    delete node;
}