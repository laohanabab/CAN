#ifndef __EXTI_H
#define __EXIT_H	 
#include "sys.h"

/******************************************************************************************/
//STM32F103 开发板

//外部中断 驱动代码	 

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/  

#define EXTI_PA1  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)  //读取 IO --PA1
#define EXTI_PA2  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)  //读取 IO --PA2
#define EXTI_PA3  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)  //读取 IO --PA3

#define KEY_K0   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)   //读取按键  K0 (WK_UP) 


void EXTIX_Init(void);//外部中断初始化		 					    
#endif
































/******************************************************************************************/
//STM32F103 开发板

//外部中断 驱动代码	 

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/  











