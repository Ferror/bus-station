#ifndef BUS_STATION_BUS_H
#define BUS_STATION_BUS_H

#include "passenger.h"

struct Bus {
    unsigned long connectionCode;
    unsigned long amountOfPassengers;
    char* startingPoint;
    char* startingDate;

    struct Bus* next;
    struct Passenger* passengers;
};

/**
 * @param Bus* bus
 * @param connectionCode
 *
 * @return Bus*
 */
struct Bus* getBusByConnectionCode(struct Bus* bus, unsigned long connectionCode);

/**
 * @param code
 * @param city
 * @param date
 *
 * @return Bus*
 */
struct Bus* createBus(unsigned long code, char* city, char* date);

#endif
