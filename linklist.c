#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    struct node *next;

} Node;


Node *node_create(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (!newnode) return NULL;
    else {
        newnode->data = data;
        newnode->next=NULL;
    }
    return newnode;
}

void node_push(Node *first, Node *addnode)
{
    Node *trace = first;
    Node *previos;

    while(trace) {
        previos = trace;
        trace = trace->next;
    }

    previos->next = addnode;

}

void list_free(Node *first)
{
    Node *trace = first;

    while(trace) {
        Node *tmp = trace;
        trace = trace->next;
        printf("Free %d\n",tmp->data);
        free(tmp);
    }
}

void print_list(Node *first)
{
    Node *trace = first;
    if (!trace) {
        printf("list is empty!!\n");
    } else {

        while (trace) {
            printf("%d\n", trace->data);
            trace = trace->next;
        }
    }
    printf("<---%s\n",__func__);
}

int delete_node(Node *first, int data_del)
{
    int status = 0;

    Node *trace = first;
    Node *previous;

    while (trace) {
        if (trace->data == data_del) {
            printf("trace data: %d\n",trace->data);
            previous->next = trace->next;
            Node *tmp = trace->next;
            printf("trace next data: %d\n",tmp->data);

            free(trace);

            status = 1;
            break;
        } else {
            previous = trace;
            trace = trace->next;
        }
    }

    return status;
}

int main(int argc, char *argv[])
{
    Node *first_node = node_create(5);
    for (int i =0 ;i< 10;i++){
        Node *nodenew = node_create(i*2);
        node_push(first_node, nodenew);

    }
    print_list(first_node);
    delete_node(first_node, 10);
    print_list(first_node);
    list_free(first_node);
    print_list(first_node);

    return 0;
}
