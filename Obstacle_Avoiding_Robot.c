#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getDistance() {

    return rand() % 100 + 1;
}

void moveForward() {
    printf("Robot moving FORWARD...\n");
}

void turnLeft() {
    printf("Robot turning LEFT...\n");
}

void turnRight() {
    printf("Robot turning RIGHT...\n");
}

void stopRobot() {
    printf("Robot STOPPED! Obstacle too close.\n");
}

int main() {
    srand(time(NULL));
    int distance;

    printf("=== OBSTACLE AVOIDING ROBOT SIMULATION ===\n");

    while (1) {
        distance = getDistance();
        printf("\nSensor distance: %d cm\n", distance);

        if (distance < 10) {
            stopRobot();
        }
        else if (distance < 20) {
            turnLeft();
        }
        else if (distance < 30) {
            turnRight();
        }
        else {
            moveForward();
        }

        printf("Press Enter for next reading...");
        getchar();
    }

    return 0;
}
