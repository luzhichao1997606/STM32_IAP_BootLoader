#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "iap.h"

int main(void)
{
	u16 times=0;  

	IAP_Init();//�������֮������ִ��iap��ʼ�� ����־λ���
	
	delay_init(72);	     //��ʱ��ʼ��
	NVIC_Configuration();//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);   //���ڳ�ʼ��Ϊ9600
 	LED_Init();	         //LED�˿ڳ�ʼ��
	while(1)
	{
		if(USART_RX_STA&0x80)
		{					 
			USART_RX_STA=0;
			IAP_Handle(USART_RX_BUF);
		}else
		{
			times++;
			if(times%50==0)LED0=!LED0;//��˸LED(PC13),��ʾϵͳ��������.
			delay_ms(5);   
		}
	}	 
}

