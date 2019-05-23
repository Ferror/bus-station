#include <stddef.h>
#include "../header/bus.h"

/**
 * This is insertion sort algorithm
 *
 * @see https://en.wikipedia.org/wiki/Insertion_sort#List_insertion_sort_code_in_C
 *
 * @param pList
 * @return
 */
struct Passenger* sortList(struct Passenger* passenger)
{
    if (passenger == NULL || passenger->next == NULL) {
        return passenger;
    }

    struct Passenger* head = NULL;

    while (passenger != NULL) {
        struct Passenger* current = passenger;
        passenger = passenger->next;

        if (head == NULL || current->seatNumber < head->seatNumber) {
            current->next = head;
            head = current;
        } else {
            struct Passenger* p = head;

            while (p != NULL) {
                if (p->next == NULL || current->seatNumber < p->next->seatNumber) {
                    current->next = p->next;
                    p->next = current;

                    break;
                }

                p = p->next;
            }
        }
    }

    return head;
}
