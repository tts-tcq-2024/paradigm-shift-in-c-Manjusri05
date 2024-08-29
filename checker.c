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
    batteryIsOk(25, 70, 0.7);
    batteryIsOk(50, 85, 0);
}
