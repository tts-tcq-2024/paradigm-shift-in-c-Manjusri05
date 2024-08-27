#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
  // Return 0 if any condition fails; otherwise, return 1
  if (temperature < 0 || temperature > 45 ||
      soc < 20 || soc > 80 ||
      chargeRate > 0.8) {
    printf("One or more parameters out of range!\n");
    return 0;
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));  // Expected: 1 (True)
  assert(!batteryIsOk(50, 85, 0));   // Expected: 0 (False)
}
