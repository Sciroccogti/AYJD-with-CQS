var EVENT_IGNORE = 0        //事件_忽略
var EVENT_BLOCK = 1         //事件_拦截

var REQUEST_ALLOW = 1       //请求_通过
var REQUEST_DENY = 2        //请求_拒绝

var REQUEST_GROUPADD = 1    //请求_群添加
var REQUEST_GROUPINVITE = 2 //请求_群邀请

var CQLOG_DEBUG = 0         //调试 灰色
var CQLOG_INFO = 10         //信息 黑色
var CQLOG_INFOSUCCESS = 11  //信息(成功) 紫色
var CQLOG_INFORECV = 12     //信息(接收) 蓝色
var CQLOG_INFOSEND = 13     //信息(发送) 绿色
var CQLOG_WARNING = 20      //警告 橙色
var CQLOG_ERROR = 30        //错误 红色
var CQLOG_FATAL = 40        //致命错误 深红
var HI = '公众号上有学弟学妹找你啦~快来看看吧！下面是呼叫你的账号：'
var WEL1 = '欢迎添加昆山中学2018高考答疑公众号~\n回复\"召唤命令大全\"可以浏览目前全新上线的召唤功能！'
var WEL2 = '现在公众号后台加入了机器人！\n她不仅可以跟你进行简单的对话，还能实现你的召唤！\n\n回复例如\"召唤东南大学！\"(不要忘了感叹号~)\n即可召唤对应学校的学长学姐前来回答你的问题~，快来试试吧！'
var WEL3 = '(目前仅支持：\n北大，上交，南大，东南，华科，扬大\n更多功能请等待后台学长的开发~)'

//Type=21 私聊消息
//subType 子类型，11/来自好友 1/来自在线状态 2/来自群 3/来自讨论组
var eventPrivateMsg=function(subType,sendTime,fromQQ,Msg,font){
	if (Msg == '召唤东南大学！'){
    	CQS.C_SendMsg_QQ(1325676151, HI+fromQQ);
    }else if(Msg == '召唤南京大学！'){
      	CQS.C_SendMsg_QQ(365248110, HI+fromQQ);
    }else if(Msg == '召唤北京大学！'){
      	CQS.C_SendMsg_QQ(1969793905, HI+fromQQ);
    }else if(Msg == '召唤上海交通大学！'){
      	CQS.C_SendMsg_QQ(1261179399, HI+fromQQ);
      CQS.C_SendMsg_QQ(1052796101, HI+fromQQ);
    }else if(Msg == '召唤扬州大学！'){
      	CQS.C_SendMsg_QQ(2312058479, HI+fromQQ);
    }else if(Msg == '召唤数学一号！'){
      	CQS.C_SendMsg_QQ(1052796101, HI+fromQQ);
    }else if(Msg == '召唤华中科技大学！'){
      	CQS.C_SendMsg_QQ(69422953, HI+fromQQ);
    }else if(Msg == '召唤命令大全'){
      CQS.C_SendMsg_QQ(fromQQ, WEL2);
      	CQS.C_SendMsg_QQ(fromQQ, '\"召唤\"后可接：\n北京大学！\n上海交通大学！\n南京大学！\n东南大学！\n华中科技大学！\n扬州大学！\n数学一号！');
    }
    return EVENT_IGNORE;
}

//Type=2 群消息
var eventGroupMsg=function(subType,sendTime,fromGroup,fromQQ,fromAnonymous,Msg,font){
	if (Msg == '召唤东南大学！'){
    	CQS.C_SendMsg_QQ(1325676151, HI+fromQQ);
    }else if(Msg == '召唤南京大学！'){
      	CQS.C_SendMsg_QQ(365248110, HI+fromQQ);
    }else if(Msg == '召唤北京大学！'){
      	CQS.C_SendMsg_QQ(1969793905, HI+fromQQ);
    }else if(Msg == '召唤上海交通大学！'){
      	CQS.C_SendMsg_QQ(1261179399, HI+fromQQ);
      CQS.C_SendMsg_QQ(1052796101, HI+fromQQ);
    }else if(Msg == '召唤扬州大学！'){
      	CQS.C_SendMsg_QQ(2312058479, HI+fromQQ);
    }else if(Msg == '召唤数学一号！'){
      	CQS.C_SendMsg_QQ(1052796101, HI+fromQQ);
    }else if(Msg == '召唤华中科技大学！'){
      	CQS.C_SendMsg_QQ(69422953, HI+fromQQ);
    }else if(Msg == '召唤命令大全'){
      CQS.C_SendMsg_QQ(fromQQ, WEL2);
      	CQS.C_SendMsg_QQ(fromQQ, '\"召唤\"后可接：\n北京大学！\n上海交通大学！\n南京大学！\n东南大学！\n华中科技大学！\n扬州大学！\n数学一号！');
    }
    return EVENT_IGNORE;
}

//Type=4 讨论组消息
var eventDiscussMsg=function(subType,sendTime,fromDiscuss,fromQQ,Msg,font){

    return EVENT_IGNORE;
}

// Type=101 群事件-管理员变动
// subType 子类型，1/被取消管理员 2/被设置管理员
var eventSystem_GroupAdmin=function(subType,sendTime,fromDiscuss,beingOperateQQ){

    return EVENT_IGNORE;
}

// Type=102 群事件-群成员减少
// subType 子类型，1/群员离开 2/群员被踢 3/自己(即登录号)被踢
// fromQQ 操作者QQ(仅subType为2、3时存在)
// beingOperateQQ 被操作QQ
var eventSystem_GroupMemberDecrease=function(subType,sendTime,fromDiscuss,fromQQ,beingOperateQQ){

    return EVENT_IGNORE;
}

//Type=103 群事件-群成员增加
//subType 子类型，1/管理员已同意 2/管理员邀请
//fromQQ 操作者QQ(即管理员QQ)
//beingOperateQQ 被操作QQ(即加群的QQ)
var eventSystem_GroupMemberIncrease=function(subType,sendTime,fromDiscuss,fromQQ,beingOperateQQ){

    return EVENT_IGNORE;
}

//Type=201 好友事件-好友已添加
var eventFriend_Add=function(subType,sendTime,fromQQ){
	CQS.C_SendMsg_QQ(fromQQ, WEL1);
 	CQS.C_SendMsg_QQ(fromQQ, WEL2);
  	CQS.C_SendMsg_QQ(fromQQ, WEL3);
    return EVENT_IGNORE;
}

//Type=301 请求-好友添加
//msg 附言
//responseFlag 反馈标识(处理请求用)
var eventRequest_AddFriend=function(subType,sendTime,fromQQ,Msg,responseflag){
	CQS.C_SetFriendAddRequest(responseflag, REQUEST_ALLOW, ' ');
    return EVENT_IGNORE;
}

//Type=302 请求-群添加
//subType 子类型，1/他人申请入群 2/自己(即登录号)受邀入群
//msg 附言
//responseFlag 反馈标识(处理请求用)
var eventRequest_AddGroup=function(subType,sendTime,fromGroup,fromQQ,Msg,responseflag){
	if(subType == 1 && fromGroup == 703730184){
    	CQS.C_SetGroupAddRequestV2(responseflag, REQUEST_GROUPADD, REQUEST_ALLOW, ' ');
    }
    return EVENT_IGNORE;
}