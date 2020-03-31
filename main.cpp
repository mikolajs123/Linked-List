//
//  main.cpp
//  Linked_List
//
//  Created by Mikołaj Semeniuk on 14/03/2020.
//  Copyright © 2020 Mikołaj Semeniuk. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;;

void create (int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return;
}

int count (struct Node *p)
{
    int result = 0;
    while (p != NULL) {
        result++;
        p = p->next;
    }
    return result;
}

int sum (struct Node *p)
{
    int result = 0;
    while (p != NULL) {
        result += p->data;
        p = p->next;
    }
    return result;
}

int max (struct Node *p)
{
    int result = INT32_MIN;
    while (p != NULL)
    {
        if (p->data > result)
            result = p->data;
        p = p->next;
    }
    return result;
}

int min (struct Node *p)
{
    int result = INT32_MAX;
    while (p != NULL)
    {
        if (p->data < result)
            result = p->data;
        p = p->next;
    }
    return result;
}

int linear_search (struct Node *p, int key)
{
    int pos = 0;
    while (p != NULL) {
        if (p->data == key)
            return pos;
        else
        {
            p = p->next;
            pos++;
        }
    }
    return -1;
}

void sortedInsert (struct Node *p, int x)
{
    struct Node * t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void insert (struct Node *p, int i, int x)
{
    if (i < 0 || i > count(p))
        return;
    
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    
    if (i == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int j = 0; j < i - 1; j++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void unshift(struct Node **p, int x)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = (*p);
    (*p) = new_node;
}

void append(struct Node **p, int x)
{
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *p;
    new_node->data = x;
    new_node->next = NULL;
    if (*p == NULL)
    {
        *p = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void delete_ (struct Node *p)
{
    if(p == NULL)
        return;
    if(p->next == NULL)
    {
        delete p;
        p = NULL;
        return;
    }
    Node* q = p;
    while (q->next && q->next->next != NULL)
    {
        q = q->next;
    }
    delete q->next;
    q->next = NULL;
}

void _delete (struct Node *p)
{
    if(p == NULL)
        return;
    else
    {
        struct Node *q = first;
        first = first->next;
        free(q);
        return;
    }
}

void Delete (struct Node *p, int index)
{
    struct Node *q = NULL;
    
    if (index < 0 || index > count(p))
        return;
    if (index == 0)
    {
        q = first;
        first = first->next;
        free(q);
        return;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
        return;
    }
}

void display (struct Node * p)
{
    if(p == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        while (p != NULL) {
            printf("%d\n", p->data);
            p = p->next;
        }
    }
}

int random_in_range (int min, int max)
{
    int range = (max - min) + 1;
    int result = min + rand() % range;
    return result;
}

void generate_random_array_from_range (struct Node **p, int min, int max, int n)
{
    for (int i = 0; i < n; i++)
    {
        append(p, random_in_range(min, max));
    }
    return;
}

int main(int argc, const char * argv[]) {
    
    srand(static_cast<unsigned int>(time(nullptr)));
    int A[] = {3, 5, 7, 10, 15, 12};
    create(A, 6);
    display(first);
    insert(first, 4, 9);
    unshift(&first, 33);
    unshift(&first, 34);
    append(&first, 71);
    append(&first, 101);
    printf("count: %d\n", count(first));
    printf("sum: %d\n", sum(first));
    printf("max: %d\n", max(first));
    printf("min: %d\n", min(first));
    printf("linear search: %d\n", linear_search(first, 12));
    printf("\n");
    Delete(first, 2);
    delete_(first);
    _delete(first);
    display(first);
    generate_random_array_from_range(&second, 0, 10000, 100);
    append(&second, -101);
    printf("\nsecond goes here\n");
    display(second);
    display(second);
    return 0;
}
