#include <stdio.h>
#define MAX_SIZE 5 

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() 
{
    return (front == -1 && rear == -1);
}

// Function to check if the queue is full
int isFull() 
{
    return ((rear + 1) % MAX_SIZE == front);
}

// Function to enqueue an element into the circular queue
void enqueue(int value) 
{
    if (isFull()) 
	{
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
	else if (isEmpty()) 
	{
        front = rear = 0;
    }
	else 
	{
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Function to dequeue an element from the circular queue
void dequeue() 
{
    if (isEmpty()) 
	{
        printf("Queue is empty. Cannot dequeue element.\n");
        return;
    }
	else if (front == rear) 
	{
        printf("%d dequeued from the queue.\n", queue[front]);
        front = rear = -1;
    }
	else 
	{
        printf("%d dequeued from the queue.\n", queue[front]);
        front = (front + 1) % MAX_SIZE;
    }
}

// Function to display the elements in the circular queue
void display() 
{
    if (isEmpty()) 
	{
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    printf("Circular Queue: ");
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() 
{
    int choice, value;

    while (1) 
	{
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

