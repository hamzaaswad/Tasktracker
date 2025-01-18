#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100 // Maximum number of tasks

typedef struct {
    char description[100]; // Task description
    int is_complete;       // 0 = incomplete, 1 = complete
} Task;

Task tasks[MAX_TASKS]; // Array to store tasks
int task_count = 0;    // Keeps track of the number of tasks

// Function declarations
void display_menu();
void view_tasks();
void add_task();
void mark_task_complete();
void delete_task();

int main() {
    int choice;

    // Main loop
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');  // Clear the input buffer

        switch (choice) {
            case 1:
                view_tasks();
                break;
            case 2:
                add_task();
                break;
            case 3:
                mark_task_complete();
                break;
            case 4:
                delete_task();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display the menu
void display_menu() {
    printf("\n=== To-Do List Manager ===\n");
    printf("1. View Tasks\n");
    printf("2. Add Task\n");
    printf("3. Mark Task as Complete\n");
    printf("4. Delete Task\n");
    printf("5. Exit\n");
}

// Function to view tasks
void view_tasks() {
    if (task_count == 0) {
        printf("\nNo tasks available.\n");
        return;
    }

    printf("\n=== Task List ===\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i].description,
               tasks[i].is_complete ? "Completed" : "Incomplete");
    }
}

// Function to add a task
void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("\nTask list is full. Cannot add more tasks.\n");
        return;
    }

    char description[100];
    printf("\nEnter task description: ");
    fgets(description, sizeof(description), stdin); // Read the task description
    description[strcspn(description, "\n")] = '\0'; // Remove the newline character

    // Add the new task to the tasks array
    strcpy(tasks[task_count].description, description);
    tasks[task_count].is_complete = 0; // Task is initially incomplete
    task_count++;

    printf("\nTask added successfully!\n");
}

// Function to mark a task as complete
void mark_task_complete() {
    if (task_count == 0) {
        printf("\nNo tasks available to mark as complete.\n");
        return;
    }

    int task_number;
    printf("\nEnter task number to mark as complete: ");
    scanf("%d", &task_number);
    while (getchar() != '\n');  // Clear the input buffer

    if (task_number < 1 || task_number > task_count) {
        printf("\nInvalid task number.\n");
        return;
    }

    if (tasks[task_number - 1].is_complete == 1) {
        printf("\nTask %d is already marked as complete.\n", task_number);
    } else {
        tasks[task_number - 1].is_complete = 1; // Mark the task as complete
        printf("\nTask %d marked as complete!\n", task_number);
    }
}

// Function to delete a task
void delete_task() {
    if (task_count == 0) {
        printf("\nNo tasks available to delete.\n");
        return;
    }

    int task_number;
    printf("\nEnter task number to delete: ");
    scanf("%d", &task_number);
    while (getchar() != '\n');  // Clear the input buffer

    if (task_number < 1 || task_number > task_count) {
        printf("\nInvalid task number.\n");
        return;
    }

    // Shift tasks to delete the selected task
    for (int i = task_number - 1; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    task_count--; // Decrease task count after deletion
    printf("\nTask %d deleted successfully.\n", task_number);
}
