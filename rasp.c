#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

#define BUFFER_SIZE 256


int main() 
{
    int serialPort;
    char sendBuffer[BUFFER_SIZE];
    
    serialPort = open("/dev/ttyS0", O_RDWR);
    if (serialPort < 0) 
    {
        perror("Failed to open serial port");
        return 1;
    }


    while (1) 
    {
        printf("Enter a string to send:");
        fgets(sendBuffer, BUFFER_SIZE, stdin);
        write(serialPort, sendBuffer, strlen(sendBuffer));
    }
    
    close(serialPort);
    return 0;
}

