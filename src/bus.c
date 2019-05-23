#include <stddef.h>
#include <stdlib.h>
#include "../header/bus.h"

struct Bus* getBusByConnectionCode(struct Bus* bus, unsigned long connectionCode)
{
    while (bus != NULL && bus->connectionCode != connectionCode) {
        bus = bus->next;
    }

    return bus;
}

struct Bus* createBus(unsigned long code, char* city, char* date)
{
    struct Bus* bus = (struct Bus*) malloc(sizeof(struct Bus));

    bus->connectionCode = code;
    bus->startingPoint = city;
    bus->startingDate = date;
    bus->amountOfPassengers = 0;
    bus->passengers = NULL;

    return bus;
}
