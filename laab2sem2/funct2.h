#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef LAAB2SEM2_FUNCT2_H
#define LAAB2SEM2_FUNCT2_H


typedef struct Node {
    char* text;
    int count;
    int len;
    struct Node* next;
} Node;

typedef struct SinglyLinkedList{
    size_t sizes;
    Node* head;
    Node* tail;
} SinglyLinkedList;

void singlyListInfo(SinglyLinkedList*);
int checkIndex(SinglyLinkedList*,const char*);
void addInfo(FILE*, SinglyLinkedList *);
void printCompressedFile(FILE*,FILE*, char**, char**,int);
int mostPopularWord(SinglyLinkedList*, int);
int mostUnpopularWord(SinglyLinkedList*, int);
void printSestertius(FILE*, char**, char**,int);
Node* at(SinglyLinkedList*,int);
void pushBack(SinglyLinkedList*,const char*,int,int);
void eraseNode(SinglyLinkedList*,const char *);
int profit(SinglyLinkedList*,int,int);

#endif LAAB2SEM2_FUNCT2_H
//typedef struct NodeWord {
//    int count;
//    char word[100];
//    struct NodeWord *next;
//    struct NodeWord *prev;
//}  NodeWord;
//Структура для представления узла связного списка
//typedef struct Node {
//    int size;
//    struct NodeWord *head;
//    struct NodeWord *tail;
//} Node ;
//void add_word(struct Node *node, const char *buffer);
//void print(Node *node);
//int is_word_character(char c);
//void add_word(Node **queue, char *word);
//void print_queue(Node *queue);
//Node *find_most_popular_long_word(Node *queue, int min_length);
//Node *find_least_popular_short_word(Node *queue, int max_length);
//void compress(Node *queue, int min_length, int max_length, char *input_filename, char *output_filename);
//void decompress(Node *queue, int min_length, int max_length, char *input_filename, char *output_filename);

