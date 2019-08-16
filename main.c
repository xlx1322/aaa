#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
int main(void)
{
	u8 flag=0;
	uart_init(9600);
	delay_init();
	LED_Init();
	KEY_Init();
	LED0=0; 
	while(1)
	{
		if(KEY0==0)
		{		
			flag = 0	;
		}
		
		if(KEY1==0)
		{
			flag=1;
		}
if(flag)
	{		
		vu8 key=0;
	u16 a,b,i,j;
	a=5200;
	b=4800;
	while(1)
	{
		key=AX_KEY_Scan();
		if(key)
		{
			for(j=0;j<1000;j++)
			{
				for(i=0;i<=a;i++)
				{
					LED0=0;
					delay(i);
					LED0=1;
					delay(a-i);
					if(key==0)
						break;
				}
				for(i=0;i<b;i++)
				{
					 LED0=0;
					 delay(b-i);
					 LED0=1;
					 delay(i);
					 if(key==0)
					   break;
				 }
		   }
		 }
	 }
		
	}
else 
{	
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOE,GPIO_Pin_5);
	delay_ms(300);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
	delay_ms(300);

			
}	
		delay_ms(10);
		
	}
		
}

