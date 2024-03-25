#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"



/******************************************************************************************/
//STM32F103 开发板

//外部中断 驱动代码	 

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/  



/******************************************************************************************/
 
 /*	 配置  外部中断  用到的I/O口 */ 

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/



void EXTIX_GPIO_Config(void)
{
	
	
  GPIO_InitTypeDef GPIO_InitStructure;

  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); //开启按键端口PA的时钟
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOE2,3,4


}



/******************************************************************************************/
 
//外部中断  初始化

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/


void EXTIX_Init(void)
{
 
 	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;

    Key_GPIO_Config();//按键端口初始化 
    
	  EXTIX_GPIO_Config(); //外部中断IO引脚初始化
	
	
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//使能复用功能时钟

    //PA1 中断线以及中断初始化配置   下降沿触发
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource1);

  	EXTI_InitStructure.EXTI_Line=EXTI_Line1;	
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	       //根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

   //PA2	  中断线以及中断初始化配置 下降沿触发 
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource2);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line2;
  	EXTI_Init(&EXTI_InitStructure);	  	        //根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

   //PA3	  中断线以及中断初始化配置  下降沿触发	
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource3);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
  	EXTI_Init(&EXTI_InitStructure);	  	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器


   //PA0	  中断线以及中断初始化配置 上升沿触发 PA0  WK_UP
 	 GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0); 

  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器


  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//使能按键WK_UP所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//子优先级3
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure); 

    NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			//使能按键KEY2所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//子优先级2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);


  	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//使能按键KEY1所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//子优先级1 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			//使能按键KEY0所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//子优先级0 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
 
}



u8 Key_value=KEY_ON;//清除键值

/******************************************************************************************/
 
//外部中断0服务程序  PA0--K0 K0 (WK_UP) 

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/

void EXTI0_IRQHandler(void)
{
	delay_ms(10);    //消抖
	
	if(KEY_K0==1)	 	 //按键 K0 (WK_UP) 
	{				 
		LED_D2=!LED_D2;	
		
		Key_value=KEY_OFF;//设置按下标记
	}
	EXTI_ClearITPendingBit(EXTI_Line0); //清除LINE0上的中断标志位  
}
 



/******************************************************************************************/
 
//外部中断1服务程序

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/

void EXTI1_IRQHandler(void)
{
	delay_ms(10);     //消抖
	
	if(EXTI_PA1==0)	  //读取 IO --PA1
	{
		LED_D2=!LED_D2;
	}		 
	EXTI_ClearITPendingBit(EXTI_Line1);  //清除LINE2上的中断标志位  
}


/******************************************************************************************/
 
//外部中断2服务程序

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/

void EXTI2_IRQHandler(void)
{
	delay_ms(10);			//消抖
	
	if(EXTI_PA2==0)	  //读取 IO --PA2
	{				 
		LED_D2=!LED_D2;
	}		 
	EXTI_ClearITPendingBit(EXTI_Line2);  //清除LINE3上的中断标志位  
}

/******************************************************************************************/
 
//外部中断3服务程序

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/


void EXTI3_IRQHandler(void)
{
	delay_ms(10);    //消抖
	
	if(EXTI_PA3==0)	 //读取 IO --PA3
	{
		LED_D2=!LED_D2;
		
	}		 
	EXTI_ClearITPendingBit(EXTI_Line3);  //清除LINE4上的中断标志位  
}
 




/******************************************************************************************/
//STM32F103 开发板

//外部中断 驱动代码	 

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/ 
