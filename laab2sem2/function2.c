#include "funct2.h"
#define SIZE 32


void pushBack(SinglyLinkedList* list,const char* text, int len, int count) {
    Node* ptr = (Node*)malloc( sizeof(Node));
    ptr->count = count;
    ptr->len = len;
    if (len > 0) {
        ptr->text = (char*)malloc((ptr->len+1) * sizeof(char));
        strcpy(ptr->text, text);
    } else {
        ptr->text = NULL;
    }

    if (list->head == NULL) {
        ptr->next = NULL;
        list->head = ptr;
        list->tail = ptr;
        list->sizes++;
    }
    else {
        ptr->next = NULL;
        list->tail->next = ptr;
        list->tail = ptr;
        list->sizes++;
    }
}

int profit(SinglyLinkedList* list, int popular, int rare) {
    int lenA = at(list, popular)->len;
    int lenB = at(list, rare)->len;
    int countA = at(list, popular)->count;
    int countB = at(list, rare)->count;

    if (lenA * countA + lenB * countB - lenA * countB - lenB * countA-lenB-lenA>0) {
        return 1;
    } else {
        return 0;
    }
}


Node* at(SinglyLinkedList* list, int index) { //извлекает узел по заданному индексу в связанном списке
    if (index < 0 || index >= list->sizes) {
        return NULL;
    }
    if (index == list->sizes - 1) {
        return list->tail;
    }
    Node* current = list->head;

    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

void singlyListInfo(SinglyLinkedList* list)
{
    Node* temp;
    temp = list->head;
    while (temp != NULL) {
        printf("Replacements: %d Lengths: %d Word: %s\n", temp->count, temp->len, temp->text);
        temp = temp->next;
    }
}

int checkIndex(SinglyLinkedList* list,const char* compWord) //возвращаем индекс
{
    if (list != NULL && list->head != NULL) {
        Node* ptr;
        ptr = list->head;
        int i = 0;
        while (ptr != NULL) {
            if (strcmp(ptr->text, compWord) == 0) {
                return i;
            }
            ptr = ptr->next;
            i++;
        }
    }
    return -1;
}



void addWordInStruct(FILE* file, SinglyLinkedList* list) {
    char* word = (char*)calloc(SIZE, sizeof(char));

    while (fscanf(file, "%32s", word) == 1) {

        int index;
        if ((index = checkIndex(list, word)) == -1) {
            pushBack(list, word, (int)strlen(word), 1);
        }
        else {
            at(list, index)->count++;
        }
    }

    free(word);
}

void printCompressFile(FILE* file,FILE* compressedFile, char** wordsA, char** wordsB, int numReplacements) {
    int size = 16;
    char *word = (char *) calloc(size, sizeof(char));

    while (fscanf(file, "%16s", word) == 1) {
        int found = 0;
        for (int i = 0; i < numReplacements; i++) {
            if (strcmp(word, wordsA[i]) == 0) {
                fprintf(compressedFile, "%s ", wordsB[i]);
                found = 1;
                break;
            } else if (strcmp(word, wordsB[i]) == 0) {
                fprintf(compressedFile, "%s ", wordsA[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            fprintf(compressedFile, "%s ", word);
        }
    }
    free(word);
}

int mostPopularWord(SinglyLinkedList* list, int wordsCount) {
    int mostPopularIndex = -1;
    int maxLenCount = -1;
    for (int i = 0; i < wordsCount; i++) {
        if(at(list,i)->len >=4) {
            int lenCount = at(list, i)->len * at(list, i)->count;
            if (lenCount > maxLenCount) {
                maxLenCount = lenCount;
                mostPopularIndex = i;
            }
        }
    }
    return mostPopularIndex;
}

int mostUnpopularWord(SinglyLinkedList* list, int wordsCount) {
    int mostUnpopularIndex = -1;
    int minLenCount = 100;
    for (int i = 0; i < wordsCount; i++) {
        if(at(list,i)->len<4) {
            int lenCount = at(list, i)->len * at(list, i)->count;
            if (lenCount < minLenCount) {
                minLenCount = lenCount;
                mostUnpopularIndex = i;
            }
        }
    }
    return mostUnpopularIndex;
}


void eraseNode(SinglyLinkedList*list,const char *wordRemove) {
    Node* nodeRemove = list->head;
    Node* prevNode = NULL;

    while (nodeRemove != NULL) {
        if (strcmp(nodeRemove->text, wordRemove) == 0) {
            if (prevNode == NULL) {
                list->head = nodeRemove->next;
            } else {
                prevNode->next = nodeRemove->next;
            }
            free(nodeRemove->text);
            free(nodeRemove);
            list->sizes--;
            return;
        }
        prevNode = nodeRemove;
        nodeRemove = nodeRemove->next;
    }
}

void printCouple(FILE* compressFile, char** wordA, char** wordB,int num) {
    for(int i = 0;i<num;i++) {
        fprintf(compressFile, "$%s$%s", wordA[i], wordB[i]);
    }
    fprintf(compressFile,"\n");
}

void freeList(SinglyLinkedList* list)
{
    Node* current = list->head;
    while(current!=NULL)
    {
        Node* temp = current;
        current = current->next;
        free(temp->text);
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->sizes = 0;
}
