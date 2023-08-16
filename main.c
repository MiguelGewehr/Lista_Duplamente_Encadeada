#include "list.h"
#include <stdio.h>

int main() {
    List *myList = list_construct();

    // Testando list_push_back
    for (int i = 1; i <= 50; i++) {
        list_push_back(myList, i);
    }

    // Testando list_pop_back
    printf("Removendo elementos com list_pop_back:\n");
    while (!isEmpty(myList)) {
        printf("Popped element from back: %d\n", list_pop_back(myList));
    }

    // Recriando a lista para realizar o teste com list_pop_front
    for (int i = 1; i <= 50; i++) {
        list_push_back(myList, i);
    }

    // Testando list_pop_front
    printf("\nRemovendo elementos com list_pop_front:\n");
    while (!isEmpty(myList)) {
        printf("Popped element from front: %d\n", list_pop_front(myList));
    }

    list_destroy(myList);
    return 0;
}
