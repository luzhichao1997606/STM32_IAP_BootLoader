#ifndef __IAP_H_
#define __IAP_H_
#include "sys.h"

/* Define if use bkp save flag  -------------------------------*/
#define USE_BKP_SAVE_FLAG     1

#if (USE_BKP_SAVE_FLAG == 1)
  #define INIT_FLAG_DATA      0x0000  //Ĭ�ϱ�־������(��Ƭ�ӵ����)
#else
  #define INIT_FLAG_DATA      0xFFFF   //Ĭ�ϱ�־������(��Ƭ�ӵ����)
#endif
#define UPDATE_FLAG_DATA      0xEEEE   //���ر�־������
#define UPLOAD_FLAG_DATA      0xDDDD   //�ϴ���־������
#define ERASE_FLAG_DATA       0xCCCC   //������־������
#define APPRUN_FLAG_DATA      0x5A5A   //APP����Ҫ���κδ���ֱ������״̬

/* IAP command------------------------------------------------ */
#if (USE_BKP_SAVE_FLAG == 1)
  #define IAP_FLAG_ADDR    BKP_DR1
#else
  #define IAP_FLAG_ADDR   (uint32_t)(ApplicationAddress - 1024 * 2)//App�����Bootloader��������Ϣ�ĵ�ַ(�ݶ���СΪ2K)
#endif

#define IAP_FLASH_SIZE  0x3000//Bootloader�����С
#define ApplicationAddress  (STM32_FLASH_BASE + IAP_FLASH_SIZE)//Ӧ�ó����ַ

void IAP_WriteFlag(uint16_t flag);
uint16_t IAP_ReadFlag(void);
void IAP_Init(void);
void IAP_Handle(u8 * cmd);
#endif
