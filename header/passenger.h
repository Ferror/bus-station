#ifndef BUS_STATION_PASSENGER_H
#define BUS_STATION_PASSENGER_H

struct Passenger {
    char* name;
    unsigned long seatNumber;

    struct Passenger* next;
};

/**
 * This is insertion sort algorithm
 *
 * @see https://en.wikipedia.org/wiki/Insertion_sort#List_insertion_sort_code_in_C
 *
 * @param pList
 * @return
 */
struct Passenger* sortList(struct Passenger* passenger);

#endif
