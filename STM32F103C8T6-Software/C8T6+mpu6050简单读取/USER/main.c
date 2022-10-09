#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "string.h"		
#include "led.h"
#include "TIME.h"
#include "mpu6050.h"
#include "OLED.h"

float Pitch,Roll,Yaw;


//MPU6050��
//#define IIC_SCL    PBout(6) //SCL
//#define IIC_SDA    PBout(7) //SDA	 

//OLED
//#define OLED_SCLK_Set() GPIO_SetBits(GPIOA,GPIO_Pin_5)//SCL
//#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_7)//DIN


int main(void)
{	
	u8 string[10] = {0};	
	delay_init();
	uart_init(115200);
//	LED_Init();
	
	
	OLED_Init();
	OLED_ShowString(40,0,"MPU6050",16);
	OLED_Refresh();
	
	IIC_Init();
	MPU6050_initialize();     //=====MPU6050��ʼ��	
	DMP_Init();
	
	
	TIM2_Getsample_Int(1999,719);		//50ms����ʱ�ж�


	while(1)
	{	
		delay_ms(999);
		sprintf((char *)string,"Pitch:%.2f",Pitch);//0300
		OLED_ShowString(16,16,string,16);
		sprintf((char *)string,"Roll :%.2f",Roll);//0300
		OLED_ShowString(16,32,string,16);
		sprintf((char *)string,"Yaw  :%.2f",Yaw);//0300
		OLED_ShowString(16,48,string,16);
		OLED_Refresh();
	}
}
