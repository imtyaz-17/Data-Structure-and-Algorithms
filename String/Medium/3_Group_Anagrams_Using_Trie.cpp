// Given a sequence of words, print all anagrams together
// https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together-set-2/

// Using Trie
// Time Complexity: O(MN+N*MlogM) , Auxiliary Space: O(MN).

#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 26

struct IndexNode
{
    int index;
    struct IndexNode *next;
};
struct TrieNode
{
    bool isEnd;
    struct TrieNode *child[NO_OF_CHARS];
    struct IndexNode *head;
};
struct TrieNode *newTrieNode()
{
    struct TrieNode *temp = new TrieNode;
    temp->isEnd = 0;
    temp->head = NULL;

    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        temp->child[i] = NULL;
    }

    return temp;
}

int compare(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}
struct IndexNode *newIndexNode(int index)
{
    struct IndexNode *temp = new IndexNode;
    temp->index = index;
    temp->next = NULL;
    return temp;
}

void insert(struct TrieNode **root, char *word, int index)
{
    if (*root == NULL)
        *root = newTrieNode();
    if (*word != '\0')
        insert(&((*root)->child[tolower(*word) - 'a']), word + 1, index);
    else
    {
        if ((*root)->isEnd)
        {
            IndexNode *pCrawl = (*root)->head;

            while (pCrawl->next)
            {
                pCrawl = pCrawl->next;

                pCrawl->next = newIndexNode(index);
            }
        }
        else
        {
            (*root)->isEnd = 1;
            (*root)->head = newIndexNode(index);
        }
    }
}

void printAnagramsUtil(struct TrieNode* root,char *wordArr[])
{
    if (root == NULL)
        return;
    if (root->isEnd)
    {
        IndexNode *pCrawl = root->head;

        while (pCrawl != NULL)
        {
            cout<<wordArr[pCrawl ->index];
            pCrawl = pCrawl->next;
        }
    }

    for(int i =0; i<NO_OF_CHARS;i++){
         printAnagramsUtil(root->child[i], wordArr);
    }
}
void printAnagramsTogether(char* wordArr[], int size){
    struct TrieNode* root = NULL;

    for(int i=0;i<size;i++){
        int len = strlen(wordArr[i]);
        char *buffer = new char[len+1];
        strcpy(buffer, wordArr[i]);
        qsort( (void*)buffer, strlen(buffer), sizeof(char), compare);
        insert(&root, buffer, i);
    }

    printAnagramsUtil(root, wordArr);
}
int main()
{
    char *wordArr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}