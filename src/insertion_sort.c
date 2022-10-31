#include "insertion_sort.h"
#include "linked_list.h"



void sort(linked_list *llPtr)
{
 node_t *ptr_current = llPtr->head->next;
 node_t *ptr_previous = llPtr->head;
 node_t *tjek = llPtr->head;

    while(ptr_current != NULL) {
        if (ptr_current->data < ptr_previous->data && ptr_previous == llPtr->head){ // hvis node skal være en ny head
            llPtr->head = swap(ptr_previous, ptr_current); // Ny head skal være først i 
            ptr_current = llPtr->head->next; //peger på anden node i list
            ptr_previous = llPtr->head; // peger på første node i list
        }
        else if (ptr_current->data < ptr_previous->data) // hvis node skal sorteres
        {
            while (tjek->next != ptr_previous){ //tjek skal være en node før previous før while loop kører
                tjek = tjek->next;
            }
            tjek->next = swap(ptr_previous, ptr_current); 
            ptr_previous = tjek; 
            tjek = llPtr->head; 
        }
        else{
            ptr_current = ptr_current->next; //flytter current og previous til next hvis listen er sorteret
            ptr_previous = ptr_previous->next; // ^^
        }
    }
}