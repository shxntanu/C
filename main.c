#include "singly_linked_list/sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

void print_menu() {
  printf("\nData Structures CLI\n");
  printf("1. Singly Linked List\n");
  printf("0. Exit\n");
  printf("Enter your choice: ");
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
      printf("Thank you for using Data Structures CLI. Goodbye!\n");
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}