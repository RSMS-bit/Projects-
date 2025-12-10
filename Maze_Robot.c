#include <stdio.h>

#define ROWS 10
#define COLS 15

// Maze Legend:
// '#' = wall
// ' ' = open space
// 'R' = robot
// 'E' = exit

char maze[ROWS][COLS] = {
    "###############",
    "#R   #       E#",
    "# ### ####### #",
    "#     #       #",
    "##### # ##### #",
    "#     #     # #",
    "# ### ##### # #",
    "#   #       # #",
    "### ######### #",
    "###############"
};

int robotRow = 1, robotCol = 1;

// Directions: 0=UP, 1=RIGHT, 2=DOWN, 3=LEFT
int direction = 1;

void printMaze() {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

int isOpen(int r, int c) {
    return maze[r][c] == ' ' || maze[r][c] == 'E';
}

void moveRobot(int newR, int newC) {
    maze[robotRow][robotCol] = ' ';  // clear old position
    robotRow = newR;
    robotCol = newC;
    maze[robotRow][robotCol] = 'R';
}

int main() {
    printf("=== MAZE SOLVING ROBOT (RIGHT-HAND RULE) ===\n\n");

    printMaze();

    while (maze[robotRow][robotCol] != 'E') {

        // Check right side
        int rightDir = (direction + 1) % 4;

        int lookR = robotRow, lookC = robotCol;
        if (rightDir == 0) lookR--;
        if (rightDir == 1) lookC++;
        if (rightDir == 2) lookR++;
        if (rightDir == 3) lookC--;

        if (isOpen(lookR, lookC)) {
            direction = rightDir; // turn right
        } else {
            // Check forward
            lookR = robotRow;
            lookC = robotCol;

            if (direction == 0) lookR--;
            if (direction == 1) lookC++;
            if (direction == 2) lookR++;
            if (direction == 3) lookC--;

            if (!isOpen(lookR, lookC)) {
                // turn left
                direction = (direction + 3) % 4;
            }
        }

        // Move robot FORWARD
        int newR = robotRow, newC = robotCol;
        if (direction == 0) newR--;
        if (direction == 1) newC++;
        if (direction == 2) newR++;
        if (direction == 3) newC--;

        if (isOpen(newR, newC)) {
            moveRobot(newR, newC);
        }

        printMaze();
        printf("Press ENTER for next move...");
        getchar();
    }

    printf("\n🎉 Robot reached the EXIT!\n");
    return 0;
}
