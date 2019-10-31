/**
  ******************************************************************************
  * @file    bsp_dwt_delay.c
  * @author  fire
  * @version V1.0
  * @date    2017-xx-xx
  * @brief   ģ��IIC
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:˫��ʵ����-LZM
  * 
  * Wechat��qabc132321
  *
  ******************************************************************************
  */

#include "bsp_dwt_delay.h"



// 0xE000EDFC DEMCR RW Debug Exception and Monitor Control Register.
#define DEMCR           ( *(unsigned int *)0xE000EDFC )
#define TRCENA          ( 0x01 << 24) // DEMCR��DWTʹ��λ 

// 0xE0001000 DWT_CTRL RW The Debug Watchpoint and Trace (DWT) unit
#define DWT_CTRL        ( *(unsigned int *)0xE0001000 )

#define CYCCNTENA      ( 0x01 << 0 ) // DWT��SYCCNTʹ��λ

// 0xE0001004 DWT_CYCCNT RW Cycle Count register, 
#define DWT_CYCCNT      ( *(unsigned int *)0xE0001004) // ��ʾ�����ô����������ڼ���ֵ

 //#define DWT_DELAY_mS(mSec)    DWT_DELAY_uS(mSec*1000) 
 
static int SYSCLK = 0;; 

void bsp_DWT_init(int sys_clk)
{  
	DEMCR |= TRCENA;  
	DWT_CTRL |= CYCCNTENA;    
	
	SYSCLK = sys_clk; // ���浱ǰϵͳ��ʱ�����ڣ�eg. 72,000,000(72MHz). 
} 

// ΢����ʱ
void DwtDelay_uS(int uSec)
{  
	int ticks_start, ticks_end, ticks_delay;    
	ticks_start = DWT_CYCCNT;
    if ( !SYSCLK )    bsp_DWT_init( MY_MCU_SYSCLK );
	
    ticks_delay = ( uSec * ( SYSCLK / (1000*1000) ) ); // ��΢��������ɵδ��� 
	
	ticks_end = ticks_start + ticks_delay;
	
    if ( ticks_end > ticks_start )  
	{
		while( DWT_CYCCNT < ticks_end );
	}
	else // �����������ת  
	{    
		while( DWT_CYCCNT >= ticks_end ); // ��ת���ֵ�����ticks_endС    
		while( DWT_CYCCNT < ticks_end );  
    }
}

			 


































