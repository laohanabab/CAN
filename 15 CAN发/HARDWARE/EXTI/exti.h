#ifndef __EXTI_H
#define __EXIT_H	 
#include "sys.h"

/******************************************************************************************/
//STM32F103 ������

//�ⲿ�ж� ��������	 

//STM32F103����ģ��-�⺯���汾
//DevEBox  ��Խ����

//�Ա����̣�mcudev.taobao.com
//�Ա����̣�devebox.taobao.com	

/****************************************************************************************/  

#define EXTI_PA1  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)  //��ȡ IO --PA1
#define EXTI_PA2  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)  //��ȡ IO --PA2
#define EXTI_PA3  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)  //��ȡ IO --PA3

#define KEY_K0   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)   //��ȡ����  K0 (WK_UP) 


void EXTIX_Init(void);//�ⲿ�жϳ�ʼ��		 					    
#endif
































/******************************************************************************************/
//STM32F103 ������

//�ⲿ�ж� ��������	 

//STM32F103����ģ��-�⺯���汾
//DevEBox  ��Խ����

//�Ա����̣�mcudev.taobao.com
//�Ա����̣�devebox.taobao.com	

/****************************************************************************************/  











