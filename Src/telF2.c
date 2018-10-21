#include "telF2.h"
/**
int main(){

    struct telemetry tel;

    tel = receive_telemetry("121110000001");
    char report[16] = {'0'};
    reportString(tel,report);
    printf("%s", report);


    return 0;
}
**/

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
void reportString(struct telemetry tel, char result[]){

    //result = malloc(sizeof(char)*24);

    result[0] = '[';

    uint16_t j = 0;
    for(uint16_t i = 1; i <= 14; i++){
        if(i % 5 == 0){
            result[i] = ',';
        }else{
            result[i] = tel.a[j];
            j++;
        }
    }
    result[15] = ']';
    result[16] = '\0';
    

    return;
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
struct data constructor(uint16_t ID, uint16_t value, uint16_t time, bool check){
    struct data d;
    d.ID = ID;
    d.value = value;
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
    char a[3][5];
    struct data b;
    char *pch;
    pch = strtok(rData, " ");
    uint8_t i = 0;
    while(pch != NULL){
        strcpy(a[i], pch);
        a[i][4] = '\0';
        pch = strtok(NULL, " ");
        i++;
    }
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
_Bool getCheck(){
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

void send_telemetry(struct telemetry telem_data)
{
    union {
        struct telemetry telem;
        uint8_t raw[sizeof(struct telemetry)];
    } data;

    data.telem = telem_data;
    //send_thing(data.raw, sizeof(struct telemetry));
}

struct telemetry receive_telemetry(char rData[])
{
    union {
        struct telemetry telem;
        uint8_t raw[sizeof(struct telemetry)];
    } *data;
    data = rData;
    return data->telem;
}
