/**
  ******************************************************************************
  * @file    x
  * @author  lss
  * @version V1.0
  * @date    2019-xx-xx
  * @brief   .
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:˫��ʵ����-LZM
  * 
  * Wechat��qabc132321
  *
  ******************************************************************************
  */
#ifndef __BSP_LED_H_

#define __BSP_LED_H_

#include "includes.h"  //��Ϊmain.c�е��ù���������ļ�Ҳ�����˾Ͳ����ٵ�����



//#define OFF  1
//#define ON   0



/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define digitalLo(p,i)		 {p->BRR=i;}	 //����͵�ƽ
#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬

/* �豸���� */
typedef enum
{
	LED_A,              //��
	LED_B,              //��
	LED_C,              //��
	FMQ,                //������
}LEDN_Status;

//LED���ò���
typedef struct class_led_config
{
	uint32_t      gpio_clk;
	GPIO_TypeDef* gpio_port;
	uint32_t      gpio_pin;
}CLASS_led_config;

//led��
struct class_led 
{
	u8         led_name;
	u8         flag_kg;        //led����
	int        cycle;          //led����
	int        temp;           //����Ƶ�ʼ���
	
	//dev����
	CLASS_led_config config;
	
};

//����
typedef  struct  class_led     CLASS_Led;




//�㲥
extern CLASS_Led   LedA;
extern CLASS_Led   LedB;
extern CLASS_Led   LedC;
extern CLASS_Led   Fmq;





void   bsp_LED_Init      (void);  //��ʼ��
void   bsp_Led_Flash    (CLASS_Led* led_n,int time);
#endif

