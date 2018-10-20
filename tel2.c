/**
 * tel1.c
 * Author: Tristen Raab
 * Oct 8th 2018
 * 
 * Purpose: Prototype to figure out the structure
 * of the telemetry process we will use for the cubesat
 * 
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

typedef int bool;
#define true 1;
#define false 0;

/**
 * Purpose: Struct to contain data passed from
 * different subsystems
 * 
 * [Todo]:
 *  -Add more parameters (?)
 *  -Confirm datatypes (?)
 *
**/
struct data{
    uint16_t ID;
    uint16_t value;
    uint16_t time;
    bool check;
};

char* reportString(struct data);
struct data constructor();
struct data receiveData();
uint16_t getID();
uint16_t getValue();
uint16_t getTime();
bool getCheck();
void sendData(struct data);

int main(){

    struct data dat = receiveData("1000 1234 0001");
    printf("hello");
    printf("%d %d %d %d", dat.ID, dat.value, dat.time, dat.check);

    system("pause");
    return 0;
}

/**
 * Purpose: Returns the struct of data as a string
 * to report back to a console or other display to
 * be read
 * 
 * [Todo]:
 *  -Formalize struct
 *  -How big should the data report be?
 *  
 **/
char* reportString(struct data d){



}

/**
 * Purpose: Constructs the data struct
 * 
 * [Todo]:
 *  -We might not need this
 *  -Would this use receiveData() then compile that into
 *  the struct?
 *      ->In that case what would receive data return?
 *  -How are we receiving that data and do we need
 *  a constructor?
 **/
struct data constructor(){
    
}

/**
 * Purpose: Gets the data from the given subsystem and 
 *  records the given subsystems ID and the time it was
 *  received
 * 
 *  [Todo]:
 *  -Maybe the constructor can be called in here?
 *      ->Then we can pass all the data into the
 *          constructor and return the data
 **/
struct data receiveData(char *rData){
    char a[3][5];
    struct data b;
    char *pch;
    printf("hell02");
    pch = strtok(rData, " ");
    printf("hell03");
    uint8_t i = 0;
    while(pch != NULL){
        
        strcpy(a[i], pch);
        a[i][4] = '\0';
        pch = strtok(NULL, " ");
        i++;
    }
    printf("hell01");
    b = constructor((uint16_t)atoi(a[0]), (uint16_t)atoi(a[1]), getTime(), atoi(a[2]));

    return b;
}

/**
 * Purpose: Returns the ID of the given subsystem
 * 
 * [Todo]:
 *  -Will this record the ID of the subsystem?
 *      ->If so how will it do that?
 *  -Otherwise, is this a getter for the struct?
 **/
uint16_t getID(){
    return 100;
}

/**
 * Purpose: Retrieves the value of the subsystems
 *  sensor
 * 
 *  [Todo]:
 *  -Basically the same as getID()
 **/
uint16_t getValue(){
    return 16;
}

/**
 * Purpose: Records the time a subsystems data
 *  and ID where taken in
 * 
 *  [Todo]:
 *  -How accurate time recording do we need?
 *  -Recorded as a string or and int?
 **/
uint16_t getTime(){
   
    time_t current_time;
 
    current_time = time(NULL);

    uint16_t i_time = (uint16_t)current_time;
    
    return i_time;
}

/**
 * Purpose: Gets the checksum from the subsystem
 * 
 * [Todo]:
 *  -What is this checking?
 *      -> Correctly received? Correctly transmitted? Normal value?
 **/
bool getCheck(){
    return true;
}

/**
 * Purpose: Sends the telemetry data to COMMS to 
 *  be transmitted back down to earth
 * 
 *  [Todo]:
 *  *This will probably need the most work*
 *  -How are we going to process the data so that
 *  COMMS can read and transmit it?
 **/
void sendData(struct data d){
}