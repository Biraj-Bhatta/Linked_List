#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void AtFirst(struct node **tail, int data)
{
    struct node *newnode = createnode(data);
    if (*tail == NULL)
    {
        *tail = newnode;
        (*tail)->next = *tail;
        (*tail)->prev = *tail;
    }
    else
    {
        newnode->next = (*tail)->next;
        newnode->prev = (*tail);
        (*tail)->next->prev = newnode;
        (*tail)->next = newnode;
    }
}
void AtLast(struct node **tail, int data)
{
    struct node *newnode = createnode(data);
    if (*tail == NULL)
    {
        *tail = newnode;
        (*tail)->next = (*tail);
        (*tail)->prev = (*tail);
    }
    else
    {
        newnode->next = (*tail)->next;
        newnode->prev = (*tail);
        (*tail)->next->prev = newnode;
        (*tail)->next = newnode;
        *tail = newnode;
    }
}
void AtNth(struct node **tail, int data)
{
    int pos;
    printf("Enter position of node to be inserted: ");
    scanf("%d", &pos);
    struct node *temp = (*tail)->next;
    struct node *newnode = createnode(data);
    for (int i = 1; i < (pos - 1); i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}
void DeleteFirst(struct node **tail)
{
    if ((*tail) == NULL)
    {
        printf("The list is empty.\n\n");
        return;
    }
    struct node *temp = (*tail)->next;
    if (temp == (*tail))
    {
        free(temp);
        (*tail) = NULL;
    }
    else
    {
        (*tail)->next = temp->next;
        temp->next->prev = (*tail);
        free(temp);
    }
}
void DeleteLast(struct node **tail)
{
    if (*tail == NULL)
    {
        printf("The list is empty.\n\n");
        return;
    }
    struct node *temp = (*tail)->next;
    if (temp == *tail)
    {
        free(temp);
        *tail = NULL;
    }
    else
    {
        struct node *temp1 = (*tail);
        (*tail)->prev->next = temp1->next;
        (*tail)->next->prev = temp1->prev;
        (*tail) = temp1->prev;
        free(temp1);
    }
}
void DeleteNth(struct node **tail)
{
    int pos;
    struct node *temp = (*tail)->next;
    if (*tail == NULL)
    {
        printf("The list is empty.\n\n");
        return;
    }
    printf("Enter the position to delete node: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        if (temp == *tail)
        {
            free(temp);
            *tail = NULL;
        }
        else
        {
            (*tail)->next = temp->next;
            temp->next->prev = (*tail);
            free(temp);
        }
    }
    for (int i = 1; i < (pos - 1); i++)
    {
        temp = temp->next;
    }
    struct node *temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;
    free(temp1);
}
void Search(struct node **tail, int search)
{
    struct node *temp = (*tail)->next;
    do
    {
        if (temp->data == search)
        {
            printf("The searched data %d is found.\n\n", search);
            return;
        }
        temp = temp->next;
    } while (temp != (*tail)->next);
    printf("The searched data %d is not found.\n\n", search);
}
void display(struct node **tail)
{
    if (*tail == NULL)
    {
        printf("The list is empty.\n\n");
        return;
    }
    struct node *temp = (*tail)->next;
    do
    {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    } while (temp != (*tail)->next);
    printf("Beigning\n\n");
}
int main()
{
    int data, choice;
    struct node *tail = NULL;
    do
    {
        printf("1. Insert at first \n");
        printf("2. Insert at Nth \n");
        printf("3. Insert at last \n");
        printf("4. Delete at first \n");
        printf("5. Delete at Nth \n");
        printf("6. Delete at last \n");
        printf("7.Search element in linked list \n");
        printf("8. Display Linked List \n");
        printf("9. Exit \n\n");
        printf("Enter choice:: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            AtFirst(&tail, data);
            break;
        case 2:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            AtNth(&tail, data);
            break;
        case 3:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            AtLast(&tail, data);
            break;
        case 4:
            DeleteFirst(&tail);
            break;
        case 5:
            DeleteNth(&tail);
            break;
        case 6:
            DeleteLast(&tail);
            break;
        case 7:
            printf("Enter data to be searched: ");
            scanf("%d", &data);
            Search(&tail, data);
            break;
        case 8:
            display(&tail);
            break;
        case 9:
            exit(1);
        default:
            printf("Invalid Input\n\n");
            break;
        }
    } while (1);
    return 0;
}