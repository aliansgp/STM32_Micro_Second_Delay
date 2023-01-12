/*
 * us_Delay.c
 *
 *  Created on: Jan 12, 2023
 *      Author: Ali
 */
#include "tim.h"


void us_delay(int us){
	HAL_TIM_Base_Start(&htim1);
	htim1.Instance->CNT=0;
	while(htim1.Instance->CNT < us);

}

