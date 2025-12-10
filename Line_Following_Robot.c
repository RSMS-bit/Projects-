#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Randomly simulate black/white detection
// 1 = sees line (black), 0 = white (no line)
int readLeftSensor() {
    return rand() % 2;
}

int readRightSensor() {
    return rand() % 2;
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
    printf("Robot STOPPED (line lost).\n");
}

int main() {
    srand(time(NULL));
    int left, right;

    printf("=== LINE FOLLOWING ROBOT SIMULATION ===\n");

    while (1) {
        left = readLeftSensor();
        right = readRightSensor();

        printf("\nLeft Sensor: %d | Right Sensor: %d\n", left, right);

        if (left == 1 && right == 1) {
            moveForward();
        }
        else if (left == 1 && right == 0) {
            turnLeft();
        }
        else if (left == 0 && right == 1) {
            turnRight();
        }
        else {
            stopRobot();
        }

        printf("Press Enter for next reading...");
        getchar();
    }

    return 0;
}
