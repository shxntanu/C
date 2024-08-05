#include "dll.h"
#include <stdlib.h>

#define MAX_INPUT 100

#define IMPLEMENT_DLL(T)                                                       \
  dll_##T *dll_##T##_create() {                                                \
    dll_##T *list = (dll_##T *)malloc(sizeof(dll_##T));                        \
    if (list) {                                                                \
      list->head = NULL;                                                       \
      list->size = 0;                                                          \
    }                                                                          \
    return list;                                                               \
  }                                                                            \
  \               
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

DEFINE_DLL(int)
