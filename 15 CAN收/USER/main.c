#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"

#include "can.h" 

 
 
	u8 i=0,t=0;
	u8 res;
	u8 KeyNum=0; 
	u8 mode=CAN_Mode_Normal;//CAN工作模式;CAN_Mode_Normal(0)：普通模式，CAN_Mode_LoopBack(1)：环回模式


 int main(void)
 {
	 
	delay_init();	     //延时函数初始化	
	 
	LED_Init(); //LED 端口初始化 
	 
	Key_Init();		 	//外部中断初始化
	
	uart_init(115200);	 //串口初始化为115200
	  	 

  CAN_Mode_Init(CAN_SJW_1tq,CAN_BS2_8tq,CAN_BS1_9tq,4,CAN_Mode_Normal);//CAN初始化环回模式,波特率500Kbps    
 
	LED1_ON();
 while(1)
	{
		
//		KeyNum=Key_GetNum();
//		if(KeyNum==1)//K0按下
//		{
//			Can_Send_Msg(0xAA);//发送8个字节 		
//			LED1_OFF();
//		}
//		if(KeyNum==2)//K0按下
//		{
//			LED1_ON();
//			printf("%d",Can_Receive_Msg());
//		}
		Can_Receive_Msg();

		//delay_ms(200);
		
		
	}
 }


 
 

 
 
 
 
 
 
 
 
 

