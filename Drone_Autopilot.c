#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEIGHT 100.0
#define MIN_BATTERY 10
#define HOME_HEIGHT 0.0

int randomWindAlert() {

    return (rand() % 10 == 0);
}

void printStatus(double height, int battery, int windAlert) {
    printf("\n--- DRONE STATUS ---\n");
    printf("Altitude: %.1f m\n", height);
    printf("Battery: %d %%\n", battery);
    printf("Wind Warning: %s\n", windAlert ? "YES" : "NO");
    printf("--------------------\n");
}

int main() {
    srand(time(NULL));

    double height = 0.0;
    int battery = 100;
    int windAlert = 0;
    int choice;
    int running = 1;

    printf("=== DRONE AUTO-PILOT SIMULATION ===\n");

    while (running) {
        windAlert = randomWindAlert();
        printStatus(height, battery, windAlert);

        if (battery <= MIN_BATTERY) {
            printf("Battery low! Returning to home...\n");
            height = HOME_HEIGHT;
            break;
        }
        if (windAlert) {
            printf("Strong wind detected! Returning to home for safety...\n");
            height = HOME_HEIGHT;
            break;
        }

        printf("\nAvailable commands:\n");
        printf("1. Ascend  (+5 m)\n");
        printf("2. Descend (-5 m)\n");
        printf("3. Move Forward\n");
        printf("4. Move Backward\n");
        printf("5. Move Left\n");
        printf("6. Move Right\n");
        printf("7. Land (return home)\n");
        printf("8. Exit Simulation\n");
        printf("Enter command: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                height += 5.0;
                if (height > MAX_HEIGHT) height = MAX_HEIGHT;
                printf("Ascending...\n");
                break;
            case 2:
                height -= 5.0;
                if (height < HOME_HEIGHT) height = HOME_HEIGHT;
                printf("Descending...\n");
                break;
            case 3:
                printf("Moving forward...\n");
                break;
            case 4:
                printf("Moving backward...\n");
                break;
            case 5:
                printf("Moving left...\n");
                break;
            case 6:
                printf("Moving right...\n");
                break;
            case 7:
                printf("Landing / returning home...\n");
                height = HOME_HEIGHT;
                running = 0;
                break;
            case 8:
                printf("Exiting simulation...\n");
                running = 0;
                break;
            default:
                printf("Invalid command!\n");
        }

        battery -= 5;
        if (battery < 0) battery = 0;

        printf("Press Enter to continue...");
        getchar();
        getchar();
    }

    printf("\nDrone has landed. Simulation ended.\n");
    return 0;
}

