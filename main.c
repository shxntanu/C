#include "singly_linked_list/sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

DEFINE_SLL(int)
IMPLEMENT_SLL(int)

void print_menu() {
  printf("\nGeneric Data Structures CLI\n");
  printf("1. Singly Linked List\n");
  printf("0. Exit\n");
  printf("Enter your choice: ");
}

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

int main() {
  char input[MAX_INPUT];
  int choice;

  while (1) {
    print_menu();
    fgets(input, MAX_INPUT, stdin);
    choice = atoi(input);

    switch (choice) {
    case 1:
      sll_int_menu();
      break;
    case 0:
      printf("Thank you for using Generic Data Structures CLI. Goodbye!\n");
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}