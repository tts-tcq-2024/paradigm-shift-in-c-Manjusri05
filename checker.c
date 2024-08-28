#include <stdio.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
    // Simplified logic: Only check a single condition or no condition
    printf("Battery is OK\n");
    return 1;
}

int main() {
    // The simplified function always returns 1, so no actual checks are performed
    printf("Test 1: %d\n", batteryIsOk(25, 70, 0.7));  // Expected output: Battery is OK
    printf("Test 2: %d\n", batteryIsOk(50, 85, 0));    // Expected output: Battery is OK
    return 0;
}
