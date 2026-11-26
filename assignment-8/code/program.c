#include <stdio.h>
#include <string.h>

struct sensor {
    int id;
    char type[20];
    float reading;
    float min;
    float max;
    char status[10];
};

void inputsensors(struct sensor *s, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nenter details for sensor %d:\n", i+1);
        printf("sensor ID: ");
        scanf("%d", &(s + i)->id);
        printf("sensor type: ");
        scanf("%s", (s + i)->type);
        printf("measured reading: ");
        scanf("%f", &(s + i)->reading);
        printf("min value: ");
        scanf("%f", &(s + i)->min);
        printf("max value: ");
        scanf("%f", &(s + i)->max);
    }
}

void checkstatus(struct sensor *s, int n) {
    for(int i = 0; i < n; i++) {
        if ((s + i)->reading >= (s + i)->min &&
            (s + i)->reading <= (s + i)->max) {
            strcpy((s + i)->status, "normal");
        }
        else {
            strcpy((s + i)->status, "abnormal");
        }
    }
}

void displaysensors(struct sensor *s, int n) {
    printf("\n--- sensor report ---\n");
    printf("ID\ttype\treading\trange\tstatus\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\t%.2f - %.2f\t%s\n",
        (s + i)->id, (s + i)->type, (s + i)->reading,
        (s + i)->min, (s + i)->max, (s + i)->status);
    }
}

float averagereading(struct sensor *s, int n, char t[]) {
    float sum = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if (strcmp((s + i)->type, t) == 0) {
            sum += (s + i)->reading;
            count++;
        }
    }

    return (count == 0) ? 0 : (sum/count);
}

void displayAbnormal(struct sensor *s, int n) {
    printf("\nAbnormal sensors:\n");
    int flag = 0;

    for (int i = 0; i < n; i++) {
        if(strcmp((s + i)->status, "abnormal") == 0) {
            printf("\nSensor ID: %d", (s+i)->id);
            printf("\nSensor Type: %s", (s+i)->type);
            printf("\nReading: %.2f", (s+i)->reading);
            printf("\nStatus: %s\n", (s+i)->status);

            flag = 1;
        }
    }

    if(flag == 0) {
        printf("No abnormal sensors found.\n");
    }
}

// Main function
int main()
{
    struct sensor s[100];
    int n;
    char t[20];
    float avg;

    printf("Enter number of sensors: ");
    scanf("%d", &n);

    if(n < 1 || n > 100)
    {
        printf("Invalid number of sensors!\n");
        return 0;
    }

    inputsensors(s, n);

    checkstatus(s, n);

    displaysensors(s, n);

    printf("\nEnter sensor type to calculate average: ");
    scanf("%19s", t);

    avg = averagereading(s, n, t);

    printf("\nAverage reading of %s = %.2f\n", t, avg);

    displayAbnormal(s, n);

    return 0;
}
