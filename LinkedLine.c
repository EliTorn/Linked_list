
#include "stdio.h"
#include "stdlib.h"

typedef struct item {
    char data;
    struct item *next;
} item;

item *build_char_list() {
    item *lst;
    item *cur_point;
    char c;
    if ((c = getchar()) == '\n') {
        return NULL;
    }
    lst = (item *) malloc(sizeof(item));
    cur_point = lst;
    lst->data = c;

    while ((c = getchar()) != '\n') {
        cur_point->next = (item *) malloc(sizeof(item));
        cur_point->data = c;
    }
    cur_point->next = NULL;

    return lst;
}


int main() {
    item *b;
    b = build_char_list();
    printf("%c %p", b->data, b->next);
    b = b->next;
    free(b);
    return 0;
}