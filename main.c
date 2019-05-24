#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/passenger.h"
#include "header/bus.h"

/**
 * @param connectionCode
 *
 * @return int
 */
int isBusForConnectionCode(struct Bus* tmp, unsigned long connectionCode)
{
    while (tmp != NULL) {
        if (tmp->connectionCode == connectionCode) {
            return 1;
        }

        tmp = tmp->next;
    }

    return 0;
}

/**
 * @deprecated since bus has ID
 *
 * @param connectionCode
 * @param city
 * @param date
 *
 * @return int
 */
int isBusDuplicated(struct Bus* tmp, unsigned long connectionCode, char* city, char* date)
{
    while (tmp != NULL) {
        if (tmp->connectionCode == connectionCode) {
            //strcmp returns zero, when s1 == s2
            if (strcmp(city, tmp->startingPoint) == 0) {
                if (strcmp(date, tmp->startingDate) == 0) {
                    return 1;
                }
            }
        }

        tmp = tmp->next;
    }

    return 0;
}

void addPassengerToBus(struct Bus* busList, unsigned long connectionCode, char* name, unsigned long seatNumber)
{
    struct Bus* bus = getBusByConnectionCode(busList, connectionCode);

    if (bus != NULL) {
        struct Passenger* tmpPassenger = bus->passengers;
        struct Passenger* newPassenger = (struct Passenger*) malloc(sizeof(struct Passenger));

        newPassenger->name = name;
        newPassenger->seatNumber = seatNumber;
        newPassenger->next = tmpPassenger;
        bus->passengers = newPassenger;
        bus->amountOfPassengers += 1;
        //printf("ADD PASSENGER: %lu - %s TO BUS: %lu\n", seatNumber, name, bus->connectionCode);
    }
}

/**
 * @param connectionCode
 */
void printBus(struct Bus* busList, unsigned long connectionCode)
{
    struct Bus* bus = getBusByConnectionCode(busList, connectionCode);

    if (bus != NULL) {
        printf("Symbol trasy: %lu\n", bus->connectionCode);
        printf("Punkt startowy: %s\n", bus->startingPoint);
        printf("Data: %s\n", bus->startingDate);

        struct Passenger* passenger = bus->passengers;

        while (passenger != NULL) {
            printf("%lu %s\n", passenger->seatNumber, passenger->name);
            passenger = passenger->next;
        }

        printf("Liczba rezerwacji: %lu\n\n", bus->amountOfPassengers);
    }
}

/**
 * Frees all alocated data/memory
 *
 * @param Bus* bus
 */
void freeData(struct Bus* bus)
{
    while (bus != NULL) {
        struct Bus* currentBus = bus;
        struct Passenger* nextPassenger = currentBus->passengers;

        while (nextPassenger != NULL) {
            struct Passenger* currentPassenger = nextPassenger;

            nextPassenger = currentPassenger->next;
            free(currentPassenger);
        }

        bus = currentBus->next;
        free(currentBus);
    }

    free(bus);
}

/**
 * Generate domain specified result files, where file name is bus's connection code
 *
 * @param Bus* bus
 */
void generateResult(struct Bus* bus)
{
    while (bus != NULL) {
        char name[200];
        //Create file name from bus connection code
        sprintf(name, "/Users/zbyszek/Projects/Ferror/bus-station/test/output/%lu.txt", bus->connectionCode);
        FILE* file = fopen(name, "wt");

        //Save header
        fprintf(file, "Symbol trasy: %lu\n", bus->connectionCode);
        fprintf(file, "Punkt startowy: %s\n", bus->startingPoint);
        fprintf(file, "Data: %s\n", bus->startingDate);

        //Save passengers
        struct Passenger* passenger = sortList(bus->passengers);

        while (passenger != NULL) {
            fprintf(file, "%lu %s\n", passenger->seatNumber, passenger->name);
            passenger = passenger->next;
        }

        fprintf(file, "Liczba rezerwacji: %lu\n", bus->amountOfPassengers);
        fclose(file);
        bus = bus->next;
    }
}

/**
 * Handles domain required -i parameter. When -i param is not defiend, then it loads static input file
 *
 * @param char* argv
 *
 * @return FILE*
 */
FILE* loadSourceFile(const char* argv[])
{
    if (argv[1] != NULL && strcmp(argv[1], "-i") == 0) {
        if (argv[2] == NULL) {
            printf("Argument -i potrzebuje sciezki do pliku wejsciowego\n");

            return 0;
        }

        printf("Wczytuje plik z lini polecen: %s\n", argv[2]);
        return fopen(argv[2], "rt");
    }

    return fopen("/Users/zbyszek/Projects/Ferror/bus-station/test/input/in_example_big.txt", "rt");
}

int main(int argc, const char* argv[])
{
    struct Bus* busList = NULL;
    FILE* source = loadSourceFile(argv);

    if (source == NULL) {
        printf("Nie znaleziono pliku z danymi!\n");
        printf("Pamietaj, ze potrzebna jest absolutna (pelna) sciezka pliku\n");
        
        return 0;
    }

    //Temporary operational fscanf variables
    char* connectionCode[255];
    char* startingPoint[255];
    char* startingDate[255];
    char* seatNumber[255];
    char* passengerName[255];

    while(fscanf(source, "%s %s %s %s %s", connectionCode, startingPoint, startingDate, passengerName, seatNumber) == 5) {
        //printf("SOURCE: %s %s %s %s %s\n", connectionCode, startingPoint, startingDate, passengerName, seatNumber);
        unsigned long code = strtol(strdup(connectionCode), (char **) NULL, 10);
        unsigned long seat = strtol(strdup(seatNumber), (char **) NULL, 10);
        char* city = strdup(startingPoint);
        char* date = strdup(startingDate);
        char* name = strdup(passengerName);

        //when identifier is connection code
        if (isBusForConnectionCode(busList, code) == 0) {
            struct Bus* tmp = createBus(code, city, date);
            //add bus to the beginning of bus list
            tmp->next = busList;
            busList = tmp;
        }

        addPassengerToBus(busList, code, name, seat);
        //printf("STRUCT: %lu %s %s %s %lu\n", code, city, date, name, seat);
    }

    fclose(source);
    generateResult(busList);
    freeData(busList);

    return 0;
}
