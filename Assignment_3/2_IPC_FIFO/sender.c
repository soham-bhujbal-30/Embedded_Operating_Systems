#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_PATH "/home/desd/Desktop/Prateek/Assi_3/IPC_FIFO/file"  // Path to the FIFO

int main() {
    int fd;
    char message[100];

    // Create the FIFO if it doesn't exist
    mkfifo(FIFO_PATH, 0666);   //0666 min octal -> 000,110,110,110 

    // Open the FIFO for writing
    fd = open(FIFO_PATH, O_WRONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read messages from the user and send them through the FIFO
        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);


        // Write the message into the FIFO
        write(fd, message, strlen(message) + 1);
    

    // Close the FIFO
    close(fd);

    // Remove the FIFO from the file system
    unlink(FIFO_PATH);
    

    return 0;
}
