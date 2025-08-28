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

    // Open the FIFO for reading
    fd = open(FIFO_PATH, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }


        // Read a message from the FIFO
        int num_bytes = read(fd, message, sizeof(message));

        if (num_bytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Display the received message
	printf("Received message: %s\n", message);
	
      // Close the FIFO
       close(fd);

    return 0;
}
