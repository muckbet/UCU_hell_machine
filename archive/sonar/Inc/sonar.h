#ifndef __sonar_h
#define __sonar_h

#define SystemCoreClockInMHz 96
//#define TIMER_reinit TIM11_reinit
//#define get_tim_us get_tim11_us
#include "stm32f4xx_hal_tim.h"

inline void TIM11_reinit()
{
 HAL_TIM_Base_Stop(&htim11);
 __HAL_TIM_SET_PRESCALER( &htim11, (SystemCoreClockInMHz-1) );
 __HAL_TIM_SET_COUNTER( &htim11, 0 );
 HAL_TIM_Base_Start_IT(&htim11);
}

inline uint32_t get_tim11_us()
{
 __HAL_TIM_DISABLE_IT(&htim11, TIM_IT_UPDATE); //! Дуже важливо!
 //__disable_irq();
 uint32_t res = __HAL_TIM_GET_COUNTER(&htim11);
 //__enable_irq();
 __HAL_TIM_ENABLE_IT(&htim11, TIM_IT_UPDATE);
 return res;
}
#endif
