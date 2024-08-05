#include "sll.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 100

#define IMPLEMENT_SLL(T)                                                       \
  sll_##T *sll_##T##_create() {                                                \
    sll_##T *list = (sll_##T *)malloc(sizeof(sll_##T));                        \
    if (list) {                                                                \
      list->head = NULL;                                                       \
      list->size = 0;                                                          \
    }                                                                          \
    return list;                                                               \
  }                                                                            \
                                                                               \
  void sll_##T##_push_front(sll_##T *list, T value) {                          \
    sll_node_##T *new_node = (sll_node_##T *)malloc(sizeof(sll_node_##T));     \
    if (new_node) {                                                            \
      new_node->data = value;                                                  \
      new_node->next = list->head;                                             \
      list->head = new_node;                                                   \
      list->size++;                                                            \
    }                                                                          \
  }                                                                            \
                                                                               \
  T sll_##T##_pop_front(sll_##T *list) {                                       \
    if (list->head) {                                                          \
      sll_node_##T *temp = list->head;                                         \
      T value = temp->data;                                                    \
      list->head = temp->next;                                                 \
      free(temp);                                                              \
      list->size--;                                                            \
      return value;                                                            \
    }                                                                          \
    /*Empty List case */                                                       \
    return (T)0;                                                               \
  }                                                                            \
                                                                               \
  void sll_##T##_free(sll_##T *list) {                                         \
    while (list->head) {                                                       \
      sll_node_##T *temp = list->head;                                         \
      list->head = temp->next;                                                 \
      free(temp);                                                              \
    }                                                                          \
    free(list);                                                                \
  }                                                                            \
                                                                               \
  size_t sll_##T##_size(sll_##T *list) { return list->size; }                  \
                                                                               \
  int sll_##T##_is_empty(sll_##T *list) { return list->size == 0; }

DEFINE_SLL(int)
IMPLEMENT_SLL(int)

void sll_int_menu() {
  sll_int *list = sll_int_create();
  char input[MAX_INPUT];
  int choice, value;

  while (1) {
    printf("\nSingly Linked List (Int) Operations\n");
    printf("1. Push front\n");
    printf("2. Pop front\n");
    printf("3. Print size\n");
    printf("4. Check if empty\n");
    printf("0. Back to main menu\n");
    printf("Enter your choice: ");

    fgets(input, MAX_INPUT, stdin);
    choice = atoi(input);

    switch (choice) {
    case 1:
      printf("Enter value to push: ");
      fgets(input, MAX_INPUT, stdin);
      value = atoi(input);
      sll_int_push_front(list, value);
      printf("Pushed %d to the front of the list.\n", value);
      break;
    case 2:
      if (!sll_int_is_empty(list)) {
        value = sll_int_pop_front(list);
        printf("Popped %d from the front of the list.\n", value);
      } else {
        printf("The list is empty.\n");
      }
      break;
    case 3:
      printf("Size of the list: %zu\n", sll_int_size(list));
      break;
    case 4:
      printf("Is the list empty? %s\n", sll_int_is_empty(list) ? "Yes" : "No");
      break;
    case 0:
      sll_int_free(list);
      return;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }
}
