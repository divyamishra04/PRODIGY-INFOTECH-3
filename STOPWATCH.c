#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

int main() {
    int minutes = 0, seconds = 0, milliseconds = 0;
    char action;

    while (1) {
        printf("\nStopwatch: %02d:%02d:%03d", minutes, seconds, milliseconds);

        printf("\n\nActions:\n");
        printf("  s - Start/Resume\n");
        printf("  p - Pause\n");
        printf("  r - Reset\n");
        printf("  q - Quit\n");

        printf("\nEnter action: ");
        scanf(" %c", &action);

        switch (action) {
            case 's':  // Start/Resume
                while (1) {
                    delay(1);
                    milliseconds++;
                    if (milliseconds == 1000) {
                        milliseconds = 0;
                        seconds++;
                    }
                    if (seconds == 60) {
                        seconds = 0;
                        minutes++;
                    }
                    system("cls || clear"); // Clears the console screen
                    printf("\nStopwatch: %02d:%02d:%03d", minutes, seconds, milliseconds);
                    if (kbhit()) {  // Check if any key is pressed
                        break;
                    }
                }
                break;

            case 'p':  // Pause
                printf("\nPaused. Press 's' to resume...");
                while (getch() != 's'); // Wait for 's' key to resume
                break;

            case 'r':  // Reset
                minutes = seconds = milliseconds = 0;
                break;

            case 'q':  // Quit
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid action. Please try again.");
        }
    }

    return 0;
}