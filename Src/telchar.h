#ifndef TEL_CHAR
#define TEL_CHAR

typedef int bool;
#define true 1;
#define false 0;

struct data{
    char ID[4];
    char value[4];
    uint16_t time;
    char check;
};

char *reportString(struct data);
struct data constructor(char ID[], char value[], uint16_t time, char check);
struct data receiveData();
uint16_t getID();
uint16_t getValue();
uint16_t getTime();
bool getCheck();
void sendData(struct data);

#endif