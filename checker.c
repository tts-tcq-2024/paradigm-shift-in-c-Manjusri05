#include <stdio.h>
#include "checker.h"

float tolerance_Check(float max){
    return max*0.05; //5% of the max value
}
int warning_check(float value, float tolerance,float upper, float lower, const char* range_name){
    if(value >= (upper - tolerance)){
        printf("%s approaching peak!\n", range_name);
    }
    if (value <= (lower + tolerance)) {
        printf("%s approaching discharge!\n", range_name);
    }
}

int isTemperatureOk(float temperature) {
    float Temp_tolerance_Check = tolerance_Check(TEMP_UL);
    
    if(temperature < 0 || temperature > 45)
    {
        printf("Temperature out of range!\n");
        return 0;
    }
    warning_check(temperature,Temp_tolerance_Check,TEMP_UL,TEMP_LL,"Temperature");
    return 1;
}
 
int isSocOk(float soc) {
    float SOC_tolerance_Check = tolerance_Check(SOC_UL);
    
    if(soc < 20 || soc > 80)
    {
        printf("State of Charge out of range!\n");
      return 0;
    }
    warning_check(soc,SOC_tolerance_Check,SOC_UL,SOC_LL,"SOC");
    return 1;
}
 
int isChargeRateOk(float chargeRate) {
    float Chargerate_tolerance_Check = tolerance_Check(CHARGE_RATE_UL);
    
    if(chargeRate > 0.8)
    {
         printf("Charge Rate out of range!\n");
         return 0;
    }
     warning_check(chargeRate,Chargerate_tolerance_Check,CHARGE_RATE_UL,0,"Charge rate");
    return 1;
}
 
int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
