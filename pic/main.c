#include "mcc_generated_files/mcc.h"

void lmtr(int16_t val) {
  // wip
  if(val > 0) {
    L0_SetHigh();
    L1_SetLow();
  } else {
    L0_SetLow();
    L0_SetHigh();
  }
  PWM3_LoadDutyValue(abs(val));
}

void rmtr(int16_t val) {
  // wip
  if(val > 0) {
    R0_SetHigh();
    R0_SetLow();
  } else {
    R0_SetLow();
    R0_SetHigh();
  }
  PWM4_LoadDutyValue(abs(val));
}

void main(void) {
  SYSTEM_Initialize();

  //INTERRUPT_GlobalInterruptEnable();
  //INTERRUPT_PeripheralInterruptEnable();

  while(1) {
  }
}
