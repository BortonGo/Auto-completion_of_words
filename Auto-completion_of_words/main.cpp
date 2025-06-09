#include <iostream>
#include <cstring>
#include "Trie.h"


int main() {
    setlocale(LC_ALL, "rus");
    // ������� ������ ����������� ������
    TrieNode* root = createNode();

    // �������������� �������
    initializeDictionary(root);

    char input[100];
    int choice;

    do {
        std::cout << "\n������� ����� ����� (��� 'exit' ��� ������): ";
        std::cin >> input;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        std::cout << "����������� �� ��������������:\n";
        int found = printSuggestions(root, input);

        if (!found) {
            std::cout << "���� � ����� ��������� �� �������.\n";
        }

    } while (true);

    // ������� ������
    deleteTrie(root);

    return 0;
}