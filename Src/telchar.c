#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include "telchar.h"

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
char *reportString(struct data d){
    char ctime[8];
    sprintf(ctime, "%d", d.time);
    char result[20];
    result[1] = '[';
    int j = 0;
    for(int i = 1; i < 5; i++){
        result[i] = d.ID[j];
        j++;
    }
    result[5] = ' ';
    result[6] = ',';
    result[7] = ' ';
    j = 0;
    for(int i = 8; i < 12; i++){
        result[i] = d.value[j];
        j++;
    }
    result[12] = ' ';
    result[13] = ',';
    result[14] = ' ';
    j = 0;
    for(int i = 15; i < 20; i++){
        result[i] = ctime[j];
        j++;
    }
    result[20] = ' ';
    result[21] = ',';
    result[22] = ' ';
    result[23] = d.check;
    result[24] = ']';
    char *rtnPtr = result;
    return rtnPtr;
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
struct data constructor(char ID[], char value[], uint16_t time, char check){
    struct data d;
    strcpy(d.ID, ID);
    strcpy(d.value, value);
    d.time = time;
    d.check = check;

    return d;
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
struct data receiveData(char rData[]){
    
    char rID[4];
    char rVal[4];
    strncpy(rID, &rData[0], 4);
    strncpy(rVal, &rData[5], 4);
    
    struct data d = constructor(rID, rVal, getTime(), rData[10]);
    return d;
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
    
    uint16_t t = (uint16_t) current_time;
    
    return t;
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