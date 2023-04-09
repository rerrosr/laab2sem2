#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funct2.h"

int main() {
    FILE* file;

    SinglyLinkedList* list;
    list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));

    list->head = NULL;
    list->sizes = 0;

    if ((file = fopen("D:/CLionProjects/laab2sem2/file.txt", "r")) == NULL) {
        printf("Error\n");
        exit(1);
    }
    addWordInStruct(file, list);


    fclose(file);

    singlyListInfo(list);
    FILE *compressedFile;

    if ((file = fopen("D:/CLionProjects/laab2sem2/file.txt", "r")) == NULL) {
        printf("Error\n");
        exit(1);
    }

    if ((compressedFile = fopen("D:/CLionProjects/laab2sem2/compress.txt", "w")) == NULL) {
        printf("Error\n");
        exit(1);
    }

    int numSwap = 0;
    char **wordsA = (char **) malloc(list->sizes * sizeof(char *));
    char **wordsB = (char **) malloc(list->sizes * sizeof(char *));
    while (1) {
        int indexPop = mostPopularWord(list, (int) list->sizes);
        int indexRare = mostUnpopularWord(list, (int) list->sizes);

        if (profit(list, indexPop, indexRare) == 1) {
            char *wordA = (char *) malloc(at(list, indexPop)->len * sizeof(char));
            char *wordB = (char *) malloc(at(list, indexRare)->len * sizeof(char));
            strcpy(wordA, at(list, indexPop)->text);
            strcpy(wordB, at(list, indexRare)->text);
            wordsA[numSwap] = wordA;
            wordsB[numSwap] = wordB;
            numSwap++;
            eraseNode(list, wordA);
            eraseNode(list, wordB);
        } else {
            break;
        }
    }

    freeList(list);


    printCouple(compressedFile,wordsA,wordsB,numSwap);

    printCompressFile(file,compressedFile, wordsA, wordsB, numSwap);

    fclose(file);
    fclose(compressedFile);
    return 0;
}
