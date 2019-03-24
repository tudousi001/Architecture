#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "itcast_comm.h"
//#include "memwatch.h"
#include "itcastlog.h"

/*
���涨����һ��socket�ͻ��˷��ͱ��Ľ��ܱ��ĵ�api�ӿ�
��д�����׽ӿ�api�ĵ��÷���
*/

/*
1 �Ȱѻ������ʵ�� �汾����
2 �ڴ�й¶���
3 ��־
4 �汾�Ż�
*/
//�����ײ�⣨�����ӿڣ����ṩ����һ�ֻ��� ��������ĳ�־���Ĳ��ԡ�

//��̬���ɿ�� 
//1 ������ҵ����ڴ��������ص���������ڵ�ַ��������

//2 ���� ���� ҵ��ģ�ͳ���
//ʵ�� ��̬�� ���ܽ���ҵ��ģ�ͳ���
typedef int (*EncData)(unsigned char *inData,int inDataLen,unsigned char *outData,int *outDataLen,void *Ref, int RefLen);
typedef int (*DecData)(unsigned char *inData,int inDataLen,unsigned char *outData,int *outDataLen,void *Ref, int RefLen);



typedef struct _SCK_HANDLE {
	char	version[16];
	char	serverip[16];
	int		serverport;
	unsigned char *	buf ;
	int				buflen;

	//wangbaoming 20140404 add
	EncData                  myEncDataFunc;
	void					*encRef;
	int						encRefLen;

	DecData                   myDecDataFunc;
	void					*decRef;
	int						decRefLen;


}SCK_HANDLE;




//�ͻ��˳�ʼ��
ITCAST_FUNC_EXPORT(int)
cltSocketInit(void **handle) //5day after
{
	SCK_HANDLE		*sh = NULL;
	int				rv = 0;

	ITCAST_LOG(__FILE__, __LINE__,LogLevel[1], rv,"func cltSocketInit() Begin");

	if (handle == NULL)
	{
		rv = -1;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketInit(): check handle == NULL [%d]", rv);
		return rv;
	}
	//�����ڴ沢��ʼ��
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		rv = -2;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketInit(): malloc err [%d]", rv);
		return rv;
	}
	memset(sh, 0, sizeof(SCK_HANDLE));

	//��ֵ
	strcpy(sh->version, "0.0.1");
	strcpy(sh->serverip, "192.168.0.211");
	sh->serverport = 8888;

	//����
	*handle = sh;

	ITCAST_LOG(__FILE__, __LINE__,LogLevel[1], rv,"func cltSocketInit() End");

	return rv;
}

//�ͻ��˷�����
ITCAST_FUNC_EXPORT(int)
cltSocketSend(void *handle, unsigned char *buf,  int buflen)
{
	int				rv = 0;
	SCK_HANDLE		*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend(): check handle == NULL [%d]", rv);
		return rv;
	}
	if (buf == NULL || buflen<=0)
	{
		rv = -5;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend(): (buf == NULL || len<=0) [%d]", rv);
		return rv;
	}
	sh = (SCK_HANDLE *)handle;
	//����м��ܻص���������ִ�лص�
	if (sh->myEncDataFunc != NULL)
	{
		sh->buf = (unsigned char *)malloc(sizeof(char)*(buflen+128));
		if (sh->buf == NULL)
		{
			return rv;
		}

		rv = sh->myEncDataFunc(buf, buflen, sh->buf, &(sh->buflen), sh->encRef, sh->encRefLen);
		if (rv != 0)
		{
			ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend(): (sh->myEncDataFunc [%d]", rv);
			return rv;
		}
	}
	else
	{
		sh->buf = (unsigned char *)malloc(sizeof(char)*buflen);
		if (sh->buf == NULL)
		{
			rv = -6;
			ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend() buflen:%d)", buflen);
			ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend() check (handle->buf == NULL)) [%d]", rv);
			return rv;
		}

		//�ѷ��͵ı������ݣ��洢 handle ������֮��
		memcpy(sh->buf, buf, buflen);
		sh->buflen = buflen;
	}
	return rv;
}
ITCAST_FUNC_EXPORT(int)
cltSocketSend_enc(void *handle, unsigned char *buf,  int buflen, EncData encDataCallbakFunc, void *ref, int refLen)
{
	int				rv = 0;
	SCK_HANDLE		*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend(): check handle == NULL [%d]", rv);
		return rv;
	}
	if (buf == NULL || buflen<=0)
	{
		rv = -5;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend(): (buf == NULL || len<=0) [%d]", rv);
		return rv;
	}
	sh = (SCK_HANDLE *)handle;
	//����м��ܻص���������ִ�лص�
	if (sh->myEncDataFunc != NULL)
	{
		sh->buf = (unsigned char *)malloc(sizeof(char)*(buflen+128));
		if (sh->buf == NULL)
		{
			return rv;
		}

		rv = encDataCallbakFunc(buf, buflen, sh->buf, &(sh->buflen), ref, refLen);
		if (rv != 0)
		{
			ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend(): (sh->myEncDataFunc [%d]", rv);
			return rv;
		}
	}
	else
	{
		sh->buf = (unsigned char *)malloc(sizeof(char)*buflen);
		if (sh->buf == NULL)
		{
			rv = -6;
			ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend() buflen:%d)", buflen);
			ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend() check (handle->buf == NULL)) [%d]", rv);
			return rv;
		}

		//�ѷ��͵ı������ݣ��洢 handle ������֮��
		memcpy(sh->buf, buf, buflen);
		sh->buflen = buflen;
	}
	return rv;
}
//�ͻ����ձ���
ITCAST_FUNC_EXPORT(int)
cltSocketRev(void *handle, unsigned char *buf, int *buflen)
{
	int			rv = 0;
	SCK_HANDLE	*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev: check handle == NULL [%d]", rv);
		return rv;
	}
	if (buflen == NULL)
	{
		rv = -5;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev: (buflen == NULL) [%d]", rv);
		return rv;
	}

	sh = (SCK_HANDLE *)handle;

	//��ֵ ���������е����ݣ�copy��buf�ռ���
	//֧�ֶ��ε��ã���һ�ε����󳤶� �ڶ��ε��ÿ��԰�����copy buf��
	if (buf != NULL)
	{
		memcpy(buf, sh->buf, sh->buflen);
		//buf[ci->buflen] = '\0';
	}
	*buflen = sh->buflen;

	return rv;
}
//�ͻ����ͷ���Դ
ITCAST_FUNC_EXPORT(int)
cltSocketDestory(void *handle)
{
	SCK_HANDLE *sh = NULL;
	sh = handle; 
	if (sh != NULL)
	{
		if (sh->encRef != NULL)  free(sh->encRef);
		if (sh->decRef != NULL)  free(sh->decRef);
		if (sh->buf != NULL) free(sh->buf);
		free(sh);
	}
	return 0;
}

