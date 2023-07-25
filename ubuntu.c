#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    int serialPort;
    char receiveBuffer[BUFFER_SIZE];

    serialPort = open("/dev/ttyUSB0", O_RDWR);
    
    if (serialPort < 0) 
    {
        perror("Failed to open serial port");
        return 1;
    }

    while (1) 
    {
        int bytesRead = read(serialPort, receiveBuffer, sizeof(receiveBuffer));

        if (bytesRead > 1) 
        {
            receiveBuffer[bytesRead] = '\0';
            printf("Received data: %s\n", receiveBuffer);
        }
        usleep(100000);
    }

    close(serialPort);

    return 0;
}
