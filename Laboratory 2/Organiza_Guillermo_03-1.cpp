/* A program that demonstrates the kitchenware washing machine 
   process using stack implementation and application
   Written by: Trixie Nicole Organiza & Roslyn Faith Guillermo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 10 // Constant maximum stack size

// Structure for a node in the stack
struct node {
    char kitchenware[100];  // Stores the name of the kitchenware in the node
    struct node* next;  // Pointer to the next node in the stack
};

// Function prototypes
void displayMenu();
void Add_Kitchenware(struct node** S);
void Wash_Kitchenware(struct node **S);
void Top_Kitchenware(struct node *S);
void Wash_All_Kitchenware(struct node **S);
void Push(char x[], struct node** S);
struct node* Pop(struct node **S);
int is_Full(struct node* S);
int is_Empty(struct node *S);
struct node* Top(struct node *S);
void makeNull(struct node **S);


// This program accepts character strings even with whitespaces

int main() {
    struct node* S = NULL;  // Initialize the stack
    int choice;

    do {
        displayMenu();
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // Clear input buffer and reads input until it encounters a new line

        switch (choice) {
            case 1:
                Add_Kitchenware(&S);
                break;
            case 2:
                Wash_Kitchenware(&S);
                break;
            case 3:
                Top_Kitchenware(S);
                break;
            case 4:
                Wash_All_Kitchenware(&S);
                break;
            case 0:
                printf("\nThe washing machine process has been terminated. Exiting...\n"); // The program is terminated
                break;
            default:
                printf("\nERROR: Invalid choice. Please try again.\n"); 
                break;
        }

    } while (choice != 0);
    
    makeNull(&S); // Free memory before termination
    
    return 0;
}

// Function to display the main menu
void displayMenu(){
    printf("\nKitchenware Washing Machine\n");
    printf("\n[1] Add kitchenware\n[2] Wash kitchenware \n[3] Top kitchenware\n[4] Wash all\n[0] Exit");
}

// Function to add kitchenware to the stack
void Add_Kitchenware(struct node** S){
    if(!is_Full(*S)){
        char x[100];
        printf("\nEnter kitchenware that needs to be washed: ");
        
        // Loop until valid input is provided
        while (1) {
            fgets(x, sizeof(x), stdin);
            x[strcspn(x, "\n")] = '\0'; // Removes newline character
            
            // Check if input contains only characters and not integers
            int valid = 1;
            for (int i = 0; x[i] != '\0'; i++) {
                if (!isalpha(x[i]) && !isspace(x[i])) {
                    valid = 0;
                    break;
                }
            }
            
            if (valid) {
                Push(x, S); // Adds kitchenware to the stack by pushing item x at the top of the stack 
                printf("\n[%s] has been added to the kitchenware to be washed.\n");
                break; // Exits the loop
            } else {
                printf("Invalid input. Enter kitchenware that needs to be washed: ");
            }
        }
    } else {
        printf("The STACK is FULL. Cannot add kitchenware.\n"); // Prompts when the stack reached the maximum stack size
    }
}

// Function to wash the top kitchenware from the stack
void Wash_Kitchenware(struct node **S){
    if(!is_Empty(*S)){
        struct node* sink = Pop(S);
        printf("[%s] is being washed.\n", sink->kitchenware);
        free(sink);
    } else{
        printf("\nThe STACK is EMPTY. No more kitchenware to wash.\n");
    }
}

// Function to display the top kitchenware from the stack
void Top_Kitchenware(struct node *S){
    if(!is_Empty(S)){
        printf("[%s] is next to be washed.\n", Top(S)->kitchenware);
    } else {
        printf("The STACK is EMPTY. No kitchenware to wash.\n");
    }
}

// Function to wash all kitchenware from the stack
void Wash_All_Kitchenware(struct node **S){
    if(!is_Empty(*S)){
        while(!is_Empty(*S)){
            Wash_Kitchenware(S);
        }
        printf("\nAll kitchenware has been washed.\n");
    } else {
        printf("The STACK is EMPTY. No kitchenware to wash.\n");
    }
}

// Function to push kitchenware onto the stack
void Push(char x[], struct node** S) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed.");
        exit(EXIT_FAILURE);
    } 
        
    strcpy(newNode->kitchenware, x);
    newNode->next = *S;
    *S = newNode;
}

// Function to remove and return the top kitchenware of the stack S
struct node* Pop(struct node **S) {
    if(is_Empty(*S)){
        printf("Stack is empty.");
        return NULL;
    }
    struct node* temp = *S;
    *S = (*S)->next;
    temp->next = NULL;
    return temp;
}

// Function to check if the stack is full
int is_Full(struct node* S){
    int count = 0;
    struct node* tempCont = S;
    while(tempCont != NULL) {
        count++;
        tempCont = tempCont->next;
    }

    return count >= MAX_STACK_SIZE;
}

// Function to check if the stack is empty
int is_Empty(struct node *S){
    return (S == NULL);
}

// Function to get the top element of the stack
struct node* Top(struct node *S){
    if(!is_Empty(S))
        return S;
    return NULL;
}

// Function to make the stack empty
void makeNull(struct node **S){
    while(!is_Empty(*S)){
        struct node* temp = *S;
        *S = (*S)->next;
        free(temp);
    }
}