/////////////////�ڶ���apiʵ��/////////////////////////////////////////////////


//�ͻ��˳�ʼ��
ITCAST_FUNC_EXPORT(int)
cltSocketInit2(void **handle) //5day after
{
	SCK_HANDLE		*sh = NULL;
	int				rv = 0;

	ITCAST_LOG(__FILE__, __LINE__,LogLevel[1], rv,"func cltSocketInit2() Begin");

	if (handle == NULL)
	{
		rv = -1;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketInit2(): check handle == NULL [%d]", rv);
		return rv;
	}
	//�����ڴ沢��ʼ��
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		rv = -2;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketInit2(): malloc err [%d]", rv);
		return rv;
	}
	memset(sh, 0, sizeof(SCK_HANDLE));

	//��ֵ
	strcpy(sh->version, "0.0.1");
	strcpy(sh->serverip, "192.168.0.211");
	sh->serverport = 8888;

	//����
	*handle = sh;

	ITCAST_LOG(__FILE__, __LINE__,LogLevel[1], rv,"func cltSocketInit2() End");

	return rv;
}

//�ͻ��˷�����
ITCAST_FUNC_EXPORT(int)
cltSocketSend2(void *handle, unsigned char *buf,  int buflen)
{
	int				rv = 0;
	SCK_HANDLE		*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend2(): check handle == NULL [%d]", rv);
		return rv;
	}
	if (buf == NULL || buflen<=0)
	{
		rv = -5;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend2(): (buf == NULL || len<=0) [%d]", rv);
		return rv;
	}

	sh = (SCK_HANDLE *)handle;
	sh->buf = (unsigned char *)malloc(sizeof(char)*buflen);
	if (sh->buf == NULL)
	{
		rv = -6;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend2() buflen:%d)", buflen);
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketSend2() check (handle->buf == NULL)) [%d]", rv);
		return rv;
	}

	//�ѷ��͵ı������ݣ��洢 handle ������֮��
	memcpy(sh->buf, buf, buflen);
	sh->buflen = buflen;

	return rv;
}
//�ͻ����ձ���
ITCAST_FUNC_EXPORT(int)
cltSocketRev2(void *handle, unsigned char **buf, int *buflen)
{
	int			rv = 0;
	SCK_HANDLE	*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev2: check handle == NULL [%d]", rv);
		return rv;
	}
	if (buflen == NULL)
	{
		rv = -5;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev2: (buflen == NULL) [%d]", rv);
		return rv;
	}
	sh = (SCK_HANDLE *)handle;


	//�����ڴ����ݴ���
	*buf = (char *)malloc(sh->buflen);
	if (*buf == NULL)
	{
		rv = -6;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev2: (buflen == NULL) [%d]", rv);
		return rv;
	}
	memcpy(*buf, sh->buf, sh->buflen);

	*buflen = sh->buflen;

	return rv;
}

ITCAST_FUNC_EXPORT(int)
cltSocketRev2_Free(unsigned char **buf)
{
	int rv = 0;
	unsigned char * tmp = *buf;
	if (buf == NULL)
	{
		rv = -7;
		ITCAST_LOG(__FILE__, __LINE__,LogLevel[4], rv,"func cltSocketRev2: (buflen == NULL) [%d]", rv);
		return rv;
	}
	if (tmp != NULL)
	{
		free(tmp);
	}
	*buf = NULL;
	return 0;
}

//�ͻ����ͷ���Դ
ITCAST_FUNC_EXPORT(int)
cltSocketDestory2(void **handle)
{
	SCK_HANDLE *sh = NULL;
	sh = *handle; 
	if (sh != NULL)
	{
		free(sh->buf);
		free(sh);
	}
	*handle = NULL;
	return 0;
}


ITCAST_FUNC_EXPORT(int)
clitSocket_SetEncFunc(void *handle, EncData encDataCallbak, void *ref, int refLen)
{
	
	SCK_HANDLE *sh = NULL;
	sh = (SCK_HANDLE *)handle;
	sh->myEncDataFunc  = encDataCallbak;

	if (refLen > 0)
	{
		sh->encRef = (void *)malloc(refLen);
		if (sh->encRef  == NULL)
		{
			return -1;
		}
		memcpy(sh->encRef, ref, refLen);
		sh->encRefLen = refLen;
	}

	return 0;
}


