/*

ģ������ : ������ģ�顣
*	�ļ����� : main.c
*	��    �� : V1.0
*	˵    �� : ��ʵ����ҪѧϰFreeRTOS�Ĵ��ڵ��Է�������ӡ����ִ�������
*              ʵ��Ŀ�ģ�
*                1. ѧϰFreeRTOS�Ĵ��ڵ��Է�������ӡ����ִ���������
*                2. Ϊ�˻�ȡFreeRTOS�����ִ���������Ҫִ��������������
*					a. ��FreeRTOSConfig.h�ļ���ʹ�����º�
*                	    #define configUSE_TRACE_FACILITY	                1
*                		#define configGENERATE_RUN_TIME_STATS               1
*                		#define configUSE_STATS_FORMATTING_FUNCTIONS        1
*                		#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()    (ulHighFrequencyTimerTicks = 0ul)
*                		#define portGET_RUN_TIME_COUNTER_VALUE()            ulHighFrequencyTimerTicks
*					b. ����һ����ʱ���������ʱ����ʱ���׼����Ҫ����ϵͳʱ�ӽ��ģ������õ���������Ϣ��׼ȷ��
*                   c. ���ú���vTaskList��vTaskGetRunTimeStats���ɻ�ȡ���������ִ�������
*              ʵ�����ݣ�
*                1. ���°���K1����ͨ�����ڴ�ӡ����ִ�������������115200������λ8����żУ��λ�ޣ�ֹͣλ1��
*                   =================================================
*                   ������      ����״̬ ���ȼ�   ʣ��ջ �������
*                   vTaskUserIF     R       1       318     1
*                	IDLE            R       0       118     5
*                	vTaskLED        B       2       490     2
*                	vTaskMsgPro     B       3       490     3
*               	vTaskStart      B       4       490     4
*
*                	������       ���м���         ʹ����
*                	vTaskUserIF     467             <1%
*                	IDLE            126495          99%
*                	vTaskMsgPro     1               <1%
*                	vTaskStart      639             <1%
*                	vTaskLED        0               <1%
*                  ������������ʹ��SecureCRT��V4���������д��������鿴��ӡ��Ϣ��
*                  ��������ʵ�ֵĹ������£�
*                   vTaskTaskUserIF ����: �ӿ���Ϣ����	
*                   vTaskLED        ����: LED��˸
*                   vTaskMsgPro     ����: ��Ϣ����������������LED��˸
*                   vTaskStart      ����: ��������Ҳ����������ȼ���������ʵ�ְ���ɨ��
*                2. ��������״̬�Ķ������£������洮�ڴ�ӡ��ĸB, R, D, S��Ӧ��
*                    #define tskBLOCKED_CHAR		( 'B' )  ����
*                    #define tskREADY_CHAR		    ( 'R' )  ����
*                    #define tskDELETED_CHAR		( 'D' )  ɾ��
*                    #define tskSUSPENDED_CHAR	    ( 'S' )  ����
*              ע�����
*                 1. ��ʵ���Ƽ�ʹ�ô�������SecureCRT��Ҫ�����ڴ�ӡЧ�������롣��������
*                    V4��������������С�
*                 2. ��ؽ��༭��������������TAB����Ϊ4���Ķ����ļ���Ҫ��������ʾ�����롣
*/