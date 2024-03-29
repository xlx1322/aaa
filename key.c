#include "stm32f10x.h"
#include "key.h"
#include "delay.h"
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	


}
uint8_t AX_KEY_Scan(void)
{
	if(PEin(3) == 0)		
	{
		delay_ms(10);
		if(PEin(3) == 0)
		{
			while(PEin(3) == 0);
			return 1;
		}
	}
	return 0;
}

//u8 KEY_Scan(u8 mode)
//{	 
//	static u8 key_up=1;
//	if(mode)key_up=1;  		  
//	if(key_up&&(KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
//	{
//		delay_ms(10);
//		key_up=0;
//		if(KEY0==0)return KEY0_PRES;
//		else if(KEY1==0)return KEY1_PRES;
//		else if(KEY2==0)return KEY2_PRES;
//		else if(WK_UP==1)return WKUP_PRES;
//	}else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)key_up=1; 	    
//// 	return 0;
////}