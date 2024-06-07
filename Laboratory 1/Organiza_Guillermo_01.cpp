/* A program for linked list implementation
	Written by: Trixie Nicole Organiza & Roslyn Faith Guillermo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Structure for a node in the linked list
struct itemNode {
    char item[100];
    struct itemNode *next;
};

// Function prototypes
struct itemNode* NEWNODE (char item[]);
int LISTLENGTH (struct itemNode* head);
struct itemNode* INSERT (char item[], int position, struct itemNode* head);
int toAdd(struct itemNode** head);
void toDisplay(struct itemNode* head);
void saveFile(struct itemNode *head);
void loadFile(struct itemNode** head);
void toExit();
void displayMenu();
struct itemNode* itemDelete(struct itemNode* head);
void destroyList(struct itemNode** head);

int main () {
    struct itemNode* head = NULL; // Initialize the head pointer to NULL
    int choice;
    int position;

    // Load data from file into the linked list
    loadFile(&head);
    
    // Main menu loop
    do {
        displayMenu(); // Display menu options
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                position = toAdd(&head); // Add item to the list
                printf("A new item is inserted at position %d.\n", position);
                saveFile(head); // Save the updated list to file
                toExit(); // Ask user if they want to exit
                break;
            case 2:
    			head = itemDelete(head); // Delete item from the list and update head
    			toExit();
    			break;
            case 3:
                toDisplay(head); // Display the items in the list
                toExit();
                break;
            case 4:
                destroyList(&head); // Delete the entire list
                toExit();
                break;
            case 0:
                exit(0); // Exit the program
                break;
            default:
                printf("Invalid choice. Please try again.\n"); // Prompt when the user inputs an invalid choice
                break;
        }

    } while (choice != 0);

    return 0;
}

// Displays the menu options
void displayMenu(){
    printf("\nLIST MENU");
    printf("\n[1] Add Item\n[2] Delete Item \n[3] Display List\n[4] Delete List\n[0] Exit program");
}

// Creates a new node
struct itemNode *NEWNODE (char item[]){
    struct itemNode* newValue = (struct itemNode*)malloc(sizeof(struct itemNode));
    
    if(newValue == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Copy the value of item to the struct member named item
    strcpy(newValue->item, item);

    // Set the next member of newValue to NULL
    newValue->next = NULL;

    return newValue;
}

// Measures the length of the list
int LISTLENGTH (struct itemNode* head) {
    int length = 0;

    while (head != NULL){
        length++;
        head = head->next;
    }

    return length;
}

// Inserts items into the list
struct itemNode* INSERT(char item[], int position, struct itemNode* head) {
    struct itemNode* insertedNode = NEWNODE(item);
    int length = LISTLENGTH(head);

    if (position < 1) {
        printf("\nERROR: Invalid position!");
        printf("\nYou can only insert items at positions greater than 0");
        return head;
    }
    else if (position == 1) {
        // Insert at the start of the list
        insertedNode->next = head;
        head = insertedNode;
    }
    else if (position > length) {
        // Insert at the end of the list
        struct itemNode* lastNode = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = insertedNode;
    }
    else {
        // Insert at specific position
        struct itemNode* before = head;
        for (int i = 1; i < position - 1; i++) {
            before = before->next;
        }
        insertedNode->next = before->next;
        before->next = insertedNode;
    }

    return head;
}

// Displays items in the list
void toDisplay(struct itemNode* head) {
    int position = 1;
    struct itemNode* current = head; // Use a separate pointer to traverse the list

    printf("\nLIST CONTENT:");

    while (current != NULL) {
        printf("\nPOSITION %d - [%s]", position, current->item);
        current = current->next;
        position++;
    }

    printf("\n");
}

// Adds items to the list
int toAdd(struct itemNode** head) {
    char input[100];
    int option, position;

    printf("\nWhat item do you want to add?\nINPUT: ");
    scanf("%s", input);

    printf("\nWhere to add the item?");
    printf("\n[1] Start of the list\n[2] End of the list\n[3] Specific position\n[0] Cancel");
    printf("\nEnter choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            // Adding item to the start of the list
            *head = INSERT(input, 1, *head);
            position = 1;
            break;

        case 2:
            // Adding item to the end of the list
            *head = INSERT(input, LISTLENGTH(*head) + 1, *head);
            position = LISTLENGTH(*head);
            break;

        case 3:
            // Adding item to a specific position
            printf("\nEnter the position where you want to add the item: ");
            scanf("%d", &position);
            if (position < 1) {
                printf("Invalid position. Item will be added to the end of the list.\n");
                position = LISTLENGTH(*head) + 1;
            }
            else if (position > LISTLENGTH(*head) + 1) {
                printf("Position exceeds list length. Item will be added to the end of the list.\n");
                position = LISTLENGTH(*head) + 1;
            }
            *head = INSERT(input, position, *head);
            break;

        case 0:
            printf("Add operation canceled.\n");
            position = -1; // Indicate cancellation
            break;

        default:
            printf("Invalid option. Item will not be added.\n");
            position = -1; // Indicate failure
            break;
    }

    return position;
}

// Saves the list to a file
void saveFile(struct itemNode *head){
    FILE *list = fopen("itemlist.txt", "w");
    int indexCtr;
    struct itemNode *currentNode = head;

    if(list == NULL){
        printf("Error.");
        return;
    }

    while (currentNode != NULL){
        fprintf(list, "%s\n", currentNode->item);
        currentNode = currentNode->next;
    }

    fclose(list);
}

// Loads data from file into the list
void loadFile(struct itemNode** head){
    FILE *list = fopen("itemlist.txt", "r");
    char input[100];

    if(list == NULL){
        return;
    }

    while (fgets(input, sizeof(input), list) != NULL) {
        // Remove the trailing newline character from the input
        input[strcspn(input, "\n")] = '\0';

        // Insert the item from the file into the linked list
        *head = INSERT(input, LISTLENGTH(*head) + 1, *head);
    }

    fclose(list);
}

// Exits the program or return to the main menu
void toExit(){
    int choice;
    printf("\nDo you want to close the program?");
    printf("\n[1]YES\n[2]NO. Return to main menu.\nCHOICE: ");
    scanf("%d", &choice);
    if(choice == 1) {
        exit(0);
    } else {
        return;
    }
}

// Deletes an item from the list
struct itemNode* itemDelete(struct itemNode* head) {
    char item_delete[100]; // Assuming the item is a string
    struct itemNode* tempNode = head, *prevNode = NULL;
    int position = 1; // Initialize position counter

    printf("\nEnter the item you want to delete: ");
    scanf("%s", item_delete);

    while (tempNode != NULL) {
        // Compare the current item with the item to be deleted
        if (strcmp(tempNode->item, item_delete) == 0) {
            printf("\nThe element %s, which is at position %d, has been deleted.\n", tempNode->item, position);

            // If the item to be deleted is found at the head of the list
            if (prevNode == NULL) {
                head = head->next; // Update head to the next node
                free(tempNode); // Free the memory of the deleted node
                saveFile(head); // Save the updated list to file
                
                // If the list becomes empty, set head to NULL
                if (head == NULL) {
                    printf("\nThe list is now empty.\n");
                }
                
                return head;    // Return the updated head pointer
            } else {
                // Remove the item by adjusting pointers
                prevNode->next = tempNode->next;
                free(tempNode);
                saveFile(head);
                return head;
            }
        }

        // Update the pointers to move forward in the linked list
        prevNode = tempNode;
        tempNode = tempNode->next;
        position++;
    }
    
    printf("\nThe list contains no such element.\n"); // If the item to be deleted is not found in the list
    return head;
}

// Deletes the entire list and clears the contents of the file
void destroyList(struct itemNode** headPtr) {
    struct itemNode* current = *headPtr; // Initialize a pointer to the current node
    struct itemNode* next; // Initialize a pointer to the next node

    // Navigate across the list and free memory for each node
    while (current != NULL) {
        next = current->next; // Store the next node pointer
        free(current);
        current = next; // Move to the next node
    }

    *headPtr = NULL; // Update the head pointer to null to indicate an empty list

    // Open the file for writing (clear its contents)
    FILE* file = fopen("itemlist.txt", "w");
    if (file != NULL) {
        fclose(file);
        printf("\nThe list has been emptied!\n");
    } else {
        printf("\nError opening file for writing.\n");
    }
}
