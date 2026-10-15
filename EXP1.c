/*Write a program to implement a stack using an array.
Stack application to print an alert for heatwave prediction. 
Temperature>=40 deg print(Yellow Alert)
Temperature>=43 deg print(Orange Alert)
Temperature>=45 deg print(Red Alert)
Temperature<40 deg: remove all active alerts, Pop. */

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    }
}

void pop() {
    top = -1; 
}

void checkTemperature(int temp) {
    if (temp >= 45) {
        printf("Temperature: %d°C -> Red Alert\n", temp);
        push(temp);
    } else if (temp >= 43) {
        printf("Temperature: %d°C -> Orange Alert\n", temp);
        push(temp);
    } else if (temp >= 40) {
        printf("Temperature: %d°C -> Yellow Alert\n", temp);
        push(temp);
    } else {
        printf("Temperature: %d°C -> Removing all active alerts (Popped)\n", temp);
        pop();
    }
}

int main() {
    // Sample Inputs
    checkTemperature(41); 
    checkTemperature(44); 
    checkTemperature(46); 
    checkTemperature(38);
    
    return 0;
}