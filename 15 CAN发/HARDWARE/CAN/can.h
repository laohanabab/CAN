#ifndef __CAN_H
#define __CAN_H	 


#include "sys.h"	    


//////////////////////////////////////////////////////////////////////////////////	 
/****************************************************************************************/
//STM32F103 开发板

//CAN驱动 代码

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/
////////////////////////////////////////////////////////////////////////////////// 	 
 
//CAN接收RX0中断使能

#define CAN_RX0_INT_ENABLE	0		//0,不使能;1,使能.								    
										 							 				    
u8 CAN_Mode_Init(u8 tsjw,u8 tbs2,u8 tbs1,u16 brp,u8 mode);//CAN初始化
 
u8 Can_Send_Msg(u8 msg);						//发送数据

u8 Can_Receive_Msg(void);							//接收数据
#endif
















/****************************************************************************************/
//STM32F103 开发板

//STM32F103工程模板-库函数版本
//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/****************************************************************************************/










