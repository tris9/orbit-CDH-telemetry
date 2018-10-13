#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

typedef int bool;
#define true 1;
#define false 0;

struct data{
    uint16_t ID;
    uint16_t value;
    char time[8];
    bool check;
};

char* reportString(struct data);
struct data constructor();
struct data receiveData();
uint16_t getID();
uint16_t getValue();
char* getTime();
bool getCheck();
void sendData(struct data);

int main(){

    char* ttime = getTime();

    printf("%s\n", ttime);

    system("pause");
    return 0;
}

char* reportString(struct data d){



}

struct data constructor(){
    
}

struct data receiveData(){
    
}

uint16_t getID(){
    return 100;
}

uint16_t getValue(){
    return 16;
}

char* getTime(){
   
    time_t current_time;
    char* c_time_string;
    char* ct;
 
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    
    strncpy(ct, &c_time_string[11], 8);
    
    return ct;
}

bool getCheck(){
    return true;
}

void sendData(struct data d){
}