/*------------------------------------------------------------------------------

	File Name:  vc_i2c_io_interface.h

Description:  voice clean ��ʹ������Ҫ�������豸��ʵ�ֵ������ӿں���������i2c I/O����
��sleep��������voice clean ctrl api���ã���Ҫ�����ǰ��չ̶���ʱ�򣬶�/дi2c���ߺ�˯��

------------------------------------------------------------------------------*/
#include <cutils/log.h>

#ifndef VOICE_CLEAN_IIC_IO_INTERFACE_H_
#define VOICE_CLEAN_IIC_IO_INTERFACE_H_

#ifdef __cplusplus
extern "C" { 
#endif 

#include <asm-generic/ioctl.h>

#define LOGV(fmt,args...) ALOGV(fmt,##args)
#define LOGD(fmt,args...) ALOGD(fmt,##args)
#define LOGI(fmt,args...) ALOGI(fmt,##args)
#define LOGW(fmt,args...) ALOGW(fmt,##args)
#define LOGE(fmt,args...) ALOGE(fmt,##args)


#define XF6000_DEV_PATH "/proc/xf6000"
#define XF6000_IOX			'x'


typedef struct {                     
	 int offset;   
	 int size;      
	unsigned char buf[56];   
}xf6000_data;

#define XF6000_IOC_WRITE	_IOW(XF6000_IOX,0x00,unsigned long)
#define XF6000_IOC_READ		_IOWR(XF6000_IOX,0x01,unsigned long)
//#define XF6000_IOC_DELAY	_IOW(XF6000_IOX, 0x02,unsigned long)

//#define XF6000_IOC_WRITE	_IO(XF6000_IOX, 0x00)
//#define XF6000_IOC_READ		_IO(XF6000_IOX, 0x01)
//#define XF6000_IOC_DELAY	_IO(XF6000_IOX, 0x02)

// The maximum number of 32-bit data elements that a command can contain
//typedef XF600_DATE_STRUCT(13*4) xf6000_data;
/*------------------------------------------------------------------------------
  Function:   VCI2CWrite

  Purpose:    �û�ʵ�ֵĽӿں���,����Ϊ��I2C���߰��չ̶���ʱ��д����,ʱ������ͼ��
  
 |START|0x8E(8bit)|ACK|register_address��8λ|ACK|register_address��8λ|ACK|buffer[0]|ACK|buffer[1]|ACK|...|buffer[size-1]|ACK|STOP|
		

  Inputs:     register_address	- 16bit�Ŀ��Ƶ�ַ 
              buffer			- д��I2C�������ݵĴ洢��ַ
			  size				- д��I2C�������ݵĳ���, 1 for Byte

  Outputs:	  return			- succeed : 1; 
								  failed  : 0;
------------------------------------------------------------------------------*/
int VCI2CWrite(int register_address, unsigned char *buffer, int size);


/*------------------------------------------------------------------------------
  Function:   VCI2CRead

  Purpose:     �û�ʵ�ֵĽӿں���,����Ϊ��I2C���߰��չ̶���ʱ�������,ʱ������ͼ��

 |START|0x8E(8bit)|ACK|register_address��8λ|ACK|register_address��8λ|ACK|START|0x8F(8bit)|ACK|register_address��8λ|ACK|register_address��8λ|ACK|buffer[0]|ACK|buffer[1]|ACK|...|buffer[size-1]|ACK|STOP|


  Inputs:     register_address	- 16bit�Ŀ��Ƶ�ַ
              buffer			- ��I2C���߶�ȡ���ݵĴ洢��ַ
			  size				- ��I2C���߶�ȡ���ݵĳ���, 1 for Byte

  Outputs:	  return			- succeed : 1; 
								  failed  : 0;
------------------------------------------------------------------------------*/
int VCI2CRead(int register_address, unsigned char*buffer, int size);


/*------------------------------------------------------------------------------
  Function:   VCI2CSleep

  Purpose:    The I2C driver layer interface which user need to develop.This function
            just call the sleep fun on host. 

  Inputs:     intreval_ms		- time for sleep, 1 for 1 millisecond 
 
  Outputs:	  return			- void
------------------------------------------------------------------------------*/
void VCI2CSleep (int intreval_ms);
#ifdef __cplusplus
}
#endif 
#endif  // VOICE_CLEAN_IIC_IO_INTERFACE_H_

