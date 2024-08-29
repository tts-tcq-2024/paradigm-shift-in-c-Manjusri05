#include <stdio.h>
#include <stdbool.h>

bool checkTemperature(float temperature) {
    return temperature < 0 || temperature > 45;
}

bool checkState(float soc) {
    return soc < 20 || soc > 80;
}

bool checkChargeRate(float chargeRate) {
    return chargeRate > 0.8;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool isTemperatureOk = !checkTemperature(temperature);
    bool isSocOk = !checkState(soc);
    bool isChargeRateOk = !checkChargeRate(chargeRate);

    displayTemp(isTemperatureOk);
    displaySoc(isSocOk);
    displayChargeRate(isChargeRateOk);

    return isTemperatureOk && isSocOk && isChargeRateOk;
}

void displayTemp(bool isTemperatureOk) {
    if (!isTemperatureOk) {
        printf("Temperature is out of range!\n");
    }
}

void displaySoc(bool isSocOk) {
    if (!isSocOk) {
        printf("State of Charge is out of range!\n");
    }
}

void displayChargeRate(bool isChargeRateOk) {
    if (!isChargeRateOk) {
        printf("Charge Rate is out of range!\n");
    }
}

int main() {
    // Test cases
    printf("Test Case 1: %s\n", batteryIsOk(25, 70, 0.7f) ? "Passed" : "Failed");
    printf("Test Case 2: %s\n", batteryIsOk(50, 85, 0.0f) ? "Passed" : "Failed");
    printf("Test Case 3: %s\n", batteryIsOk(-1, 85, 0.0f) ? "Passed" : "Failed");
    printf("Test Case 4: %s\n", batteryIsOk(25, 10, 0.0f) ? "Passed" : "Failed");
    printf("Test Case 5: %s\n", batteryIsOk(25, 85, 0.0f) ? "Passed" : "Failed");
    printf("Test Case 6: %s\n", batteryIsOk(25, 25, 0.9f) ? "Passed" : "Failed");
    printf("Test Case 7: %s\n", batteryIsOk(25, 85, 0.0f) ? "Passed" : "Failed");

    return 0;
}
