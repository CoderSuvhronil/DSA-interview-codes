#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL; // Head pointer for the circular linked list

// Function to create a circular linked list
void createList(int value) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) 
	{
        head = newNode;
        head->next = head;
        printf("Circular linked list created with value %d as head.\n", value);
    } 
	else 
	{
        struct Node *temp = head;
        while (temp->next != head) 
		{
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        printf("Node with value %d inserted.\n", value);
    }
}

// Function to insert a node after a specific node in the circular linked list
void insertAfter(int key, int value) 
{
    if (head == NULL) 
	{
        printf("List is empty. Cannot perform insertion.\n");
        return;
    }

    struct Node *temp = head;
    do 
	{
        if (temp->data == key) 
		{
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node with value %d inserted after node with value %d.\n", value, key);
            return;
        }
        
        temp = temp->next;
        
    } while (temp != head);

    printf("Node with value %d not found.\n", key);
}

// Function to insert a node before a specific node in the circular linked list
void insertBefore(int key, int value) 
{
    if (head == NULL) 
	{
        printf("List is empty. Cannot perform insertion.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    do {
        if (temp->data == key) 
		{
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            if (prev == NULL) 
			{
                newNode->next = head;
                while (temp->next != head) 
				{
                    temp = temp->next;
                }
                temp->next = newNode;
                head = newNode;
            } 
			else 
			{
                newNode->next = temp;
                prev->next = newNode;
            }
            printf("Node with value %d inserted before node with value %d.\n", value, key);
            return;
        }
        prev = temp;
        temp = temp->next;
        
    } while (temp != head);

    printf("Node with value %d not found.\n", key);
}

// Function to search for a node in the circular linked list
void searchNode(int value) 
{
    if (head == NULL) 
	{
        printf("List is empty. Cannot perform search.\n");
        return;
    }

    struct Node *temp = head;
    int pos = 1;
    do {
        if (temp->data == value) 
		{
            printf("Node with value %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Node with value %d not found.\n", value);
}

// Function to traverse the circular linked list
void traverseList() 
{
    if (head == NULL) 
	{
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to delete a particular node from the circular linked list
void deleteNode(int value) 
{
    if (head == NULL) 
	{
        printf("List is empty. Cannot perform deletion.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    do {
        if (temp->data == value) 
		{
            if (temp == head) 
			{
                while (temp->next != head) 
				{
                    temp = temp->next;
                }
                if (temp == head) 
				{
                    free(head);
                    head = NULL;
                } 
				else 
				{
                    temp->next = head->next;
                    free(head);
                    head = temp->next;
                }
            } 
			else 
			{
                prev->next = temp->next;
                free(temp);
            }
            printf("Node with value %d deleted successfully.\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("Node with value %d not found.\n", value);
}

int main() 
{
    int choice, value, key;

    while (1) 
	{
        printf("\nCircular Linked List Operations:\n");
        printf("1. Create List\n");
        printf("2. Insert After\n");
        printf("3. Insert Before\n");
        printf("4. Search Node\n");
        printf("5. Traverse List\n");
        printf("6. Delete Node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter the value to create the list: ");
                scanf("%d", &value);
                createList(value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the key value after which to insert: ");
                scanf("%d", &key);
                insertAfter(key, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the key value before which to insert: ");
                scanf("%d", &key);
                insertBefore(key, value);
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                searchNode(value);
                break;
            case 5:
                traverseList();
                break;
            case 6:
                printf("Enter the value of node to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 7:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

