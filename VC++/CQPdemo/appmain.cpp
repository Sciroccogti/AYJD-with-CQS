/*
* CoolQ Demo for VC++ 
* Api Version 9
* Written by Coxxs & Thanks for the help of orzFly
*/

#include "stdafx.h"
#include "string"
#include <cstring>
#include "QTool.h"
#include "cqp.h"
#include "appmain.h" //Ӧ��AppID����Ϣ������ȷ��д�������Q�����޷�����

using namespace std;

int ac = ac; //AuthCode ���ÿ�Q�ķ���ʱ��Ҫ�õ�
bool enabled = false;
char* HI = "���ں�����ѧ��ѧ��������~���������ɣ������Ǻ�������˺ţ�";
char* WEL1 = "��ӭ�����ɽ��ѧ2018�߿����ɹ��ں�~\n�ظ�\"�ٻ������ȫ\"�������Ŀǰȫ�����ߵ��ٻ����ܣ�";
char* WEL2 = "���ڹ��ںź�̨�����˻����ˣ�\n���������Ը�����м򵥵ĶԻ�������ʵ������ٻ���\n\n�ظ�����\"�ٻ����ϴ�ѧ��\"(��Ҫ���˸�̾��~)\n�����ٻ���ӦѧУ��ѧ��ѧ��ǰ���ش��������~���������԰ɣ�";
char* WEL3 = "(Ŀǰ��֧�֣�\n�����Ͻ����ϴ󣬶��ϣ����ƣ����\n���๦����ȴ���̨ѧ���Ŀ���~)";
char* WAIT = "�԰�����~ѧ��ѧ�����Ͼ͵���";

/* 
* ����Ӧ�õ�ApiVer��Appid������󽫲������
*/
CQEVENT(const char*, AppInfo, 0)() {
	return CQAPPINFO;
}


/* 
* ����Ӧ��AuthCode����Q��ȡӦ����Ϣ��������ܸ�Ӧ�ã���������������������AuthCode��
* ��Ҫ�ڱ��������������κδ��룬���ⷢ���쳣���������ִ�г�ʼ����������Startup�¼���ִ�У�Type=1001����
*/
CQEVENT(int32_t, Initialize, 4)(int32_t AuthCode) {
	ac = AuthCode;
	return 0;
}


/*
* Type=1001 ��Q����
* ���۱�Ӧ���Ƿ����ã������������ڿ�Q������ִ��һ�Σ���������ִ��Ӧ�ó�ʼ�����롣
* ��Ǳ�Ҫ����������������ش��ڡ���������Ӳ˵������û��ֶ��򿪴��ڣ�
*/
CQEVENT(int32_t, __eventStartup, 0)() {
	/*CQ_setFatal(0, "0");
	CQ_setFatal(1, "1");
	CQ_setFatal(-1, "-1");
	CQ_sendPrivateMsg(0,1325676151, "haha");
	CQ_sendPrivateMsg(1,1325676151, "haha");
	CQ_sendPrivateMsg(-1,1325676151, "haha");
	CQ_sendPrivateMsg(!ac,1325676151, "haha");*/
	return 0;
}


/*
* Type=1002 ��Q�˳�
* ���۱�Ӧ���Ƿ����ã������������ڿ�Q�˳�ǰִ��һ�Σ���������ִ�в���رմ��롣
* ������������Ϻ󣬿�Q���ܿ�رգ��벻Ҫ��ͨ���̵߳ȷ�ʽִ���������롣
*/
CQEVENT(int32_t, __eventExit, 0)() {

	return 0;
}

/*
* Type=1003 Ӧ���ѱ�����
* ��Ӧ�ñ����ú󣬽��յ����¼���
* �����Q����ʱӦ���ѱ����ã�����_eventStartup(Type=1001,��Q����)�����ú󣬱�����Ҳ��������һ�Ρ�
* ��Ǳ�Ҫ����������������ش��ڡ���������Ӳ˵������û��ֶ��򿪴��ڣ�
*/
CQEVENT(int32_t, __eventEnable, 0)() {
	enabled = true;
	//CQ_sendPrivateMsg(ac, 1325676151,"���ں������ߡ�" );
	return 0;
}


/*
* Type=1004 Ӧ�ý���ͣ��
* ��Ӧ�ñ�ͣ��ǰ�����յ����¼���
* �����Q����ʱӦ���ѱ�ͣ�ã��򱾺���*����*�����á�
* ���۱�Ӧ���Ƿ����ã���Q�ر�ǰ��������*����*�����á�
*/
CQEVENT(int32_t, __eventDisable, 0)() {
	enabled = false;
	return 0;
}


