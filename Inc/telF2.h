#ifndef TEL_F2
#define TEL_F2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

typedef int bool;
#define true 1;
#define false 0;

struct telemetry {
    uint8_t a[12];
    
} __attribute__((packed));

void send_telemetry(struct telemetry);
struct telemetry receive_telemetry(char *);


struct data{
    uint16_t ID;
    uint16_t value;
    uint16_t time;
    _Bool check;
};

void reportString(struct telemetry, char[]);
struct data constructor(uint16_t ID, uint16_t value, uint16_t time, bool check);
struct data receiveData();
uint16_t getID();
uint16_t getValue();
uint16_t getTime();
_Bool getCheck();
void sendData(struct data);

#endif
