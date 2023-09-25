#include "mcc_generated_files/mcc.h"

void rmtr(int16_t val) {
  if(val > 0) {
    R0_SetHigh();
    R1_SetLow();
  } else {
    R0_SetLow();
    R1_SetHigh();
  }
  PWM3_LoadDutyValue(abs(val));
}

void lmtr(int16_t val) {
  if(val > 0) {
    L0_SetHigh();
    L1_SetLow();
  } else {
    L0_SetLow();
    L1_SetHigh();
  }
  PWM4_LoadDutyValue(abs(val));
}

void main(void) {
  SYSTEM_Initialize();

  //INTERRUPT_GlobalInterruptEnable();
  //INTERRUPT_PeripheralInterruptEnable();

  rmtr(0);
  lmtr(0);

  while(1) {
    uint16_t la = ADC_GetConversion(SAENS_LA);
    uint16_t ra = ADC_GetConversion(SAENS_RA);
  }

  while(1) {
    LED3_SetLow();
    LED0_SetHigh();

    rmtr(1000);
    lmtr(1000);

    __delay_ms(1000);

    LED0_SetLow();
    LED1_SetHigh();

    __delay_ms(1000);

    rmtr(-1000);
    lmtr(-1000);

    LED1_SetLow();
    LED2_SetHigh();

    __delay_ms(1000);

    LED2_SetLow();
    LED3_SetHigh();

    __delay_ms(1000);
  }
}