/*
* Type=21 ˽����Ϣ
* subType �����ͣ�11/���Ժ��� 1/��������״̬ 2/����Ⱥ 3/����������
*/
CQEVENT(int32_t, __eventPrivateMsg, 24)(int32_t subType, int32_t msgId, int64_t fromQQ, const char *Msg, int32_t font) {
	string a = to_string(fromQQ);
	a = HI + a;
	if (!strcmp(Msg,"�ٻ����ϴ�ѧ��")){
		CQ_sendPrivateMsg(ac,1325676151,a.c_str());
		CQ_sendPrivateMsg(ac,fromQQ, WAIT);
	}else if(!strcmp(Msg,"�ٻ��Ͼ���ѧ��")){
		CQ_sendPrivateMsg(ac,365248110, a.c_str());
		CQ_sendPrivateMsg(ac,fromQQ, WAIT);
	}else if(!strcmp(Msg,"�ٻ�������ѧ��")){
		CQ_sendPrivateMsg(ac,1969793905, a.c_str());
		CQ_sendPrivateMsg(ac,fromQQ, WAIT);
	}else if(!strcmp(Msg,"�ٻ��Ϻ���ͨ��ѧ��")){
		CQ_sendPrivateMsg(ac,1261179399, a.c_str());
		CQ_sendPrivateMsg(ac,1052796101, a.c_str());
		CQ_sendPrivateMsg(ac,fromQQ, WAIT);
	}else if(!strcmp(Msg,"�ٻ����ݴ�ѧ��")){
		CQ_sendPrivateMsg(ac,2312058479, a.c_str());
		CQ_sendPrivateMsg(ac,fromQQ, WAIT);
	}else if(!strcmp(Msg,"�ٻ���ѧһ�ţ�")){
		CQ_sendPrivateMsg(ac,1052796101, a.c_str());
		CQ_sendPrivateMsg(ac,fromQQ, WAIT);
	}else if(!strcmp(Msg,"�ٻ����пƼ���ѧ��")){
		CQ_sendPrivateMsg(ac,69422953, a.c_str());
		CQ_sendPrivateMsg(ac,fromQQ, WAIT);
	}else if(!strcmp(Msg,"�ٻ������ȫ")){
		CQ_sendPrivateMsg(ac,fromQQ, WEL2);
		CQ_sendPrivateMsg(ac,fromQQ, "\"�ٻ�\"��ɽӣ�\n������ѧ��\n�Ϻ���ͨ��ѧ��\n�Ͼ���ѧ��\n���ϴ�ѧ��\n���пƼ���ѧ��\n���ݴ�ѧ��\n��ѧһ�ţ�");
	}
	//���Ҫ�ظ���Ϣ������ÿ�Q�������ͣ��������� return EVENT_BLOCK - �ضϱ�����Ϣ�����ټ�������  ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
	//������ظ���Ϣ������֮���Ӧ��/�������������� return EVENT_IGNORE - ���Ա�����Ϣ
	return EVENT_IGNORE;
}


