#include "sll.h"
#include <stdlib.h>

/**
 * Implement a singly linked list with the given type T
 */
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
