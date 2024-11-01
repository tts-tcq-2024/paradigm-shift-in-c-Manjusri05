#include <stdio.h>
#include <stdbool.h>

typedef struct {
    float lowerLimit;
    float upperLimit;
    float warningTolerance;
} ParameterLimits;

void checkTemperature(float temperature, ParameterLimits limits);
void checkState(float soc, ParameterLimits limits);
void checkChargeRate(float chargeRate, ParameterLimits limits);
void displayWarningsAndAlarms(bool isOk, const char* parameterName, const char* warningMsg);

bool batteryIsOk(float temperature, float soc, float chargeRate, ParameterLimits tempLimits, ParameterLimits socLimits, ParameterLimits chargeRateLimits) {
    bool isTemperatureOk = true;
    bool isSocOk = true;
    bool isChargeRateOk = true;

    checkTemperature(temperature, tempLimits);
    checkState(soc, socLimits);
    checkChargeRate(chargeRate, chargeRateLimits);

    return isTemperatureOk && isSocOk && isChargeRateOk;
}

void checkTemperature(float temperature, ParameterLimits limits) {
    if (temperature < limits.lowerLimit) {
        displayWarningsAndAlarms(false, "Temperature", "Temperature is out of range!");
    } else if (temperature > limits.upperLimit) {
        displayWarningsAndAlarms(false, "Temperature", "Temperature is out of range!");
    } else if (temperature >= limits.lowerLimit && temperature < limits.lowerLimit + limits.warningTolerance) {
        displayWarningsAndAlarms(true, "Temperature", "Warning: Approaching lower limit!");
    } else if (temperature <= limits.upperLimit && temperature > limits.upperLimit - limits.warningTolerance) {
        displayWarningsAndAlarms(true, "Temperature", "Warning: Approaching upper limit!");
    }
}

void checkState(float soc, ParameterLimits limits) {
    if (soc < limits.lowerLimit) {
        displayWarningsAndAlarms(false, "State of Charge", "State of Charge is out of range!");
    } else if (soc > limits.upperLimit) {
        displayWarningsAndAlarms(false, "State of Charge", "State of Charge is out of range!");
    } else if (soc >= limits.lowerLimit && soc < limits.lowerLimit + limits.warningTolerance) {
        displayWarningsAndAlarms(true, "State of Charge", "Warning: Approaching discharge");
    } else if (soc <= limits.upperLimit && soc > limits.upperLimit - limits.warningTolerance) {
        displayWarningsAndAlarms(true, "State of Charge", "Warning: Approaching charge-peak");
    }
}

void checkChargeRate(float chargeRate, ParameterLimits limits) {
    if (chargeRate > limits.upperLimit) {
        displayWarningsAndAlarms(false, "Charge Rate", "Charge Rate is out of range!");
    }
    // Assuming charge rate has no lower limit
    // Implement warnings as needed
}

void displayWarningsAndAlarms(bool isOk, const char* parameterName, const char* message) {
    if (!isOk) {
        printf("%s\n", message);
    } else {
        printf("%s\n", message);
    }
}

int main() {
    ParameterLimits tempLimits = {0, 45, 0.05 * 45};
    ParameterLimits socLimits = {20, 80, 0.05 * 80};
    ParameterLimits chargeRateLimits = {0.0, 0.8, 0.0}; // Adjust if necessary

    // Test cases
    batteryIsOk(25, 70, 0.7, tempLimits, socLimits, chargeRateLimits);
    batteryIsOk(50, 85, 0.9, tempLimits, socLimits, chargeRateLimits);
    batteryIsOk(70, 15, 0.9, tempLimits, socLimits, chargeRateLimits);
}
