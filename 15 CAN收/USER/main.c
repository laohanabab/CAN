#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"

#include "can.h" 

 
 
	u8 i=0,t=0;
	u8 res;
	u8 KeyNum=0; 
	u8 mode=CAN_Mode_Normal;//CAN����ģʽ;CAN_Mode_Normal(0)����ͨģʽ��CAN_Mode_LoopBack(1)������ģʽ


 int main(void)
 {
	 
	delay_init();	     //��ʱ������ʼ��	
	 
	LED_Init(); //LED �˿ڳ�ʼ�� 
	 
	Key_Init();		 	//�ⲿ�жϳ�ʼ��
	
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
	  	 

  CAN_Mode_Init(CAN_SJW_1tq,CAN_BS2_8tq,CAN_BS1_9tq,4,CAN_Mode_Normal);//CAN��ʼ������ģʽ,������500Kbps    
 
	LED1_ON();
 while(1)
	{
		
//		KeyNum=Key_GetNum();
//		if(KeyNum==1)//K0����
//		{
//			Can_Send_Msg(0xAA);//����8���ֽ� 		
//			LED1_OFF();
//		}
//		if(KeyNum==2)//K0����
//		{
//			LED1_ON();
//			printf("%d",Can_Receive_Msg());
//		}
		Can_Receive_Msg();

		//delay_ms(200);
		
		
	}
 }


 
 

 
 
 
 
 
 
 
 
 

