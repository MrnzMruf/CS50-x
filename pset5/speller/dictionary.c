#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

const unsigned int TABLE_SIZE = 50000;

node *table[TABLE_SIZE];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //returns true if found else return false.
    int index = hash(word);
    //make a cursor node which points to the head of the hash table
    node *cursor = table[index];
    //for loop to go through the list until the final node is reached.
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
      if (strcasecmp(temp->word,word) == 0)
        {
            return true;
        }
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    //for  this hash get the lengh of the string then we will sum the value of the characters.
    unsigned int hashvalue = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashvalue += tolower(word[i]);
        hashvalue = (hashvalue * tolower(word[i])) % TABLE_SIZE;
    }
    return hashvalue;
}

int counter = 0;

bool load(const char *dictionary)
{
    // OPEN DICTIONARY FILE and read the contents.
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "There has been an error");
        return false;
    }

    //wordlist is a character array of the words.
    char wordlist[LENGTH + 1];
    //while fscanf != EOF print the words into the character array word
    while (fscanf(file, "%s", wordlist) != EOF)
    {
        //Keep track of how many nodes are being made
        counter++;
        //for each new node allocate memory.
        node *newNode = malloc(sizeof(node));
        //check for null
        if (newNode == NULL)
        {
            return 1;
        }
        //initialize the new node by copying the word to the next node.
        strcpy(newNode->word, wordlist);
        newNode->next = NULL;
        //add to hash table each element of the hashtable is a linked list!
        //if index != NULL newNode->word points to the old head of the list
        int index = hash(wordlist);
        //if the index is not yet assigned, put the newest node at the head of this index.
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        //if the index is assigned point the existing head node at the table[index] and then make the new node the head.
        else
        {
            //makes the next the new head
            newNode->next = table[index];
            //head points to the new node.
            table[index] = newNode;
        }
    }
    fclose(file);
    return true;
}


unsigned int size(void)
{
    return counter;
}


bool unload(void)
{
    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
           tmp = cursor;
            cursor = cursor->next;
           free(tmp);
        }
    }
    return true;
}
