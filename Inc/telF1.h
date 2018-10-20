#include <stdio.h>
#include <stdlib.h>
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
    uint16_t time;
    bool check;
};

char* reportString(struct data);
struct data constructor(uint16_t ID, uint16_t value, uint16_t time, bool check);
struct data receiveData();
uint16_t getID();
uint16_t getValue();
uint16_t getTime();
bool getCheck();
void sendData(struct data);