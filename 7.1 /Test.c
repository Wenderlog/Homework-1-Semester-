#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Test.h"
#include "binaryTree.h"

void dictionaryCreateTest (FILE* fp) {
    fprintf(fp, "dictionaryCreateTest: ");
    Dictionary dictionary;
    initializeDictionary(&dictionary);
    insert(&dictionary, 3, "abc");
    insert(&dictionary, 2, "/32");
    insert(&dictionary, 4, "=-");
    freeDictionary(&dictionary);
    fprintf( fp, "Завершено\n");
    
}

void dictionaryFindTest (FILE* fp) {
    fprintf (fp, "dictionaryFindTest: ");
    Dictionary dictionary;
    initializeDictionary(&dictionary);
    insert(&dictionary, 3, "abc");
    insert(&dictionary, 2, "/32");
    insert(&dictionary, 4, "=-");
    assert(!strcmp(search(&dictionary, 2), "_32"));
    assert(!strcmp(search(&dictionary, 4), "-"));
    assert(search(&dictionary, 7) == NULL);
    freeDictionary(&dictionary);
    fprintf( fp, "Завершено\n");
}


void testCreateNode() {
    TreeNode* node = createNode(42, "TestValue");
    assert(node != NULL);
    assert(node->key == 42);
    assert(strcmp(node->value, "TestValue") == 0);
    assert(node->left == NULL);
    assert(node->right == NULL);
    free(node->value);
    free(node);
}

void testInsertAndSearch() {
    Dictionary dict;
    initializeDictionary(&dict);
    insert(&dict, 42, "TestValue");
    assert(contains(&dict, 42) == 1);
    assert(strcmp(search(&dict, 42), "TestValue") == 0);
    freeDictionary(&dict);
}

void testDelete() {
    Dictionary dict;
    initializeDictionary(&dict);
    insert(&dict, 42, "TestValue");
    removeKey(&dict, 42);
    assert(contains(&dict, 42) == 0);
    assert(search(&dict, 42) == NULL);
    freeDictionary(&dict);
}




