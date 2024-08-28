#include <stdio.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
    if (temperature < 0 || temperature > 45) {
        printf("Temperature out of range!\n");
        return 0; // CCN contribution: 1 decision point
    } else if (soc < 20 || soc > 80) {
        printf("State of Charge out of range!\n");
        return 0; // CCN contribution: 1 decision point
    } else if (chargeRate > 0.8) {
        printf("Charge Rate out of range!\n");
        return 0; // CCN contribution: 1 decision point
    }

    return 1; // Default return if no conditions are met
}

int main() {
    printf("Test 1: %d\n", batteryIsOk(25, 70, 0.7));  // Expected output: 1
    printf("Test 2: %d\n", batteryIsOk(50, 85, 0));    // Expected output: 0
    printf("Test 3: %d\n", batteryIsOk(30, 10, 0.9));  // Expected output: 0
    return 0;
}
