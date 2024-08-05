#ifndef SLL_H
#define SLL_H

#include <stddef.h>

// Define a macro for creating a type-generic singly linked list
#define DEFINE_SLL(T)                                                          \
  typedef struct sll_node_##T {                                                \
    T data;                                                                    \
    struct sll_node_##T *next;                                                 \
  } sll_node_##T;                                                              \
                                                                               \
  typedef struct {                                                             \
    sll_node_##T *head;                                                        \
    size_t size;                                                               \
  } sll_##T;                                                                   \
                                                                               \
  sll_##T *sll_##T##_create();                                                 \
  void sll_##T##_push_front(sll_##T *list, T value);                           \
  T sll_##T##_pop_front(sll_##T *list);                                        \
  void sll_##T##_free(sll_##T *list);                                          \
  size_t sll_##T##_size(sll_##T *list);                                        \
  int sll_##T##_is_empty(sll_##T *list);

void sll_int_menu();

#endif // SLL_H