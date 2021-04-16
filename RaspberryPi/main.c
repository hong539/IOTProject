#include <stdio.h>
#include <stdlib.h>

// get dht data
int getHttp(char *buf) {
    return 0;
}

// parse dht data
parseDHT(char *buf, int *id, float *temVal, float *humVal) {
    sscanf(buf, "ID: %d, temVal: %f, humVal: %f", *id, *temVal, *humVal);
}

// write dht data to mysql
void writeDHT2SQL(int id, float temVal, float humVal) {
    return;
}

int main(int argc, char *argv[])
{
    char buf[100];
    int id;
    float temVal;
    float humVal;

    while(1){
        if (getHttp(buf)) {
            parseDHT(buf, &id, &temVal, &humVal);
            writeDHT2SQL(id, temVal, humVal);
        }

        
    }
    return 0;
}
