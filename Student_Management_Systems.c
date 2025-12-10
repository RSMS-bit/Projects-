#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    struct Student students[100];
    int count = 0, choice;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search by ID\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter student ID: ");
            scanf("%d", &students[count].id);

            printf("Enter name: ");
            scanf("%s", students[count].name);

            printf("Enter marks: ");
            scanf("%f", &students[count].marks);

            count++;
        }

        else if (choice == 2) {
            printf("\nList of Students:\n");
            for (int i = 0; i < count; i++) {
                printf("%d  %s  %.2f\n", students[i].id, students[i].name, students[i].marks);
            }
        }

        else if (choice == 3) {
            int searchID;
            printf("Enter ID to search: ");
            scanf("%d", &searchID);

            int found = 0;
            for (int i = 0; i < count; i++) {
                if (students[i].id == searchID) {
                    printf("Found: %d  %s  %.2f\n",
                           students[i].id, students[i].name, students[i].marks);
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Student not found!\n");
        }

        else if (choice == 4) break;
        else printf("Invalid choice!\n");
    }

    return 0;
}
