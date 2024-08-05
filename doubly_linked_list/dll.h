#ifndef DLL_H
#define DLL_H

#include <stddef.h>
#include <stdlib.h>

#define DEFINE_DLL(T)                                                          \
  typedef struct dll_node_##T {                                                \
    struct dll_node_##T *prev;                                                 \
    T data;                                                                    \
    struct dll_node_##T *next;                                                 \
  } dll_node_##T;                                                              \
                                                                               \
  typedef struct {                                                             \
    dll_node_##T *head;                                                        \
    size_t size;                                                               \
  } dll_##T;                                                                   \
                                                                               \
  dll_##T *dll_##T##_create();                                                 \
  void dll_##T##_push_front(dll_##T *list, T value);                           \
  void dll_##T##_push_back(dll_##T *list, T value);                            \
  void dll_##T##_push_after(dll_node_##T *node, T value);                      \
  void dll_##T##_delete_node(dll_##T *list, dll_node_##T *node);               \
  void dll_##T##_delete_by_value(dll_##T *list, T value);                      \
  void dll_##T##_search(dll_##T *list, T value);                               \
  T dll_##T##_pop_front(dll_##T *list);                                        \
  T dll_##T##_pop_back(dll_##T *list);                                         \
  void dll_##T##_pop_by_value(dll_##T *list, T value);                         \
  void dll_##T##_free_list(dll_##T *list);

#endif