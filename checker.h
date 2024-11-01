#ifndef CHECKER_H
#define CHECKER_H
#define TEMP_UL 45
#define TEMP_LL 0
#define SOC_UL 80
#define SOC_LL 20
#define CHARGE_RATE_UL 0.8

float tolerance_Check(float max);
int warning_check(float value, float tolerance,float upper, float lower, const char* range_name);
int isTemperatureOk(float temperature);
int isSocOk(float soc);
int isChargeRateOk(float chargeRate);
int batteryIsOk(float temperature, float soc, float chargeRate);

#endif // CHECKER_H
