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
void printCompressFile(FILE*,FILE*, char**, char**,int);
int mostPopularWord(SinglyLinkedList*, int);
int mostUnpopularWord(SinglyLinkedList*, int);
void printSestertius(FILE*, char**, char**,int);
Node* at(SinglyLinkedList*,int);
void pushBack(SinglyLinkedList*,const char*,int,int);
void eraseNode(SinglyLinkedList*,const char *);
int profit(SinglyLinkedList*,int,int);

#endif LAAB2SEM2_FUNCT2_H


