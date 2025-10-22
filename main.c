#include <stdio.h>
#include <stdlib.h> 
#include <string.h> // Required for strcpy() and strcmp()

// --- 1. Data Structure Definition ---
struct node {
    char driverName[50]; 
    struct node *next;
};

// --- 2. Global Pointer ---
struct node *start = NULL; 


// --- 3. Function Prototypes ---
void insert_end(char* name);
void deleteDriver(char* name); 
void assignRide();
void display();


// --- 4. Main Program (The Menu) ---
int main() {
    int option;
    char nameInput[50]; 

    printf("===================================\n");
    printf("--- Driver Dispatch System ---\n");
    printf("===================================\n");

    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Add Driver to Queue\n");
        printf("2. Assign Next Ride\n");
        printf("3. Display Driver Queue\n");
        printf("4. Remove Driver from Queue\n");
        printf("5. Exit\n");
        printf("\nEnter your option: ");
        
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            option = 0; 
            continue;
        }
        
        switch (option) {
            case 1:
                printf("\n--- Add Driver ---\n");
                printf("  Enter Driver Name (one word): ");
                scanf("%s", nameInput); 
                insert_end(nameInput);  
                break;
            case 2:
                printf("\n--- Assign Next Ride ---\n");
                assignRide();
                break;
            case 3:
                printf("\n--- Display Driver Queue ---\n");
                display();
                break;
            case 4: 
                printf("\n--- Remove Driver ---\n");
                printf("  Enter Driver Name to remove: ");
                scanf("%s", nameInput); 
                deleteDriver(nameInput); 
                break;
            case 5: 
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
    } while (option != 5); 

    return 0;
}


// --- 5. Function Definitions ---

void insert_end(char* name) {
    struct node *new_node, *ptr;
    
    new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->driverName, name); 

    if (start == NULL) {
        start = new_node;
        new_node->next = start;
    } 
    else {
        ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next; 
        }
        
        ptr->next = new_node;
        new_node->next = start;
    }
    
    printf("  -> Driver %s added to the queue.\n", name);
}


void deleteDriver(char* name) {
    if (start == NULL) {
        printf("  -> Cannot remove driver: The queue is empty.\n");
        return;
    }

    struct node *current = start;
    struct node *previous = NULL;
    struct node *last = start;

    while (last->next != start) {
        last = last->next;
    }

    do {
        if (strcmp(current->driverName, name) == 0) {
            break; 
        }
        previous = current;
        current = current->next;
    } while (current != start); 

    if (strcmp(current->driverName, name) != 0) {
        printf("  -> Driver %s not found in the queue.\n", name);
        return;
    }

    if (current == start && current->next == start) {
        start = NULL; 
        free(current);
    }
    else if (current == start) {
        last->next = start->next; 
        start = start->next;      
        free(current);            
    }
    else {
        previous->next = current->next; 
        free(current);                  
    }

    printf("  -> Driver %s was successfully removed from the queue.\n", name);
}


void assignRide() {
    if (start == NULL) {
        printf("  -> No drivers available to assign a ride.\n");
        return; 
    }

    printf("  -> RIDE ASSIGNED TO: Driver %s\n", start->driverName);

    start = start->next;
    
    printf("  -> Pointer moved. Next driver in line is: Driver %s\n", start->driverName);
}


void display() {
    if (start == NULL) {
        // Print nothing if the queue is empty
        return;
    }

    struct node *ptr = start;
    
    printf("  "); // Indent for alignment
    
    do {
        printf("%s", ptr->driverName);
        ptr = ptr->next;
        // Only print arrow if it's not the last node
        if (ptr != start) {
            printf(" -> "); 
        }
    } while (ptr != start); 

    printf("\n"); // End the line
}