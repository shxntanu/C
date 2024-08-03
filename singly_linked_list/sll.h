#ifndef SLL_H
#define SLL_H

#include <stddef.h>

#define DEFINE_SLL(T)                                                          \
  /**                                                                          \
   * Initialize a linked-list node of type T                                   \
   */                                                                          \
  typedef sll_node_##T {                                                       \
    \ T data;                                                                  \
    struct sll_node_##T *next                                                  \
  }                                                                            \
  sll_node_##T;                                                                \
                                                                               \
  /**                                                                          \
   * Initialize a Singly Linked List with data type T                          \
   */                                                                          \
  typedef struct {                                                             \
    sll_node_##T *head;                                                        \
    size_t size;                                                               \
  } sll_##T;                                                                   \
                                                                               \
  sll_##T *sll_##T##_create();                                                 \
  void sll_##T##_push_front(sll_##T *list, T value);                           \
  T slist_##T##_pop_front(slist_##T *list);                                    \
  void slist_##T##_free(slist_##T *list);                                      \
  size_t slist_##T##_size(slist_##T *list);                                    \
  int slist_##T##_is_empty(slist_##T *list);

#endif // SLL_H