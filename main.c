#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Data Structure: Represents a Driver ---
struct Node { 
    char driverName[50];
    struct Node *next;
};

// --- Global Pointer: Tracks the first/next driver ---
struct Node *start = NULL; 

// --- Function Prototypes ---
void addDriver(char* name);
void removeDriver(char* name);
void assignNextRide();
void showQueue();

// --- Main Program: The User Interface ---
int main() {
    int choice;
    char nameInput[50];

    printf("===================================\n");
    printf("--- Driver Dispatch System ---\n");
    printf("===================================\n");

    do {
        printf("\n--- What would you like to do? ---\n");
        printf("1. Add a Driver\n");
        printf("2. Assign the Next Ride\n");
        printf("3. Show the Driver Queue\n");
        printf("4. Remove a Driver\n");
        printf("5. Exit Program\n");
        printf("\nEnter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Oops! Please enter a number between 1 and 5.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                printf("\n--- Adding a Driver ---\n");
                printf("  Enter Driver's Name (one word): ");
                scanf("%s", nameInput);
                addDriver(nameInput);
                break;
            case 2:
                printf("\n--- Assigning Next Ride ---\n");
                assignNextRide();
                break;
            case 3:
                printf("\n--- Current Driver Queue ---\n");
                showQueue();
                break;
            case 4:
                printf("\n--- Removing a Driver ---\n");
                printf("  Enter Driver's Name to remove: ");
                scanf("%s", nameInput);
                removeDriver(nameInput);
                break;
            case 5:
                printf("\nOkay, shutting down. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please pick a number from 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}

// --- Function Definitions ---

// Adds a new driver to the end of the line
void addDriver(char* name) {
    // Create the new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->driverName, name);

    // If the list is empty
    if (start == NULL) {
        start = newNode;
        newNode->next = start; 
    }
    // If the list has drivers already
    else {
        // Find the last node (the one pointing back to start)
        struct Node *current = start;
        while (current->next != start) {
            current = current->next;
        }
        // Link the last node to the new node
        current->next = newNode;
        // Link the new node back to the start
        newNode->next = start;
    }

    printf(" Driver added!\n");
}


// Removes a specific driver from the queue by name
void removeDriver(char* name) {
    if (start == NULL) {
        printf("  -> The driver queue is already empty.\n");
        return;
    }

    struct Node *current = start;
    struct Node *previous = NULL;
    struct Node *last = start; 

    // Find the actual last node
    while (last->next != start) {
        last = last->next;
    }

    // Search for the node to remove
    do {
        if (strcmp(current->driverName, name) == 0) {
            break;
        }
        previous = current;
        current = current->next;
    } while (current != start); 
    if (strcmp(current->driverName, name) != 0) {
        printf("  -> Sorry, couldn't find Driver %s in the queue.\n", name);
        return;
    }

    // --- Remove the node ---

    // Case 1: Removing the only node
    if (current == start && current->next == start) {
        start = NULL; // List becomes empty
    }
    // Case 2: Removing the 'start' node (first node)
    else if (current == start) {
        last->next = start->next;
        start = start->next;    
    }
    // Case 3: Removing a node in the middle or the end
    else {
        previous->next = current->next; //
    }

    // Free the memory of the removed node
    free(current);
    printf("  -> Driver %s was successfully removed.\n", name);
}


// Assigns the ride to the next driver and moves the pointer
void assignNextRide() {
    if (start == NULL) {
        printf("  -> No drivers available right now.\n");
        return;
    }

    printf(" Ride assigned to: %s\n", start->driverName);

    // Move 'start' to the next driver in the circle
    start = start->next;
}


// Shows the current order of drivers in the queue as a numbered list
void showQueue() {
    if (start == NULL) {
        printf("  -> The driver queue is currently empty.\n");
        return;
    }

    struct Node *current = start;
    int count = 1;

    // Loop through the circle and print each driver with a number
    do {
        printf("  %d) %s\n", count, current->driverName);
        current = current->next;
        count++;
    } while (current != start); // Stop when we return to the start
}

