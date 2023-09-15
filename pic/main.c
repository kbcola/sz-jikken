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

  while(1) {
    rmtr(1000);
    lmtr(1000);

    __delay_ms(2000);

    rmtr(-1000);
    lmtr(-1000);

    __delay_ms(2000);
  }
}