/*
* Type=2 Ⱥ��Ϣ
*/
CQEVENT(int32_t, __eventGroupMsg, 36)(int32_t subType, int32_t msgId, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *Msg, int32_t font) {
	/*CQTool c;
	CQ_Type_GroupMember g;
	c.GetGroupMemberInfo(ac, fromGroup, fromQQ, g);
	string a = g.nick;*/
	string a = to_string(fromQQ);
	string b = "@";
	b += a;
	b += ' ';
	b += WAIT;
	a = HI +a;
	if (!strcmp(Msg,"�ٻ����ϴ�ѧ��")){
		CQ_sendPrivateMsg(ac,1325676151,a.c_str());
		CQ_sendGroupMsg(ac,fromGroup,b.c_str());
	}else if(!strcmp(Msg,"�ٻ��Ͼ���ѧ��")){
		CQ_sendPrivateMsg(ac,365248110, a.c_str());
		CQ_sendGroupMsg(ac,fromGroup,b.c_str());
	}else if(!strcmp(Msg,"�ٻ�������ѧ��")){
		CQ_sendPrivateMsg(ac,1969793905, a.c_str());
		CQ_sendGroupMsg(ac,fromGroup,b.c_str());
	}else if(!strcmp(Msg,"�ٻ��Ϻ���ͨ��ѧ��")){
		CQ_sendPrivateMsg(ac,1261179399, a.c_str());
		CQ_sendPrivateMsg(ac,1052796101, a.c_str());
		CQ_sendGroupMsg(ac,fromGroup,b.c_str());
	}else if(!strcmp(Msg,"�ٻ����ݴ�ѧ��")){
		CQ_sendPrivateMsg(ac,2312058479, a.c_str());
		CQ_sendGroupMsg(ac,fromGroup,b.c_str());
	}else if(!strcmp(Msg,"�ٻ���ѧһ�ţ�")){
		CQ_sendPrivateMsg(ac,1052796101, a.c_str());
		CQ_sendGroupMsg(ac,fromGroup,b.c_str());
	}else if(!strcmp(Msg,"�ٻ����пƼ���ѧ��")){
		CQ_sendPrivateMsg(ac,69422953, a.c_str());
		CQ_sendGroupMsg(ac,fromGroup, b.c_str());
	}else if(!strcmp(Msg,"�ٻ������ȫ")){
		CQ_sendGroupMsg(ac,fromGroup, WEL2);
		CQ_sendGroupMsg(ac,fromGroup, "\"�ٻ�\"��ɽӣ�\n������ѧ��\n�Ϻ���ͨ��ѧ��\n�Ͼ���ѧ��\n���ϴ�ѧ��\n���пƼ���ѧ��\n���ݴ�ѧ��\n��ѧһ�ţ�");
	}
	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=4 ��������Ϣ
*/
CQEVENT(int32_t, __eventDiscussMsg, 32)(int32_t subType, int32_t msgId, int64_t fromDiscuss, int64_t fromQQ, const char *msg, int32_t font) {

	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=101 Ⱥ�¼�-����Ա�䶯
* subType �����ͣ�1/��ȡ������Ա 2/�����ù���Ա
*/
CQEVENT(int32_t, __eventSystem_GroupAdmin, 24)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t beingOperateQQ) {

	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=102 Ⱥ�¼�-Ⱥ��Ա����
* subType �����ͣ�1/ȺԱ�뿪 2/ȺԱ���� 3/�Լ�(����¼��)����
* fromQQ ������QQ(��subTypeΪ2��3ʱ����)
* beingOperateQQ ������QQ
*/
CQEVENT(int32_t, __eventSystem_GroupMemberDecrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {

	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=103 Ⱥ�¼�-Ⱥ��Ա����
* subType �����ͣ�1/����Ա��ͬ�� 2/����Ա����
* fromQQ ������QQ(������ԱQQ)
* beingOperateQQ ������QQ(����Ⱥ��QQ)
*/
CQEVENT(int32_t, __eventSystem_GroupMemberIncrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {

	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=201 �����¼�-���������
*/
CQEVENT(int32_t, __eventFriend_Add, 16)(int32_t subType, int32_t sendTime, int64_t fromQQ) {
	CQ_sendPrivateMsg(ac,fromQQ, WEL1);
	CQ_sendPrivateMsg(ac,fromQQ, WEL2);
	CQ_sendPrivateMsg(ac,fromQQ, WEL3);
	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=301 ����-�������
* msg ����
* responseFlag ������ʶ(����������)
*/
CQEVENT(int32_t, __eventRequest_AddFriend, 24)(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, const char *responseFlag) {

	CQ_setFriendAddRequest(ac, responseFlag, REQUEST_ALLOW, "");

	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=302 ����-Ⱥ���
* subType �����ͣ�1/����������Ⱥ 2/�Լ�(����¼��)������Ⱥ
* msg ����
* responseFlag ������ʶ(����������)
*/
CQEVENT(int32_t, __eventRequest_AddGroup, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *msg, const char *responseFlag) {

	if (subType == 1 && fromGroup == 703730184) {
		CQ_setGroupAddRequestV2(ac, responseFlag, REQUEST_GROUPADD, REQUEST_ALLOW, "");
	} 
	//else if (subType == 2) {
	//	CQ_setGroupAddRequestV2(ac, responseFlag, REQUEST_GROUPINVITE, REQUEST_ALLOW, "");
	//}

	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}

/*
* �˵������� .json �ļ������ò˵���Ŀ��������
* �����ʹ�ò˵������� .json ���˴�ɾ�����ò˵�
*/
CQEVENT(int32_t, __menuA, 0)() {
	MessageBoxA(NULL, "����menuA�����������봰�ڣ����߽�������������", "" ,0);
	return 0;
}

CQEVENT(int32_t, __menuB, 0)() {
	MessageBoxA(NULL, "����menuB�����������봰�ڣ����߽�������������", "" ,0);
	return 0;
}
