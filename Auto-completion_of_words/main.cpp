#include <iostream>
#include <cstring>
#include "Trie.h"


int main() {
    setlocale(LC_ALL, "rus");
    // Создаем корень префиксного дерева
    TrieNode* root = createNode();

    // Инициализируем словарь
    initializeDictionary(root);

    char input[100];
    int choice;

    do {
        std::cout << "\nВведите часть слова (или 'exit' для выхода): ";
        std::cin >> input;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        std::cout << "Предложения по автодополнению:\n";
        int found = printSuggestions(root, input);

        if (!found) {
            std::cout << "Слов с таким префиксом не найдено.\n";
        }

    } while (true);

    // Очищаем память
    deleteTrie(root);

    return 0;
}