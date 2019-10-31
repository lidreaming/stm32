#include "led.h"

//����led + ����
CLASS_Led   LedA={  .led_name             = LED_A,
										.config.gpio_clk  = RCC_APB2Periph_GPIOB,
										.config.gpio_port = GPIOB,
										.config.gpio_pin  = GPIO_Pin_5,
										};
CLASS_Led   LedB={ .led_name              = LED_B,
										.config.gpio_clk  = RCC_APB2Periph_GPIOB,
										.config.gpio_port = GPIOB,
										.config.gpio_pin  = GPIO_Pin_0,
										};
CLASS_Led   LedC={ .led_name              = LED_C,
										.config.gpio_clk  = RCC_APB2Periph_GPIOB,
										.config.gpio_port = GPIOB,
										.config.gpio_pin  = GPIO_Pin_1,
										};
CLASS_Led   Fmq ={ .led_name              = FMQ,
										.config.gpio_clk  = RCC_APB2Periph_GPIOB,
										.config.gpio_port = GPIOB,
										.config.gpio_pin  = GPIO_Pin_8,
										};


/**************************************************************************
�������ܣ�������ʼ��,��������
��ڲ������� 
����  ֵ����
**************************************************************************/
static void led_init(CLASS_Led* led_n)
{
	GPIO_InitTypeDef G_GPIO_IniStruct;  //����ṹ��
	
	RCC_APB2PeriphClockCmd(led_n->config.gpio_clk, ENABLE);  //��ʱ��
	G_GPIO_IniStruct.GPIO_Pin = led_n->config.gpio_pin;     //���ö˿ڼ�����(ָ������)
	G_GPIO_IniStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	G_GPIO_IniStruct.GPIO_Speed =  GPIO_Speed_50MHz;	     
	GPIO_Init(led_n->config.gpio_port, &G_GPIO_IniStruct);    //��ʼ���˿ڣ�����ָ������
}	
										
										
/**************************************************************************
�������ܣ�LED�ӿڳ�ʼ��
��ڲ������� 
����  ֵ����
**************************************************************************/
void bsp_LED_Init(void)
{
	    led_init(&LedA);
			led_init(&LedB);
			led_init(&LedC);
			led_init(&Fmq);
   
	    GPIO_SetBits(LedA.config.gpio_port,LedA.config.gpio_pin);    //���
			GPIO_SetBits(LedB.config.gpio_port,LedB.config.gpio_pin);    //���
			GPIO_SetBits(LedC.config.gpio_port,LedC.config.gpio_pin);    //���
			GPIO_SetBits(Fmq.config.gpio_port,Fmq.config.gpio_pin);      //���
	        
}




/**************************************************************************
�������ܣ�LED��˸
��ڲ�������˸Ƶ�� 
����  ֵ����
**************************************************************************/
void bsp_Led_Flash(CLASS_Led* led_n,int time)
{
	if(0==time) 
	{
		digitalHi(led_n->config.gpio_port,led_n->config.gpio_pin);
	}
	else
	{
		if(time < 0)
		{
			digitalLo(led_n->config.gpio_port,led_n->config.gpio_pin);
		}
		else
		{
			if(++led_n->temp>=time)	
			{
				digitalToggle(led_n->config.gpio_port,led_n->config.gpio_pin);
				led_n->temp=0;
			}
		}
	}
}

