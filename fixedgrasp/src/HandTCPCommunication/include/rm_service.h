﻿#ifndef RM_SERVICE_H
#define RM_SERVICE_H
#include <memory>
#include <vector>
#include <string>

#include "rm_service_global.h"
#ifdef __cplusplus
extern "C" {
#include "rm_base.h"
#endif

class RM_Service
{

public:
    RM_SERVICESHARED_EXPORT RM_Service();

    ///
    /// \brief Service_RM_API_Init              API初始化
    /// \param dev_mode                 目标设备型号ARM_65/ARM_75/ARM_63_1/ARM_63_2/ARM_ECO65
    /// \param pCallback                用于接收透传接口回调函数, 不需要可以传入NULL
    ///  RM_APISHARED_EXPORT
    ///
    RM_SERVICESHARED_EXPORT int Service_RM_API_Init(int devMode, RM_Callback pCallback);

    ///
    /// \brief Service_RM_API_UnInit              API反初始化
    ///  RM_APISHARED_EXPORT
    ///
    RM_SERVICESHARED_EXPORT int Service_RM_API_UnInit();

    ///
    /// \brief Service_API_Version              查询API版本信息
    /// \return                                 API版本号
    ///
    RM_SERVICESHARED_EXPORT char * Service_API_Version();

    ///
    /// \brief Service_Arm_Socket_Start         连接机械臂
    /// \param arm_ip                   IP地址
    /// \param arm_port                 端口号
    /// \param recv_timeout             Socket连接超时时间
    /// \return                         成功返回：Socket 句柄。失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT SOCKHANDLE Service_Arm_Socket_Start(const char* const arm_ip, int arm_port, int recv_timeout);

    ///
    /// \brief Service_Arm_Socket_Close         关闭与机械臂的Socket连接
    /// \param ArmSocket                Socket句柄
    ///
    RM_SERVICESHARED_EXPORT void Service_Arm_Socket_Close(SOCKHANDLE ArmSocket);

    ///
    /// \brief Service_Arm_Socket_State         查询机械臂连接状态
    /// \param ArmSocket                Socket句柄
    /// \return                         正常返回：SYS_NORMAL 失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Arm_Socket_State(SOCKHANDLE ArmSocket);


    ///
    /// \brief Service_Set_Joint_Speed 设置关节最大速度
    /// \param ArmSocket socket句柄
    /// \param joint_num 关节序号，1~7
    /// \param speed 关节转速，单位：°/s
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Joint_Speed(SOCKHANDLE ArmSocket, byte joint_num, float speed, bool block);

    ///
    /// \brief Service_Set_Joint_Acc 设置关节最大加速度
    /// \param ArmSocket socket句柄
    /// \param joint_num 关节序号，1~7
    /// \param acc 关节转速，单位：°/s²
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Joint_Acc(SOCKHANDLE ArmSocket, byte joint_num, float acc, bool block);

    ///
    /// \brief Service_Set_Joint_Min_Pos 设置关节最小限位
    /// \param ArmSocket socket句柄
    /// \param joint_num 关节序号，1~7
    /// \param joint 关节最小位置，单位：°
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Joint_Min_Pos(SOCKHANDLE ArmSocket, byte joint_num, float joint, bool block);

    ///
    /// \brief Set_Joint_Max_Pos 设置关节最大限位
    /// \param ArmSocket socket句柄
    /// \param joint_num 关节序号，1~7
    /// \param joint 关节最大位置，单位：°
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Joint_Max_Pos(SOCKHANDLE ArmSocket, byte joint_num, float joint, bool block);

    ///
    /// \brief Service_Set_Joint_EN_State 设置关节使能状态
    /// \param ArmSocket socket句柄
    /// \param joint_num 关节序号，1~7
    /// \param state true-上使能，false-掉使能
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Joint_EN_State(SOCKHANDLE ArmSocket, byte joint_num, bool state, bool block);

    ///
    /// \brief Set_Joint_Zero_Pos 将当前位置设置为关节零位
    /// \param ArmSocket socket句柄
    /// \param joint_num 关节序号，1~7
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Joint_Zero_Pos(SOCKHANDLE ArmSocket, byte joint_num, bool block);

    ///
    /// \brief Service_Set_Joint_Err_Clear 清除关节错误代码
    /// \param ArmSocket socket句柄
    /// \param joint_num 关节序号，1~7
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Joint_Err_Clear(SOCKHANDLE ArmSocket, byte joint_num, bool block);


    ///
    /// \brief Service_Get_Joint_Speed 查询关节最大速度
    /// \param ArmSocket socket句柄
    /// \param speed 关节1~7转速数组，单位：°/s
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Speed(SOCKHANDLE ArmSocket, float *speed);

    ///
    /// \brief Service_Get_Joint_Acc 查询关节最大加速度
    /// \param ArmSocket socket句柄
    /// \param acc 关节1~7加速度数组，单位：°/s²
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Acc(SOCKHANDLE ArmSocket, float *acc);

    ///
    /// \brief Service_Get_Joint_Min_Pos 获取关节最小限位
    /// \param ArmSocket socket句柄
    /// \param min_joint 关节1~7最小位置数组，单位：°
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Min_Pos(SOCKHANDLE ArmSocket, float *min_joint);

    ///
    /// \brief Service_Get_Joint_Max_Pos 获取关节最大限位
    /// \param ArmSocket socket句柄
    /// \param max_joint 关节1~7最大位置数组，单位：°
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Max_Pos(SOCKHANDLE ArmSocket, float *max_joint);

    ///
    /// \brief Service_Get_Joint_EN_State 获取关节使能状态
    /// \param ArmSocket socket句柄
    /// \param state 关节1~7使能状态数组，1-使能状态，0-掉使能状态
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_EN_State(SOCKHANDLE ArmSocket, byte *state);

    ///
    /// \brief Service_Get_Joint_Err_Flag 获取关节Err Flag
    /// \param ArmSocket socket句柄
    /// \param state  存放关节错误码（请参考api文档中的关节错误码）
    /// \param bstate 关节抱闸状态(1代表抱闸未打开，0代表抱闸已打开)
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Err_Flag(SOCKHANDLE ArmSocket, uint16_t* state, uint16_t* bstate);

    ///
    /// \brief Service_Get_Joint_Software_Version 查询关节软件版本号
    /// \param ArmSocket socket句柄
    /// \param version                          获取到的关节软件版本号
    /// \param block                            RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                                 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Software_Version(SOCKHANDLE ArmSocket, int* version);

    ///
    /// \brief Service_Set_Arm_Line_Speed 设置机械臂末端最大线速度
    /// \param ArmSocket socket句柄
    /// \param speed 末端最大线速度，单位m/s
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Arm_Line_Speed(SOCKHANDLE ArmSocket, float speed, bool block);

    ///
    /// \brief Service_Set_Arm_Line_Acc 设置机械臂末端最大线加速度
    /// \param ArmSocket socket句柄
    /// \param acc 末端最大线加速度，单位m/s^2
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Arm_Line_Acc(SOCKHANDLE ArmSocket, float acc, bool block);

    /// \brief Service_Set_Arm_Angular_Speed 设置机械臂末端最大角速度
    /// \param ArmSocket socket句柄
    /// \param speed 末端最大角速度，单位rad/s
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Arm_Angular_Speed(SOCKHANDLE ArmSocket, float speed, bool block);

    ///
    /// \brief Service_Set_Arm_Angular_Acc 设置机械臂末端最大角加速度
    /// \param ArmSocket socket句柄
    /// \param acc 末端最大角加速度，单位rad/s^2
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Arm_Angular_Acc(SOCKHANDLE ArmSocket, float acc, bool block);

    ///
    /// \brief Service_Get_Arm_Line_Speed 获取机械臂末端最大线速度
    /// \param ArmSocket socket句柄
    /// \param speed 末端最大线速度，单位m/s
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Arm_Line_Speed(SOCKHANDLE ArmSocket, float *speed);

    ///
    /// \brief Service_Get_Arm_Line_Acc 获取机械臂末端最大线加速度
    /// \param ArmSocket socket句柄
    /// \param acc 末端最大线加速度，单位m/s^2
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Arm_Line_Acc(SOCKHANDLE ArmSocket, float *acc);

    ///
    /// \brief Service_Get_Arm_Angular_Speed 获取机械臂末端最大角速度
    /// \param ArmSocket socket句柄
    /// \param speed 末端最大角速度，单位rad/s
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Arm_Angular_Speed(SOCKHANDLE ArmSocket, float *speed);

    ///
    /// \brief Service_Get_Arm_Angular_Acc 获取机械臂末端最大角加速度
    /// \param ArmSocket socket句柄
    /// \param acc 末端最大角加速度，单位rad/s^2
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Arm_Angular_Acc(SOCKHANDLE ArmSocket, float *acc);

    ///
    /// \brief Service_Set_Arm_Tip_Init 设置机械臂末端参数为初始值
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Arm_Tip_Init(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Set_Collision_Stage 设置机械臂动力学碰撞检测等级
    /// \param ArmSocket socket句柄
    /// \param stage 等级：0~8，0-无碰撞，8-碰撞最灵敏
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Collision_Stage(SOCKHANDLE ArmSocket, int stage, bool block);

    ///
    /// \brief Service_Get_Collision_Stage 查询碰撞防护等级
    /// \param ArmSocket socket句柄
    /// \param stage    传出参数，表示等级，范围：0~8
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Collision_Stage(SOCKHANDLE ArmSocket, int *stage);

    ///
    /// \brief Service_Set_DH_Data 该函数用于重新设置DH参数，一般在标定后使用
    /// \param ArmSocket socket句柄
    /// \param lsb 相关DH参数，单位：mm
    /// \param lse 相关DH参数，单位：mm
    /// \param lew 相关DH参数，单位：mm
    /// \param lwt 相关DH参数，单位：mm
    /// \param d3  相关DH参数，单位：mm
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_DH_Data(SOCKHANDLE ArmSocket, float lsb, float lse, float lew, float lwt, float d3, bool block);

    ///
    /// \brief Service_Get_DH_Data 该函数用于获取DH参数，一般在标定后使用
    /// \param ArmSocket socket句柄
    /// \param lsb 获取到的DH参数，单位：mm
    /// \param lse 获取到的DH参数，单位：mm
    /// \param lew 获取到的DH参数，单位：mm
    /// \param lwt 获取到的DH参数，单位：mm
    /// \param d3  获取到的DH参数，单位：mm
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_DH_Data(SOCKHANDLE ArmSocket, float* lsb, float* lse, float* lew, float* lwt, float* d3);

    ///
    /// \brief Service_Set_Joint_Zero_Offset 该函数用于设置机械臂各关节零位补偿角度，一般在对机械臂零位进行标定后调用该函数
    /// \param ArmSocket socket句柄
    /// \param offset 关节1~6的零位补偿角度数组, 单位：度
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Joint_Zero_Offset(SOCKHANDLE ArmSocket, const float *offset, bool block);

    ///
    /// \brief Service_Set_Arm_Dynamic_Parm 重新设置机械臂动力学参数
    /// \param ArmSocket socket句柄
    /// \param parm     设置机械臂动力学参数，
    /// \param block    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Arm_Dynamic_Parm(SOCKHANDLE ArmSocket, const float* parm, bool block);

    ///
    /// \brief Service_Get_Tool_Software_Version        查询末端接口板软件版本号
    /// \param ArmSocket socket句柄
    /// \param version                          查询到的末端接口板软件版本号
    /// \param block                            RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                                 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Tool_Software_Version(SOCKHANDLE ArmSocket, int* version);

    /// \brief Service_Set_Arm_Servo_State 打开或者关闭控制器对机械臂伺服状态查询
    /// \param ArmSocket socket句柄
    /// \param cmd true-打开，  false-关闭
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Arm_Servo_State(SOCKHANDLE ArmSocket, bool cmd, bool block);


    ///
    /// \brief Auto_Set_Tool_Frame 六点法自动设置工具坐标系 标记点位
    /// \param ArmSocket socket句柄
    /// \param point_num 1~6代表6个标定点
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 说明：控制器只能存储十个工具，超过十个控制器不予响应，请在标定前查询已有工具
    RM_SERVICESHARED_EXPORT int Service_Auto_Set_Tool_Frame(SOCKHANDLE ArmSocket, byte point_num, bool block);

    ///
    /// \brief Service_Generate_Auto_Tool_Frame 六点法自动设置工具坐标系 提交
    /// \param ArmSocket socket句柄
    /// \param name  工具坐标系名称，不能超过十个字节。
    /// \param payload 新工具执行末端负载重量  单位kg
    /// \param x 新工具执行末端负载位置 位置x
    /// \param y 新工具执行末端负载位置 位置y
    /// \param z 新工具执行末端负载位置 位置z
    /// \param block block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Generate_Auto_Tool_Frame(SOCKHANDLE ArmSocket, const char *name,float payload,float x,float y,float z, bool block);

    ///
    /// \brief Service_Manual_Set_Tool_Frame 手动设置工具坐标系
    /// \param ArmSocket socket句柄
    /// \param name 工具坐标系名称，不能超过十个字节。
    /// \param pose 新工具执行末端相对于机械臂法兰中心的位姿
    /// \param payload 新工具执行末端负载重量  单位kg
    /// \param x 新工具执行末端负载位置 位置x
    /// \param y 新工具执行末端负载位置 位置y
    /// \param z 新工具执行末端负载位置 位置z
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 控制器只能存储十个工具，超过十个控制器不予响应，请在标定前查询已有工具
    RM_SERVICESHARED_EXPORT int Service_Manual_Set_Tool_Frame(SOCKHANDLE ArmSocket, const char *name, Pose pose,
                                                              float payload,float x,float y,float z, bool block);

    ///
    /// \brief Service_Change_Tool_Frame 切换当前工具坐标系
    /// \param ArmSocket socket句柄
    /// \param name 目标工具坐标系名称
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Change_Tool_Frame(SOCKHANDLE ArmSocket, const char *name, bool block);

    ///
    /// \brief Service_Delete_Tool_Frame 删除指定工具坐标系
    /// \param ArmSocket socket句柄
    /// \param name 要删除的工具坐标系名称
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 备注：删除坐标系后，机械臂将切换到机械臂法兰末端工具坐标系
    RM_SERVICESHARED_EXPORT int Service_Delete_Tool_Frame(SOCKHANDLE ArmSocket, const char *name, bool block);

    ///
    /// \brief Service_Set_Payload 设置末端负载质量和质心
    /// \param ArmSocket socket句柄
    /// \param payload 负载质量，单位：g，最高不超过5000g
    /// \param cx 末端负载质心位置，单位：mm
    /// \param cy 末端负载质心位置，单位：mm
    /// \param cz 末端负载质心位置，单位：mm
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    //RM_SERVICESHARED_EXPORT int Service_Set_Payload(SOCKHANDLE ArmSocket, int payload, float cx, float cy, float cz, bool block);

    ///
    /// \brief Service_Set_None_Payload 设置末端无负载
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    //RM_SERVICESHARED_EXPORT int Service_Set_None_Payload(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Get_Current_Tool_Frame 获取当前工具坐标系
    /// \param ArmSocket socket句柄
    /// \param tool 返回的坐标系
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Current_Tool_Frame(SOCKHANDLE ArmSocket, std::shared_ptr<FRAME>& tool);
    RM_SERVICESHARED_EXPORT int Service_Get_Current_Tool_Frame(SOCKHANDLE ArmSocket, FRAME* tool);

    ///
    /// \brief Service_Get_Given_Tool_Frame 获取指定工具坐标系
    /// \param ArmSocket socket句柄
    /// \param name 指定的工具名称
    /// \param tool 返回的工具参数
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Given_Tool_Frame(SOCKHANDLE ArmSocket, const char *name, std::shared_ptr<FRAME>& tool);
    RM_SERVICESHARED_EXPORT int Service_Get_Given_Tool_Frame(SOCKHANDLE ArmSocket, const char *name, FRAME* tool);

    ///
    /// \brief Service_Get_All_Tool_Frame 获取所有工具坐标系名称
    /// \param ArmSocket socket句柄
    /// \param names 返回的工具名称数组
    /// \param len   返回的工具数量
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_All_Tool_Frame(SOCKHANDLE ArmSocket, std::shared_ptr<FRAMENAME>& names, int *len);
    RM_SERVICESHARED_EXPORT int Service_Get_All_Tool_Frame(SOCKHANDLE ArmSocket, FRAME_NAME* names, int *len);

    /// \brief Service_Auto_Set_Work_Frame 三点法自动设置工作坐标系
    /// \param ArmSocket socket句柄
    /// \param name 工作坐标系名称，不能超过十个字节。
    /// \param point_num 1~3代表3个标定点，依次为原点、X轴一点、Y轴一点，4代表生成坐标系。
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 控制器只能存储十个工作坐标系，超过十个控制器不予响应，请在标定前查询已有工作坐标系
    RM_SERVICESHARED_EXPORT int Service_Auto_Set_Work_Frame(SOCKHANDLE ArmSocket, const char *name, byte point_num, bool block);

    ///
    /// \brief Service_Manual_Set_Work_Frame 手动设置工作坐标系
    /// \param ArmSocket socket句柄
    /// \param name 工作坐标系名称，不能超过十个字节。
    /// \param pose 新工作坐标系相对于基坐标系的位姿
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 控制器只能存储十个工作坐标系，超过十个控制器不予响应，请在标定前查询已有工作坐标系
    RM_SERVICESHARED_EXPORT int Service_Manual_Set_Work_Frame(SOCKHANDLE ArmSocket, const char *name, Pose pose, bool block);

    ///
    /// \brief Service_Change_Work_Frame 切换当前工作坐标系
    /// \param ArmSocket socket句柄
    /// \param name 目标工作坐标系名称
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Change_Work_Frame(SOCKHANDLE ArmSocket, const char *name, bool block);


    ///
    /// \brief Service_Delete_Work_Frame 删除指定工作坐标系
    /// \param ArmSocket socket句柄
    /// \param name 要删除的工具坐标系名称
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 备注：删除坐标系后，机械臂将切换到机械臂基坐标系
    RM_SERVICESHARED_EXPORT int Service_Delete_Work_Frame(SOCKHANDLE ArmSocket, const char *name, bool block);

    ////
    /// \brief Service_Get_Current_Work_Frame 获取当前工作坐标系
    /// \param ArmSocket socket句柄
    /// \param frame 返回的坐标系
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Current_Work_Frame(SOCKHANDLE ArmSocket, std::shared_ptr<FRAME>& frame);
    RM_SERVICESHARED_EXPORT int Service_Get_Current_Work_Frame(SOCKHANDLE ArmSocket, FRAME* frame);

    ///
    /// \brief Service_Get_Given_Work_Frame 获取指定工作坐标系
    /// \param ArmSocket socket句柄
    /// \param name 指定的工作坐标系名称
    /// \param pose 获取到的位姿
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Given_Work_Frame(SOCKHANDLE ArmSocket, char *name, std::shared_ptr<Pose>& pose);
    RM_SERVICESHARED_EXPORT int Service_Get_Given_Work_Frame(SOCKHANDLE ArmSocket, char *name, Pose* pose);

    ///
    /// \brief Service_Get_All_Work_Frame 获取所有工作坐标系名称
    /// \param ArmSocket socket句柄
    /// \param names 返回的工作坐标系名称字符数组
    /// \param len 返回的工作坐标系名称长度
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_All_Work_Frame(SOCKHANDLE ArmSocket, std::shared_ptr<FRAMENAME>& names, int *len);
    RM_SERVICESHARED_EXPORT int Service_Get_All_Work_Frame(SOCKHANDLE ArmSocket, FRAME_NAME* names, int *len);

    ///
    /// \brief Service_Get_Current_Arm_State 获取机械臂当前状态
    /// \param ArmSocket socket句柄
    /// \param joint 关节1~6角度数组
    /// \param pose 机械臂当前位姿
    /// \param Arm_Err 机械臂运行错误代码
    /// \param Sys_Err 控制器错误代码
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Current_Arm_State(SOCKHANDLE ArmSocket, float *joint, std::shared_ptr<Pose>& pose,
                                                              uint16_t *Arm_Err, uint16_t *Sys_Err);
    RM_SERVICESHARED_EXPORT int Service_Get_Current_Arm_State(SOCKHANDLE ArmSocket, float *joint, Pose* pose,
                                                              uint16_t *Arm_Err, uint16_t *Sys_Err);

    ///
    /// \brief Service_Clear_System_Err 清除系统错误代码
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Clear_System_Err(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Get_Joint_Temperature 获取关节当前温度
    /// \param ArmSocket socket句柄
    /// \param temperature 关节1~7温度数组
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Temperature(SOCKHANDLE ArmSocket, float *temperature);

    ///
    /// \brief Service_Get_Joint_Current 获取关节当前电流
    /// \param ArmSocket socket句柄
    /// \param current 关节1~7电流数组
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Current(SOCKHANDLE ArmSocket, float *current);

    ///
    /// \brief Service_Get_Joint_Voltage 获取关节当前电压
    /// \param ArmSocket socket句柄
    /// \param voltage 关节1~7电压数组
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Voltage(SOCKHANDLE ArmSocket, float *voltage);

    ///
    /// \brief Service_Get_Joint_Degree 获取当前关节角度
    /// \param ArmSocket socket句柄
    /// \param joint 当前7个关节的角度数组
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Degree (SOCKHANDLE ArmSocket, float *joint);

    ///
    /// \brief Service_Get_Arm_All_State 获取机械臂所有状态信息
    /// \param ArmSocket socket句柄
    /// \param joint_state 存储机械臂信息的结构体
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Arm_All_State(SOCKHANDLE ArmSocket, std::shared_ptr<JOINT_STATE>& joint_state);
    RM_SERVICESHARED_EXPORT int Service_Get_Arm_All_State(SOCKHANDLE ArmSocket, JOINT_STATE* joint_state);

    ///
    /// \brief Service_Get_Arm_Plan_Num             查询规划计数
    /// \param ArmSocket                    socket句柄
    /// \param plan                         查询到的规划计数
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Arm_Plan_Num(SOCKHANDLE ArmSocket, int* plan);

    ///
    /// \brief Service_Set_Arm_Init_Pose 设置机械臂的初始位置角度
    /// \param ArmSocket socket句柄
    /// \param target 机械臂初始位置关节角度数组
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Arm_Init_Pose(SOCKHANDLE ArmSocket, const float *target, bool block);

    ///
    /// \brief Service_Get_Arm_Init_Pose 获取机械臂初始位置角度
    /// \param ArmSocket socket句柄
    /// \param joint 机械臂初始位置关节角度数组
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Arm_Init_Pose(SOCKHANDLE ArmSocket, float *joint);

    ///
    /// \brief                      Service_Set_Install_Pose     设置安装方式参数
    /// \param                      ArmSocket socket句柄
    /// \param x                    旋转角
    /// \param y                    俯仰角
    /// \param z                    方位角
    /// \param block                RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                     0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Install_Pose(SOCKHANDLE ArmSocket, float x, float y, float z, bool block);

    ///
    /// \brief                      Service_Get_Install_Pose     获取安装方式参数
    /// \param                      ArmSocket socket句柄
    /// \param x                    旋转角(out)
    /// \param y                    俯仰角(out)
    /// \param z                    方位角(out)
    /// \return                     0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Install_Pose(SOCKHANDLE ArmSocket, float *fx, float *fy, float *fz);

    ///
    /// \brief Service_Movej_Cmd 关节空间运动
    /// \param ArmSocket socket句柄
    /// \param joint 目标关节1~7角度数组
    /// \param v 速度比例1~100，即规划速度和加速度占关节最大线转速和加速度的百分比
    /// \param r 轨迹交融半径，目前默认0。
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待机械臂到达位置或者规划失败
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Movej_Cmd(SOCKHANDLE ArmSocket, const float *joint,
                                                  byte v, float r, bool block);

    ///
    /// \brief Service_MoveRotate_Cmd       环绕运动
    /// \param ArmSocket                    socket句柄
    /// \param rotateAxis                   旋转轴: 1:x轴, 2:y轴, 3:z轴
    /// \param rotateAngle                  旋转角度: 旋转角度, 单位(度)
    /// \param choose_axis
    /// \param v                            速度
    /// \param r                            交融半径
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    RM_SERVICESHARED_EXPORT int Service_MoveRotate_Cmd(SOCKHANDLE ArmSocket, int rotateAxis, float rotateAngle, Pose choose_axis, byte v, float r,  bool block);

    ///
    /// \brief cartesian_tool           沿工具端位姿移动
    /// \param Joint_Cur                当前关节角度
    /// \param movelengthx:             沿X轴移动长度，米为单位
    /// \param movelengthy:             沿Y轴移动长度，米为单位
    /// \param movelengthz:             沿Z轴移动长度，米为单位
    /// \param m_dev                    机械臂型号
    /// \param v                        速度
    /// \param r                        交融半径
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回; RM_BLOCK-阻塞，等待机械臂到达位置或者规划失败
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_MoveCartesianTool_Cmd(SOCKHANDLE ArmSocket, float *Joint_Cur, float movelengthx, float movelengthy, float movelengthz, int m_dev, byte v, float r,  bool block);

    ///
    /// \brief Service_Movel_Cmd 笛卡尔空间直线运动
    /// \param ArmSocket socket句柄
    /// \param pose 目标位姿,位置单位：米，姿态单位：弧度
    /// \param v 速度比例1~100，即规划速度和加速度占机械臂末端最大线速度和线加速度的百分比
    /// \param r 轨迹交融半径，目前默认0。
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待机械臂到达位置或者规划失败
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Movel_Cmd(SOCKHANDLE ArmSocket, Pose pose, byte v, float r, bool block);

    ///
    /// \brief Service_Movec_Cmd 笛卡尔空间圆弧运动
    /// \param ArmSocket socket句柄
    /// \param pose_via 中间点位姿，位置单位：米，姿态单位：弧度
    /// \param pose_to 终点位姿
    /// \param v 速度比例1~100，即规划速度和加速度占机械臂末端最大角速度和角加速度的百分比
    /// \param r 轨迹交融半径，目前默认0。
    /// \param loop 规划圈数，目前默认0.
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待机械臂到达位置或者规划失败
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Movec_Cmd(SOCKHANDLE ArmSocket, Pose pose_via, Pose pose_to,
                                                  byte v, float r, byte loop, bool block);

    ///
    /// \brief Service_Movej_CANFD 角度不经规划，直接通过CANFD透传给机械臂
    /// \param ArmSocket socket句柄
    /// \param joint 关节1~7目标角度数组
    /// \param follow 是否高跟随
    /// \param expand 扩展关节的透传
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 只要控制器运行正常并且目标角度在可达范围内，机械臂立即返回成功指令，此时机械臂可能仍在运行；
    /// 若有错误，立即返回失败指令。
    RM_SERVICESHARED_EXPORT int Service_Movej_CANFD(SOCKHANDLE ArmSocket, const float *joint, bool follow, int expand);

    ///
    /// \brief Movep_CANFD 位姿不经规划，直接通过CANFD透传给机械臂
    /// \param ArmSocket socket句柄
    /// \param pose 位姿 (优先采用四元数表达)
    /// \param follow    是否高跟随
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Movep_CANFD(SOCKHANDLE ArmSocket, Pose pose, bool follow);

    ///
    /// \brief Service_Move_Stop_Cmd 突发状况 机械臂以最快速度急停，轨迹不可恢复
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Move_Stop_Cmd(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Move_Stop_Cmd 突发状况 机械臂缓停，轨迹不可恢复
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Move_Slow_Stop_Cmd(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Move_Pause_Cmd 轨迹暂停，暂停在规划轨迹上，轨迹可恢复
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Move_Pause_Cmd(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Move_Continue_Cmd 轨迹暂停后，继续当前轨迹运动
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Move_Continue_Cmd(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Clear_Current_Trajectory 清除当前轨迹，必须在暂停后使用，否则机械臂会发生意外！！！！
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Clear_Current_Trajectory(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Clear_All_Trajectory 清除所有轨迹，必须在暂停后使用，否则机械臂会发生意外！！！！
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Clear_All_Trajectory(SOCKHANDLE ArmSocket, bool block);

    /////
    ///// \brief Service_Get_Current_Trajectory 获取当前正在规划的轨迹信息
    ///// \param ArmSocket socket句柄
    ///// \param type 返回的规划类型
    ///// \param data 无规划和关节空间规划为当前关节1~7角度数组；笛卡尔空间规划则为当前末端位姿
    ///// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /////
    RM_SERVICESHARED_EXPORT int Service_Get_Current_Trajectory(SOCKHANDLE ArmSocket, ARM_CTRL_MODES *type, float *data);

    ///
    /// \brief Service_Movej_P_Cmd 该函数用于关节空间运动到目标位姿
    /// \param ArmSocket socket句柄
    /// \param pose: 目标位姿，位置单位：米，姿态单位：弧度。
    ///              注意：目标位姿必须是机械臂当前工具坐标系相对于当前工作坐标系的位姿，
    ///                   用户在使用该指令前务必确保，否则目标位姿会出错！！
    /// \param v: 速度比例1~100，即规划速度和加速度占机械臂末端最大线速度和线加速度的百分比
    /// \param r: 轨迹交融半径，目前默认0。
    /// \param block: RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待机械臂到达位置或者规划失败
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Movej_P_Cmd(SOCKHANDLE ArmSocket, Pose pose, byte v, float r, bool block);

    ///
    /// \brief Service_Joint_Teach_Cmd 关节示教
    /// \param ArmSocket socket句柄
    /// \param num 示教关节的序号，1~7
    /// \param direction 示教方向，0-负方向，1-正方向
    /// \param v 速度比例1~100，即规划速度和加速度占关节最大线转速和加速度的百分比
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Joint_Teach_Cmd(SOCKHANDLE ArmSocket, byte num, byte direction,
                                                        byte v, bool block);

    ///
    /// \brief Service_Pos_Teach_Cmd 当前工作坐标系下，笛卡尔空间位置示教
    /// \param ArmSocket socket句柄
    /// \param type 示教类型
    /// \param direction 示教方向，0-负方向，1-正方向
    /// \param v 速度比例1~100，即规划速度和加速度占机械臂末端最大线速度和线加速度的百分比
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Pos_Teach_Cmd(SOCKHANDLE ArmSocket, POS_TEACH_MODES type,
                                                      byte direction, byte v, bool block);

    ///
    /// \brief Service_Ort_Teach_Cmd 当前工作坐标系下，笛卡尔空间姿态示教
    /// \param ArmSocket socket句柄
    /// \param type 示教类型
    /// \param direction 示教方向，0-负方向，1-正方向
    /// \param v 速度比例1~100，即规划速度和加速度占机械臂末端最大角速度和角加速度的百分比
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Ort_Teach_Cmd(SOCKHANDLE ArmSocket, ORT_TEACH_MODES type,
                                                      byte direction, byte v, bool block);

    ///
    /// \brief Service_Teach_Stop_Cmd 示教停止
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Teach_Stop_Cmd(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Joint_Step_Cmd 关节步进
    /// \param ArmSocket socket句柄
    /// \param num 关节序号，1~7
    /// \param step 步进的角度，
    /// \param v 速度比例1~100，即规划速度和加速度占机械臂末端最大线速度和线加速度的百分比
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待机械臂返回失败或者到达位置指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Joint_Step_Cmd(SOCKHANDLE ArmSocket, byte num, float step,
                                                       byte v, bool block);

    ///
    /// \brief Service_Pos_Step_Cmd 当前工作坐标系下，位置步进
    /// \param ArmSocket socket句柄
    /// \param type 示教类型
    /// \param step 步进的距离，单位m，精确到0.001mm
    /// \param v 速度比例1~100，即规划速度和加速度占机械臂末端最大线速度和线加速度的百分比
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待机械臂返回失败或者到达位置指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Pos_Step_Cmd(SOCKHANDLE ArmSocket, POS_TEACH_MODES type, float step,
                                                     byte v, bool block);

    ///
    /// \brief Service_Ort_Step_Cmd 当前工作坐标系下，姿态步进
    /// \param ArmSocket socket句柄
    /// \param type 示教类型
    /// \param step 步进的弧度，单位rad，精确到0.001rad
    /// \param v 速度比例1~100，即规划速度和加速度占机械臂末端最大线速度和线加速度的百分比
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待机械臂返回失败或者到达位置指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Ort_Step_Cmd(SOCKHANDLE ArmSocket, ORT_TEACH_MODES type, float step,
                                                     byte v, bool block);

    ///
    /// \brief Service_Get_Controller_State 获取控制器状态
    /// \param ArmSocket socket句柄
    /// \param voltage 返回的电压
    /// \param current 返回的电流
    /// \param temperature 返回的温度
    /// \param sys_err 控制器运行错误代码
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Controller_State(SOCKHANDLE ArmSocket, float *voltage,
                                                             float *current, float *temperature, uint16_t *sys_err);

    ///
    /// \brief Service_Set_WiFi_AP_Data 开启控制器WiFi AP模式设置
    /// \param ArmSocket socket句柄
    /// \param wifi_name 控制器wifi名称
    /// \param password wifi密码
    /// \return 返回值：0-成功，失败返回:错误码, rm_define.h查询.
    /// 非阻塞模式，下发后，机械臂进入WIFI AP通讯模式
    RM_SERVICESHARED_EXPORT int Service_Set_WiFi_AP_Data(SOCKHANDLE ArmSocket, const char *wifi_name, const char* password);

    ///
    /// \brief Service_Set_WiFI_STA_Data 控制器WiFi STA模式设置
    /// \param ArmSocket socket句柄
    /// \param router_name 路由器名称
    /// \param password 路由器Wifi密码
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 非阻塞模式：设置成功后，机械臂进入WIFI STA通信模式
    RM_SERVICESHARED_EXPORT int Service_Set_WiFI_STA_Data(SOCKHANDLE ArmSocket, const char *router_name,const char* password);

    ///
    /// \brief Service_Set_USB_Data 控制器UART_USB接口波特率设置（基础系列）
    /// \param ArmSocket socket句柄
    /// \param baudrate 波特率：9600,19200,38400,115200和460800，若用户设置其他数据，控制器会默认按照460800处理。
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 非阻塞模式，设置成功后机械臂通过UART-USB接口对外通信
    RM_SERVICESHARED_EXPORT int Service_Set_USB_Data(SOCKHANDLE ArmSocket, int baudrate);

    ///
    /// \brief Service_Set_RS485 控制器RS485接口波特率设置
    /// \param ArmSocket socket句柄
    /// \param baudrate 波特率：9600,19200,38400,115200和460800，若用户设置其他数据，控制器会默认按照460800处理。
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 非阻塞模式，设置成功后机械臂通过UART-USB接口对外通信
    RM_SERVICESHARED_EXPORT int Service_Set_RS485(SOCKHANDLE ArmSocket, int baudrate);

    ///
    /// \brief Service_Get_Controller_RS485_Mode 查询控制器RS485模式
    /// \param ArmSocket socket句柄
    /// \param mode 0代表默认模式  1代表modbus主站模式
    /// \param baudrate 波特率
    /// \param timeout modbus协议超时时间，单位100ms，仅在modbus模式下提供此字段
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    RM_SERVICESHARED_EXPORT int Service_Get_Controller_RS485_Mode(SOCKHANDLE ArmSocket, int *mode, int *baudrate, int *timeout);

    ///
    /// \brief Service_Get_Tool_RS485_Mode 查询末端RS485模式
    /// \param ArmSocket socket句柄
    /// \param mode 0代表默认模式  1代表modbus主站模式
    /// \param baudrate 波特率
    /// \param timeout modbus协议超时时间，单位100ms，仅在modbus模式下提供此字段
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    RM_SERVICESHARED_EXPORT int Service_Get_Tool_RS485_Mode(SOCKHANDLE ArmSocket, int *mode, int *baudrate, int *timeout);
    ///
    /// \brief Service_Set_Ethernet 切换到以太网口工作模式
    /// \param ArmSocket socket句柄
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    /// 非阻塞模式，设置成功后机械臂通过Ethernet接口对外通信
    RM_SERVICESHARED_EXPORT int Service_Set_Ethernet(SOCKHANDLE ArmSocket);

    ///
    /// \brief Service_Set_Arm_Power 设置机械臂电源
    /// \param ArmSocket socket句柄
    /// \param cmd true-上电，   false-断电
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Arm_Power(SOCKHANDLE ArmSocket, bool cmd, bool block);

    ///
    /// \brief Service_Get_Arm_Power_State      读取机械臂电源状态
    /// \param ArmSocket                socket句柄
    /// \param power                    获取到的机械臂电源状态
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Arm_Power_State(SOCKHANDLE ArmSocket, int* power);


    ///
    /// \brief Service_Get_Arm_Software_Version     读取软件版本号
    /// \param ArmSocket                    socket句柄
    /// \param plan_version                 读取到的用户接口内核版本号
    /// \param ctrl_version                 实时内核版本号
    /// \param kernal1                      实时内核子核心1版本号
    /// \param kernal2                      实时内核子核心2版本号
    /// \param product_version              机械臂型号，仅I系列机械臂支持[-I]
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Arm_Software_Version(SOCKHANDLE ArmSocket, char* plan_version,
                                                                 char* ctrl_version, char *kernal1, char *kernal2,
                                                                 char* product_version);

    ///
    /// \brief Service_Get_System_Runtime           读取控制器的累计运行时间
    /// \param ArmSocket socket句柄
    /// \param day                          读取到的时间
    /// \param hour                         读取到的时间
    /// \param min                          读取到的时间
    /// \param sec                          读取到的时间
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_System_Runtime(SOCKHANDLE ArmSocket,int* day,
                                                           int* hour,int* min,int* sec);

    ///
    /// \brief Service_clear_system_runtime         清零控制器的累计运行时间
    /// \param ArmSocket socket句柄
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Clear_System_Runtime(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Get_Joint_Odom               读取关节的累计转动角度
    /// \param ArmSocket socket句柄
    /// \param odom                         读取到的角度值
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Joint_Odom(SOCKHANDLE ArmSocket, float* odom);

    ///
    /// \brief Service_Clear_Joint_Odom             清零关节的累计转动角度
    /// \param ArmSocket socket句柄
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Clear_Joint_Odom(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Set_High_Speed_Eth 设置高速网口（基础系列）
    /// \param ArmSocket socket句柄
    /// \param num      0-关闭  1-开启
    /// \param block block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    RM_SERVICESHARED_EXPORT int Service_Set_High_Speed_Eth(SOCKHANDLE ArmSocket, byte num, bool block);

    ///
    /// \brief Service_Get_IO_State 获取IO状态[-I]
    /// \param ArmSocket socket句柄
    /// \param num      通道号，1~4
    /// \param state    IO状态
    /// \param mode     0-通用输入模式，1-通用输出模式、2-输入开始功能复用模式、3-输入暂停功能复用模式、4-输入继续功能复用模式、5-输入急停功能复用模式、
    ///                 6-输入进入电流环拖动复用模式、7-输入进入力只动位置拖动模式（六维力版本可配置）、8-输入进入力只动姿态拖动模式（六维力版本可配置）、
    ///                 9-输入进入力位姿结合拖动复用模式（六维力版本可配置）、10-输入外部轴最大软限位复用模式（外部轴模式可配置）、
    ///                 11-输入外部轴最小软限位复用模式（外部轴模式可配置）
    /// \return         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_IO_State(SOCKHANDLE ArmSocket, byte num, byte *state, byte *mode);

    ///
    /// \brief Service_Get_IO_Input 查询所有数字和模拟IO的输入状态
    /// \param ArmSocket socket句柄
    /// \param DI_state 数字IO输入通道1~3状态数组地址，1-高，0-低
    /// \param AI_voltage 模拟IO输入通道1~4输入电压数组
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_IO_Input(SOCKHANDLE ArmSocket, int *DI_state, float *AI_voltage);

    ///
    /// \brief Service_Get_IO_Output 查询所有数字和模拟IO的输出状态
    /// \param ArmSocket socket句柄
    /// \param DO_state 数字IO输出通道1~4状态数组地址，1-高，0-低
    /// \param AO_voltage 模拟IO输出通道1~4输处电压数组
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_IO_Output(SOCKHANDLE ArmSocket, int *DO_state, float *AO_voltage);

    ///
    /// \brief Service_Set_Tool_DO_State 设置工具端数字IO输出
    /// \param ArmSocket socket句柄
    /// \param num 通道号，1~2
    /// \param state true-高，   false-低
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Tool_DO_State(SOCKHANDLE ArmSocket, byte num, bool state, bool block);

    ///
    /// \brief Service_Set_Tool_IO_Mode 设置数字IO模式输入
    /// \param ArmSocket socket句柄
    /// \param num 通道号，1~2
    /// \param state 0输入，   1输出
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Tool_IO_Mode(SOCKHANDLE ArmSocket, byte num, bool state, bool block);

    ///
    /// \brief Service_Get_Tool_IO_State 获取数字IO状态
    /// \param ArmSocket socket句柄
    /// \param IO_Mode 0-输入模式，1-输出模式
    /// \param IO_State 0-低，1-高
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Tool_IO_State(SOCKHANDLE ArmSocket, float* IO_Mode, float* IO_State);

    ///
    /// \brief Service_Set_Tool_Voltage 设置工具端电压输出
    /// \param ArmSocket socket句柄
    /// \param type 电源输出类型，0-0V，1-5V，2-12V，3-24V
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Tool_Voltage(SOCKHANDLE ArmSocket, byte type, bool block);

    ///
    /// \brief Service_Get_Tool_Voltage 查询工具端电压输出
    /// \param ArmSocket socket句柄
    /// \param voltage 电源输出类型，0-0V，1-5V，2-12V，3-24V
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Tool_Voltage(SOCKHANDLE ArmSocket, byte *voltage);

    ///
    /// \brief Service_Set_Gripper_Route 设置手爪行程
    /// \param ArmSocket socket句柄
    /// \param min_limit 手爪最小开口，范围 ：0~1000，无单位量纲 无
    /// \param max_limit 手爪最大开口，范围 ：0~1000，无单位量纲 无
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Gripper_Route(SOCKHANDLE ArmSocket, int min_limit, int max_limit, bool block);

    ///
    /// \brief Service_Set_Gripper_Release 手爪松开
    /// \param ArmSocket socket句柄
    /// \param speed 手爪松开速度 ，范围 1~1000，无单位量纲
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Gripper_Release(SOCKHANDLE ArmSocket, int speed, bool block);

    ///
    /// \brief Service_Set_Gripper_Pick 手爪力控夹取
    /// \param ArmSocket socket句柄
    /// \param speed 手爪夹取速度 ，范围 1~1000，无单位量纲 无
    /// \param force 力控阈值 ，范围 ：50~1000，无单位量纲 无
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Gripper_Pick(SOCKHANDLE ArmSocket, int speed, int force, bool block);

    ///
    /// \brief Service_Set_Gripper_Pick_On 手爪力控持续夹取
    /// \param ArmSocket socket句柄
    /// \param speed 手爪夹取速度 ，范围 1~1000，无单位量纲 无
    /// \param force 力控阈值 ，范围 ：50~1000，无单位量纲 无
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Gripper_Pick_On(SOCKHANDLE ArmSocket, int speed, int force, bool block);

    ///
    /// \brief Service_Set_Gripper_Position 设置手爪开口度
    /// \param ArmSocket socket句柄
    /// \param position 手爪开口位置 ，范围 ：1~1000，无单位量纲 无
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Gripper_Position(SOCKHANDLE ArmSocket, int position, bool block);

    ///
    /// \brief Service_Start_Drag_Teach 开始控制机械臂进入拖动示教模式
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Start_Drag_Teach(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Stop_Drag_Teach 控制机械臂退出拖动示教模式
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Stop_Drag_Teach(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Run_Drag_Trajectory 控制机械臂复现拖动示教的轨迹，必须在拖动示教结束后才能使用，
    ///                            同时保证机械臂位于拖动示教的起点位置。
    ///                            若当前位置没有位于轨迹复现起点，请先调用Drag_Trajectory_Origin，否则会返回报错信息。
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Run_Drag_Trajectory(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Pause_Drag_Trajectory 控制机械臂在轨迹复现过程中的暂停
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Pause_Drag_Trajectory(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Continue_Drag_Trajectory 控制机械臂在轨迹复现过程中暂停之后的继续，
    ///                                 轨迹继续时，必须保证机械臂位于暂停时的位置，
    ///                                 否则会报错，用户只能从开始位置重新复现轨迹。
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Continue_Drag_Trajectory(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Stop_Drag_Trajectory 控制机械臂在轨迹复现过程中的停止
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Stop_Drag_Trajectory(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Drag_Trajectory_Origin 轨迹复现前，必须控制机械臂运动到轨迹起点，
    ///                               如果设置正确，机械臂将以20%的速度运动到轨迹起点
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Drag_Trajectory_Origin(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Start_Multi_Drag_Teach       开始复合模式拖动示教
    /// \param ArmSocket socket句柄
    /// \param mode                         拖动示教模式 0-电流环模式，1-使用末端六维力，只动位置，2-使用末端六维力 ，只动姿态，
    ///                                     3-使用末端六维力，位置和姿态同时动
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Start_Multi_Drag_Teach(SOCKHANDLE ArmSocket, int mode,bool block);

    ///
    /// \brief Set_Force_Postion            力位混合控制
    /// \param ArmSocket                    socket句柄
    /// \param sensor                       0-一维力；1-六维力
    /// \param mode                         0-基坐标系力控；1-工具坐标系力控；
    /// \param direction                    力控方向；0-沿X轴；1-沿Y轴；2-沿Z轴；3-沿RX姿态方向；4-沿RY姿态方向；5-沿RZ姿态方向
    /// \param N                            力的大小，单位N
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Force_Postion(SOCKHANDLE ArmSocket, int sensor, int mode,
                                                          int direction, int N, bool block);

    ///
    /// \brief Service_Stop_Force_Postion   结束力位混合控制
    /// \param ArmSocket socket句柄
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Stop_Force_Postion(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Clear_Force_Data 将六维力数据清零，即后续获得的所有数据都是基于当前数据的偏移量
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回; RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Clear_Force_Data(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Get_Force_Data 查询当前六维力传感器得到的力和力矩信息，若要周期获取力数据
    ///                               周期不能小于50ms。
    /// \param ArmSocket socket句柄
    /// \param Force 返回的力和力矩数组地址，数组6个元素，依次为Fx，Fy，Fz, Mx, My, Mz。
    ///              其中，力的单位为N；力矩单位为Nm。
    /// \param zero_force 系统受到的外力数据
    /// \param work_zero 当前工作坐标系下系统受到的外力数据
    /// \param tool_zero 当前工具坐标系下系统受到的外力数据
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Force_Data(SOCKHANDLE ArmSocket, float *Force, float *zero_force, float *work_zero, float *tool_zero);

    ///
    /// \brief Service_Set_Force_Sensor 设置六维力重心参数，六维力重新安装后，必须重新计算六维力所收到的初始力和重心。
    ///                         该指令下发后，机械臂以20%的速度运动到各标定点，该过程不可中断，中断后必须重新标定。
    ///                         重要说明：必须保证在机械臂静止状态下标定。
    /// \param ArmSocket socket句柄
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Force_Sensor(SOCKHANDLE ArmSocket);

    ///
    /// \brief Service_Manual_Set_Force 手动设置六维力重心参数，六维力重新安装后，必须重新计算六维力所收到的初始力和重心。
    /// \param ArmSocket socket句柄
    /// \param type 点位；1~4，调用此函数四次
    /// \param joint 关节角度
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Manual_Set_Force(SOCKHANDLE ArmSocket, int type,const float* joint);

    ///
    /// \brief Service_Stop_Set_Force_Sensor 在标定六维力过程中，如果发生意外，发送该指令，停止机械臂运动，退出标定流程
    /// \param ArmSocket socket句柄
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Stop_Set_Force_Sensor(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Set_Hand_Posture 设置灵巧手目标手势
    /// \param ArmSocket socket句柄
    /// \param posture_num 预先保存在灵巧手内的手势序号，范围：1~40
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Hand_Posture(SOCKHANDLE ArmSocket, int posture_num, bool block);

    ///
    /// \brief Service_Set_Hand_Seq 设置灵巧手目标动作序列
    /// \param ArmSocket socket句柄
    /// \param seq_num 预先保存在灵巧手内的动作序列序号，范围：1~40
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Hand_Seq(SOCKHANDLE ArmSocket, int seq_num, bool block);

    ///
    /// \brief Service_Set_Hand_Angle 设置灵巧手各关节角度
    /// \param ArmSocket socket句柄
    /// \param angle 手指角度数组，6个元素分别代表6个自由度的角度。范围：0~1000.另外，-1代表该自由度不执行任何操作，保持当前状态
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Hand_Angle(SOCKHANDLE ArmSocket, const int *angle, bool block);

    ///
    /// \brief Service_Set_Hand_Speed 设置灵巧手各关节速度
    /// \param ArmSocket socket句柄
    /// \param speed 灵巧手各关节速度设置，范围：1~1000
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Hand_Speed(SOCKHANDLE ArmSocket, int speed, bool block);

    ///
    /// \brief Service_Set_Hand_Force 设置灵巧手各关节力阈值
    /// \param ArmSocket socket句柄
    /// \param force 灵巧手各关节力阈值设置，范围：1~1000，代表各关节的力矩阈值（四指握力0~10N，拇指握力0~15N）。
    /// \param block RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Hand_Force(SOCKHANDLE ArmSocket, int force, bool block);

    ///
    /// \brief Service_Get_Fz 该函数用于查询末端一维力数据
    /// \param ArmSocket socket句柄
    /// \param 反馈的一维力数据 单位：N
    /// \param work_zero 当前工作坐标系下系统受到的外力数据
    /// \param tool_zero 当前工具坐标系下系统受到的外力数据
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Fz(SOCKHANDLE ArmSocket, float *Fz, float *zero_Fz, float *work_zero, float *tool_zero);

    ///
    /// \brief Service_Clear_Fz 该函数用于清零末端一维力数据
    /// \param ArmSocket socket句柄
    /// \param RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Clear_Fz(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Auto_Set_Fz 该函数用于自动一维力数据
    /// \param ArmSocket socket句柄
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Auto_Set_Fz(SOCKHANDLE ArmSocket);

    ///
    /// \brief Service_Manual_Set_Fz 该函数用于手动设置一维力数据
    /// \param ArmSocket socket句柄
    /// \param 点位数  0~4
    /// \param 关节角度
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Manual_Set_Fz(SOCKHANDLE ArmSocket, const float* joint1,const float* joint2);

    ///
    /// \brief Service_Set_Modbus_Mode 配置通讯端口 Modbus RTU 模式
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器 RS485 端口，1-末端接口板 RS485 接口
    /// \param baudrate: 波特率，支持 9600,115200,460800 三种常见波特率
    /// \param timeout: 超时时间，单位秒。
    /// \param block: RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Modbus_Mode(SOCKHANDLE ArmSocket, int port,int baudrate,int timeout,bool block);

    ///
    /// \brief Service_Close_Modbus_Mode 关闭通讯端口 Modbus RTU 模式
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器 RS485 端口，1-末端接口板 RS485 接口
    /// \param block: RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Close_Modbus_Mode(SOCKHANDLE ArmSocket, int port,bool block);

    ///
    /// \brief Service_Get_Read_Coils 读线圈
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器 RS485 端口，1-末端接口板 RS485 接口
    /// \param address: 线圈起始地址
    /// \param num: 要读的线圈的数量，该指令最多一次性支持读 8 个线圈数据，即返回的数据不会超过一个字节
    /// \param device: 外设设备地址
    /// \param coils_data: 返回离散量
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Read_Coils(SOCKHANDLE ArmSocket, int port,int address,int num,
                                                       int device,int *coils_data);

    ///
    /// \brief 读多圈数据 read_multiple_coils
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器 RS485 端口，1-末端接口板 RS485 接口
    /// \param address: 线圈起始地址
    /// \param num: 8< num <= 120 要读的线圈的数量，该指令最多一次性支持读 120 个线圈数据， 即15个byte
    /// \param device: 外设设备地址
    /// \param coils_data: 返回离散量
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Read_Multiple_Coils(SOCKHANDLE ArmSocket, int port,int address,int num,
                                                                int device,int *coils_data, int len);
    RM_SERVICESHARED_EXPORT int Service_Get_Read_Multiple_Coils(SOCKHANDLE ArmSocket, int port,int address,int num,
                                                             int device,int *coils_data);

    ///
    /// \brief Service_Get_Read_Input_Status 读离散量输入
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器 RS485 端口，1-末端接口板 RS485 接口
    /// \param address: 线圈起始地址
    /// \param num: 要读的线圈的数量，该指令最多一次性支持读 8 个线圈数据，即返回的数据不会一个字节
    /// \param device: 外设设备地址
    /// \param coils_data: 返回离散量
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Read_Input_Status(SOCKHANDLE ArmSocket, int port,int address,int num,
                                                              int device,int* coils_data);

    ///
    /// \brief Service_Get_Read_Holding_Registers 读保持寄存器
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器 RS485 端口，1-末端接口板 RS485 接口
    /// \param address: 线圈起始地址
    /// \param device: 外设设备地址
    /// \param coils_data: 返回离散量
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Read_Holding_Registers(SOCKHANDLE ArmSocket, int port,int address,
                                                                   int device,int* coils_data);

    ///
    /// \brief Service_Get_Read_Input_Registers 读输入寄存器
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器 RS485 端口，1-末端接口板 RS485 接口
    /// \param address: 线圈起始地址
    /// \param device: 外设设备地址
    /// \param coils_data: 返回离散量
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Read_Input_Registers(SOCKHANDLE ArmSocket, int port,int address,
                                                                 int device,int* coils_data);

    ///
    /// \brief Service_Write_Single_Coil 写单圈数据
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器 RS485 端口，1-末端接口板 RS485 接口
    /// \param address: 线圈起始地址
    /// \param data: 要写入线圈的数据，数据类型：int16
    /// \param device: 外设设备地址
    /// \param block: RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Write_Single_Coil(SOCKHANDLE ArmSocket, int port, int address,
                                                          int16_t data, int device, bool block);

    ///
    /// \brief Service_Write_Coils 写多圈数据
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器RS485端口，1-末端接口板RS485接口
    /// \param address: 线圈起始地址
    /// \param num: 写线圈个数，每次写的数量不超过160个
    /// \param data: 要写入线圈的数据数组，类型：byte。若线圈个数不大于8，则写入的数据为1个字节；否则，则为多个数据的数组
    /// \param device: 外设设备地址
    /// \param block: RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Write_Coils(SOCKHANDLE ArmSocket, int port,int address,int num,
                                                    byte * coils_data,int len, int device,bool block);
    RM_SERVICESHARED_EXPORT int Service_Write_Coils(SOCKHANDLE ArmSocket, int port,int address,int num,
                                                    byte * coils_data,int device,bool block);

    ///
    /// \brief Service_Write_Single_Register 写单个寄存器
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器 RS485 端口，1-末端接口板 RS485 接口
    /// \param address: 线圈起始地址
    /// \param data: 要写入寄存器的数据，数据类型：int16
    /// \param device: 外设设备地址
    /// \param block: RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Write_Single_Register(SOCKHANDLE ArmSocket, int port, int address,
                                                              int16_t data, int device, bool block);

    ///
    /// \brief Service_Write_Registers 写多个寄存器
    /// \param ArmSocket socket句柄
    /// \param port: 通讯端口，0-控制器 RS485 端口，1-末端接口板 RS485 接口
    /// \param address: 寄存器起始地址
    /// \param num: 写寄存器个数，寄存器每次写的数量不超过10个
    /// \param data: 要写入寄存器的数据数组，类型：byte
    /// \param device: 外设设备地址
    /// \param block: RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return 0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Write_Registers(SOCKHANDLE ArmSocket, int port,int address,int num,
                                                        byte *single_data, int len, int device, bool block);
    RM_SERVICESHARED_EXPORT int Service_Write_Registers(SOCKHANDLE ArmSocket, int port,int address,int num,
                                                        byte *single_data, int device, bool block);

    ///
    /// \brief Service_Set_Lift_Speed           速度开环控制
    /// \param ArmSocket                socket句柄
    /// \param speed                    speed-速度百分比，-100 ~100
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Lift_Speed(SOCKHANDLE ArmSocket, int speed);

    ///
    /// \brief Service_Set_Lift_Height          位置闭环控制
    /// \param ArmSocket                socket句柄
    /// \param height                   目标高度，单位mm，范围：0~2600
    /// \param speed                    速度百分比，1~100
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Lift_Height(SOCKHANDLE ArmSocket, int height, int speed, bool block);

    ///
    /// \brief Service_Get_Lift_State           获取升降机构状态
    /// \param ArmSocket socket句柄
    /// \param height                   当前升降机构高度，单位：mm，精度：1mm，范围：0~2300
    /// \param current                  当前升降驱动电流，单位：mA，精度：1mA
    /// \param err_flag                 升降驱动错误代码，错误代码类型参考关节错误代码
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Lift_State(SOCKHANDLE ArmSocket, int* height,int* current,int* err_flag);

    ///
    /// \brief Service_Expand_Set_Version   扩展关节模式设置
    /// \param ArmSocket                socket句柄
    /// \param version                  0：表示关闭, 2：表示打开
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Expand_Set_Version(SOCKHANDLE ArmSocket, int version);

    ///
    /// \brief Service_Expand_Get_Version           扩展关节模式读
    /// \param ArmSocket                socket句柄
    /// \param version                  2：表示开启 其他表示未启动
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Expand_Get_Version(SOCKHANDLE ArmSocket, int* version);
    ///
    /// \brief Service_Expand_Get_State   扩展关节状态获取
    /// \param ArmSocket                socket句柄
    /// \param pos                      当前升降机构高度，单位：mm，精度：1mm，如果是旋转关节则为角度 单位度，精度0.001°
    /// \param err_flag                 升降驱动错误代码，错误代码类型参考关节错误代码
    /// \param current                  当前升降驱动电流，单位：mA，精度：1mA
    /// \param mode                     当前升降状态，0-空闲，1-正方向速度运动，2-正方向位置运动，3-负方向速度运动，4-负方向位置运动
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Expand_Get_State(SOCKHANDLE ArmSocket, int* pos, int* err_flag, int* current, int* mode);
    ///
    /// \brief Service_Expand_Config    扩展关节参数配置
    /// \param ArmSocket                socket句柄
    /// \param rpm_max                  关节的最大速度
    /// \param rpm_acc                  最大加速度
    /// \param conversin_coe            减速比
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Expand_Config(SOCKHANDLE ArmSocket, int rpm_max, int rpm_acc, int conversin_coe);
    ///
    /// \brief Service_Expand_Get_Config        扩展关节参数获取
    /// \param ArmSocket                socket句柄
    /// \param config                   扩展关节参数
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Expand_Get_Config(SOCKHANDLE ArmSocket, std::shared_ptr<ExpandConfig>& config);
    RM_SERVICESHARED_EXPORT int Service_Expand_Get_Config(SOCKHANDLE ArmSocket, ExpandConfig* config);

    ///
    /// \brief Service_Expand_Set_Speed         扩展关节速度环控制
    /// \param ArmSocket                socket句柄
    /// \param speed                    -50 表示最大速度的百分之五十反方向运动
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Expand_Set_Speed(SOCKHANDLE ArmSocket,int speed, bool block);

    ///
    /// \brief Service_Expand_Set_Pos           扩展关节位置环控制
    /// \param ArmSocket                socket句柄
    /// \param pos                      升降关节 1mm   旋转关节表示 0.001°
    /// \param speed                    50 表示最大速度的百分之五十,且速度必须大于0
    /// \param block                    RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                         0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Expand_Set_Pos(SOCKHANDLE ArmSocket, int pos,int speed,bool block);

    ///
    /// \brief Service_Start_Force_Position_Move    开启透传力位混合控制补偿模式
    /// \param ArmSocket                    socket句柄
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Start_Force_Position_Move(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Force_Position_Move_Pose          透传力位混合补偿（透传位姿）
    /// \param ArmSocket                    socket句柄
    /// \param pose                         当前坐标系下目标位姿
    /// \param sensor                       所使用传感器类型，0-一维力，1-六维力
    /// \param mode                         模式，0-沿基坐标系，1-沿工具端坐标系
    /// \param dir                          力控方向，0~5分别代表X/Y/Z/Rx/Ry/Rz，其中一维力类型时默认方向为Z方向
    /// \param force                        力的大小 单位N
    /// \param follow                       表示驱动器的运动跟随效果，true为高跟随，false为低跟随
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Force_Position_Move_Pose(SOCKHANDLE ArmSocket, Pose pose, byte sensor,
                                                                 byte mode, int dir, float force, bool follow);

    ///
    /// \brief Service_Force_Position_Move_Joint          透传力位混合补偿（透传关节角度）
    /// \param ArmSocket                    socket句柄
    /// \param joint                        目标关节角度
    /// \param sensor                       所使用传感器类型，0-一维力，1-六维力
    /// \param mode                         模式，0-沿基坐标系，1-沿工具端坐标系
    /// \param dir                          力控方向，0~5分别代表X/Y/Z/Rx/Ry/Rz，其中一维力类型时默认方向为Z方向
    /// \param force                        力的大小 单位N
    /// \param follow                       表示驱动器的运动跟随效果，true为高跟随，false为低跟随
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    RM_SERVICESHARED_EXPORT int Service_Force_Position_Move_Joint(SOCKHANDLE ArmSocket, const float *joint, byte sensor,
                                                                  byte mode, int dir, float force, bool follow);

    ///
    /// \brief Service_Stop_Force_Position_Move     停止透传力位混合控制补偿模式
    /// \param ArmSocket                    socket句柄
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Stop_Force_Position_Move(SOCKHANDLE ArmSocket, bool block);

    ///
    /// \brief Service_Set_Teach_Frame              切换示教运动坐标系
    /// \param ArmSocket                    socket句柄
    /// \param type                         0: 基座标运动, 1: 工具坐标系运动
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Teach_Frame(SOCKHANDLE ArmSocket, int type, bool block);

    ///
    /// \brief Service_Send_TrajectoryFile      轨迹文件下发
    /// \param ArmSocket                    socket句柄
    /// \param file_name                    轨迹文件完整路径 例: c:/rm_file.txt
    /// \param file_name_len                file_name 字段的长度
    /// \param plan_speed                   规划速度比例(0-100)
    /// \param auto_start                   设置默认在线编程文件 1-设置默认  0-设置非默认[-I]
    /// \param step_flag                    设置单步运行方式模式 1-设置单步模式  0-设置正常运动模式[-I]
    /// \param err_line                     有问题的工程行数
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Send_TrajectoryFile(SOCKHANDLE ArmSocket, const char * file_name,
                                                            int file_name_len, int plan_speed,
                                                            byte auto_start, byte step_flag, int * err_line);

    /***************************************新加接口***************************************/

    ///
    /// \brief Set_Plan_Speed               轨迹规划中改变速度比例系数
    /// \param ArmSocket                    socket句柄
    /// \param speed                        当前进度条的速度数据
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Plan_Speed(SOCKHANDLE ArmSocket, int speed, bool block);

    ///
    /// \brief Popup                        文件树弹窗提醒(本指令是控制器发送给示教器，返回值是示教器发送给控制器)
    /// \param ArmSocket                    socket句柄
    /// \param content                      弹窗提示指令所在文件树的位置
    /// \param block                        RM_NONBLOCK-非阻塞，发送后立即返回；RM_BLOCK-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Popup(SOCKHANDLE ArmSocket, int content, bool block);

    ///
    /// \brief Service_Get_Program_Trajectory_List  查询在线编程程序列表
    /// \param ArmSocket                    socket句柄
    /// \param programlist                  在线编程程序列表
    ///                                     page_num:页码（全部查询时此参数传NULL）
    ///                                     page_size:每页大小（全部查询时此参数传NULL）
    ///                                     vague_search:模糊搜索 （传递此参数可进行模糊查询）
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Program_Trajectory_List(SOCKHANDLE ArmSocket, int page_num, int page_size, char *vague_search, std::shared_ptr<ProgramTrajectoryData> &programlist);
    RM_SERVICESHARED_EXPORT int Service_Get_Program_Trajectory_List(SOCKHANDLE ArmSocket, ProgramTrajectoryData* programlist);

    ///
    /// \brief Service_Get_Program_Run_State        查询在线编程程序运行状态
    /// \param ArmSocket                    socket句柄
    /// \param run_state                    0 未开始 1运行中 2暂停中
    /// \param id                           运行轨迹编号，已存储轨迹 的id，没有存储则为0 ，未运行则不返回
    /// \param plan_num                     运行到的行数，未运行则不返回
    /// \param loop_num                     存在循环指令的行数，未运行则不返回
    /// \param loop_cont                    循环指令行数对应的运行次数，未运行则不返回
    /// \param len                          循环指令数量，无循环指令则传入0（MATLAB API使用）
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Program_Run_State(SOCKHANDLE ArmSocket, int *run_state, int *id, int *plan_num, int *loop_num, int *loop_cont, int len);
    RM_SERVICESHARED_EXPORT int Service_Get_Program_Run_State(SOCKHANDLE ArmSocket, int *run_state, int *id, int *plan_num, int *loop_num, int *loop_cont);

    ///
    /// \brief Service_Set_Program_ID_Start         开始运行指定编号轨迹
    /// \param ArmSocket                    socket句柄
    /// \param id                           运行指定的ID，1-100，存在轨迹可运行
    /// \param speed                        1-100，需要运行轨迹的速度，可不提供速度比例，按照存储的速度运行
    /// \param block                        0-非阻塞，开始运行后返回；1-阻塞，等待在线编程程序运行结束返回
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Program_ID_Start(SOCKHANDLE ArmSocket, int id, int speed, bool block);

    ///
    /// \brief Service_Delete_Program_Trajectory    删除指定编号轨迹
    /// \param ArmSocket                    socket句柄
    /// \param id                           可删除指定ID的轨迹
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Delete_Program_Trajectory(SOCKHANDLE ArmSocket, int id);

    ///
    /// \brief Service_Set_High_Ethernet            设置高速网口网络配置[配置通讯内容]（基础系列）
    /// \param ArmSocket                    socket句柄
    /// \param ip                           网络地址
    /// \param mask                         子网掩码
    /// \param gateway                      网关
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_High_Ethernet(SOCKHANDLE ArmSocket, const char * ip,
                                                          const char * mask, const char * gateway);

    ///
    /// \brief Get_High_Ethernet            获取高速网口网络配置[配置通讯内容]（基础系列）
    /// \param ArmSocket                    socket句柄
    /// \param ip                           网络地址
    /// \param mask                         子网掩码
    /// \param gateway                      网关
    /// \param mac                          MAC地址
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_High_Ethernet(SOCKHANDLE ArmSocket, char * ip,
                                                          char * mask, char * gateway, char * mac);

    ///
    /// \brief Save_Device_Info_All         保存所有参数（基础系列）
    /// \param ArmSocket                    socket句柄
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Save_Device_Info_All(SOCKHANDLE ArmSocket);

    ///
    /// \brief Set_NetIP                    配置有线网卡IP地址[-I]
    /// \param ArmSocket                    socket句柄
    /// \param ip                           网络地址
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_NetIP(SOCKHANDLE ArmSocket, const char * ip);

    ///
    /// \brief Get_Wired_Net                查询有线网卡网络信息[-I]
    /// \param ArmSocket                    socket句柄
    /// \param ip                           网络地址
    /// \param mask                         子网掩码
    /// \param mac                          MAC地址
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Wired_Net(SOCKHANDLE ArmSocket, char * ip, char * mask, char * mac);

    ///
    /// \brief Get_Wifi_Net                 查询无线网卡网络信息[-I]
    /// \param ArmSocket                    socket句柄
    /// \param network                      无线网卡网络信息结构体
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Wifi_Net(SOCKHANDLE ArmSocket, std::shared_ptr<WiFi_Info>& network);
    RM_SERVICESHARED_EXPORT int Service_Get_Wifi_Net(SOCKHANDLE ArmSocket, WiFi_Info* network);

    ///
    /// \brief Set_Net_Default              恢复网络出厂设置[-I]
    /// \param ArmSocket                    socket句柄
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Net_Default(SOCKHANDLE ArmSocket);

    ///
    /// \brief Get_Multi_Holding_Registers  读多个保存寄存器
    /// \param ArmSocket                    socket句柄
    /// \param port                         通讯端口[0/1]
    /// \param address                      寄存器起始地址
    /// \param num                          要读的寄存器数量[2 < num < 17]
    /// \param device                       外设设备地址
    /// \param coils_data                   线圈状态
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Read_Multiple_Holding_Registers(SOCKHANDLE ArmSocket, int port, int address,
                                                             int num, int device, int *coils_data, int len);
    RM_SERVICESHARED_EXPORT int Service_Read_Multiple_Holding_Registers(SOCKHANDLE ArmSocket, int port, int address,
                                                                        int num, int device, int *coils_data);

    ///
    /// \brief Set_IO_Mode                  设置数字IO模式[-I]
    /// \param ArmSocket                    socket句柄
    /// \param io_num                       IO端口号，范围：1~4
    /// \param io_mode                      0-通用输入模式，1-通用输出模式、2-输入开始功能复用模式、3-输入暂停功能复用模式、4-输入继续功能复用模式、5-输入急停功能复用模式、
    ///                                     6-输入进入电流环拖动复用模式、7-输入进入力只动位置拖动模式（六维力版本可配置）、8-输入进入力只动姿态拖动模式（六维力版本可配置）、
    ///                                     9-输入进入力位姿结合拖动复用模式（六维力版本可配置）、10-输入外部轴最大软限位复用模式（外部轴模式可配置）、
    ///                                     11-输入外部轴最小软限位复用模式（外部轴模式可配置）
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_IO_Mode(SOCKHANDLE ArmSocket, byte io_num, byte io_mode);

    ///
    /// \brief Service_Set_DO_State         设置数字IO输出
    /// \param ArmSocket                    socket句柄
    /// \param io_num                       通道号，1~4
    /// \param state                        IO状态，true-高，false-低
    /// \param block                        0-非阻塞，发送后立即返回；1-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_DO_State(SOCKHANDLE ArmSocket, byte io_num, bool state, bool block);

    ///
    /// \brief Service_Get_DO_State         查询数字IO输出状态（基础系列）
    /// \param ArmSocket                    socket句柄
    /// \param io_num                       通道号，1~4
    /// \param state                        指定数字IO通道返回的状态，1-高，   0-低
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_DO_State(SOCKHANDLE ArmSocket, byte io_num, byte *state);

    ///
    /// \brief Service_Get_DI_State         查询数字IO输入状态（基础系列）
    /// \param ArmSocket                    socket句柄
    /// \param io_num                       通道号，1~3
    /// \param state                        指定数字IO通道返回的状态，1-高，   0-低
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_DI_State(SOCKHANDLE ArmSocket, byte io_num, byte *state);

    ///
    /// \brief Service_Set_AO_State         设置模拟IO输出（基础系列）
    /// \param ArmSocket                    socket句柄
    /// \param io_num                       通道号，1~4
    /// \param voltage                      IO输出电压，分辨率0.001V，范围：0~10000，代表输出电压0v~10v
    /// \param block                        0-非阻塞，发送后立即返回；1-阻塞，等待控制器返回设置成功指令
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_AO_State(SOCKHANDLE ArmSocket, byte io_num, float voltage, bool block);

    ///
    /// \brief Service_Get_AO_State         查询模拟IO输出状态（基础系列）
    /// \param ArmSocket                    socket句柄
    /// \param io_num                       通道号，1~4
    /// \param voltage                      IO输出电压，分辨率0.001V，范围：0~10000，代表输出电压0v~10v
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_AO_State(SOCKHANDLE ArmSocket, byte io_num, byte *voltage);

    ///
    /// \brief Service_Get_AI_State         查询模拟IO输入状态（基础系列）
    /// \param ArmSocket                    socket句柄
    /// \param io_num                       通道号，1~4
    /// \param voltage                      IO输入电压，分辨率0.001V，范围：0~10000，代表输入电压0v~10v
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_AI_State(SOCKHANDLE ArmSocket, byte io_num, byte *voltage);

    ///
    /// \brief Service_Set_Voltage          设置电源输出[-I]
    /// \param ArmSocket                    socket句柄
    /// \param voltage_type                 电源输出类型，范围：0~3(0-0V，2-12V，3-24V)
    /// \param start_enable                 true-开机启动时即输出此配置电压，false-取消开启启动配置电压
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Voltage(SOCKHANDLE ArmSocket, byte voltage_type, bool start_enable);

    ///
    /// \brief Service_Get_Voltage                  获取电源输出类型[-I]
    /// \param ArmSocket                    socket句柄
    /// \param voltage_type                 电源输出类型，范围：0~3(0-0V，2-12V，3-24V)
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Voltage(SOCKHANDLE ArmSocket, byte * voltage_type);

    ///
    /// \brief Service_Save_Trajectory              获取刚拖动过的轨迹，在拖动示教后调用
    /// \param ArmSocket                    socket句柄
    /// \param file_name                    轨迹要保存路径及名称，例: c:/rm_test.txt
    /// \param num                          轨迹点数
    /// \return                             0-成功，失败返回:错误码, rm_define.h查询.
    ///
    RM_SERVICESHARED_EXPORT int Service_Save_Trajectory(SOCKHANDLE ArmSocket, char * filename, int* num);
    ///
    /// \brief Service_Get_Realtime_Push            获取主动上报接口配置
    /// \param ArmSocket                    socket句柄
    /// \param cycle                        获取广播周期，为5ms的倍数
    /// \param port                         获取广播的端口号
    /// \param enable                       获取使能，是否使能主动上上报
    /// \param force_coordinate             获取系统外受力数据的坐标系(仅带有力传感器的机械臂支持)
    /// \param ip                           获取自定义的上报目标IP地址
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Realtime_Push(SOCKHANDLE ArmSocket, int* cycle, int* port, bool* enable, int* force_coordinate, char* ip);

    ///
    /// \brief Service_Set_Realtime_Push            设置主动上报接口配置
    /// \param cycle                        设置广播周期，为5ms的倍数
    /// \param port                         设置广播的端口号
    /// \param enable                       设置使能，是否使能主动上上报
    /// \param force_coordinate             设置系统外受力数据的坐标系(仅带有力传感器的机械臂支持)
    /// \param ip                           设置自定义的上报目标IP地址
    ///
    RM_SERVICESHARED_EXPORT int Service_Set_Realtime_Push(SOCKHANDLE ArmSocket, int cycle, int port, bool enable, int force_coordinate, const char* ip);

    ///
    /// \brief Service_Realtime_Arm_Joint_State     机械臂状态主动上报
    /// \param RobotStatuscallback          接收机械臂状态信息回调函数
    ///
    RM_SERVICESHARED_EXPORT void Service_Realtime_Arm_Joint_State(RobotStatusListener RobotStatuscallback);

    ///
    /// \brief Service_Get_Realtime_Arm_Joint_State     获取实时机械臂状态上报
    /// \param RobotStatus                      机械臂状态
    ///
    RM_SERVICESHARED_EXPORT int Service_Get_Realtime_Arm_Joint_State(std::shared_ptr<RobotStatus>& RobotStatus);
    RM_SERVICESHARED_EXPORT int Service_Get_Realtime_Arm_Joint_State(RobotStatus* RobotStatus);


    //*************************************算法封装*************************************
    ///
    /// \brief Algo_Init_Sys_Data       初始化算法依赖数据(不连接机械臂时调用, 连接机械臂会自动调用)
    /// \param dMode                    机械臂型号
    /// \param bType                    传感器型号
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Init_Sys_Data(RobotType dMode, SensorType bType);

    ///
    /// \brief Algo_Set_Angle           设置安装角度
    /// \param x                        X轴安装角度 单位°
    /// \param y                        Y轴安装角度 单位°
    /// \param z                        z轴安装角度 单位°
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Set_Angle(float x, float y, float z);

    ///
    /// \brief Algo_Get_Angle           获取安装角度
    /// \param x                        X轴安装角度 单位°
    /// \param y                        Y轴安装角度 单位°
    /// \param z                        z轴安装角度 单位°
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Get_Angle(float* x, float* y, float* z);

    ///
    /// \brief  Algo_Forward_Kinematics 正解函数
    /// \param  joint                   关节1到关节6角度 单位°
    /// \return Pose                    目标位姿
    ///
    RM_SERVICESHARED_EXPORT Pose Service_Algo_Forward_Kinematics(const float* const joint);

    ///
    /// \brief Algo_Inverse_Kinematics  逆解函数
    /// \param q_in                     上一时刻关节角度 单位°
    /// \param q_pose                   目标位姿
    /// \param q_out                    输出的关节角度 单位°
    /// \param flag                     姿态参数类别：0-四元数；1-欧拉角
    /// \return                         SYS_NORMAL：计算正常，CALCULATION_FAILED：计算失败
    ///
    RM_SERVICESHARED_EXPORT int Service_Algo_Inverse_Kinematics(const float* const q_in, const Pose* const q_pose,
                                                                float* q_out, uint8_t flag);

    ///
    /// \brief  Algo_RotateMove         计算环绕运动位姿
    /// \param  curr_joint              当前关节角度 单位°
    /// \param  rotate_axis             旋转轴: 1:x轴, 2:y轴, 3:z轴
    /// \param  rotate_angle            旋转角度: 旋转角度, 单位(度)
    /// \param  choose_axis             指定计算时使用的坐标系
    /// \return Pose                    计算位姿结果
    RM_SERVICESHARED_EXPORT Pose Service_Algo_RotateMove(const float* const curr_joint, int rotate_axis,
                                                         float rotate_angle, Pose choose_axis);

    ///
    /// \brief  Algo_End2Tool           末端位姿转成工具位姿
    /// \param  eu_end                  基于世界坐标系和默认工具坐标系的末端位姿
    /// \return Pose                    基于工作坐标系和工具坐标系的末端位姿
    ///
    RM_SERVICESHARED_EXPORT Pose Service_Algo_End2Tool(Pose eu_end);

    ///
    /// \brief  Algo_Tool2End           工具位姿转末端位姿
    /// \param  eu_tool                 基于工作坐标系和工具坐标系的末端位姿
    /// \return Pose                    基于世界坐标系和默认工具坐标系的末端位姿
    ///
    RM_SERVICESHARED_EXPORT Pose Service_Algo_Tool2End(Pose eu_tool);

    ///
    /// \brief  Algo_Quaternion2Euler   四元数转欧拉角
    /// \param  qua                     四元数
    /// \return Euler                   欧拉角
    ///
    RM_SERVICESHARED_EXPORT Euler Service_Algo_Quaternion2Euler(Quat qua);

    ///
    /// \brief  Algo_Euler2Quaternion   欧拉角转四元数
    /// \param  eu                      欧拉角
    /// \return Quat                    四元数
    ///
    RM_SERVICESHARED_EXPORT Quat Service_Algo_Euler2Quaternion(Euler eu);

    ///
    /// \brief  Algo_Euler2Matrix       欧拉角转旋转矩阵
    /// \param  eu                      欧拉角
    /// \return Matrix                  旋转矩阵
    ///
    RM_SERVICESHARED_EXPORT Matrix Service_Algo_Euler2Matrix(Euler eu);

    ///
    /// \brief  Algo_Pos2Matrix         位姿转旋转矩阵
    /// \param  state                   位姿
    /// \return Matrix                  旋转矩阵
    ///
    RM_SERVICESHARED_EXPORT Matrix Service_Algo_Pos2Matrix(Pose state);

    ///
    /// \brief  Algo_Matrix2Pos         旋转矩阵转位姿
    /// \param  matrix                  旋转矩阵
    /// \return Pose                    位姿
    ///
    RM_SERVICESHARED_EXPORT Pose Service_Algo_Matrix2Pos(Matrix matrix);

    ///
    /// \brief  Algo_Base2WorkFrame     基坐标系转工作坐标系
    /// \param  matrix                  工作坐标系在基坐标系下的矩阵
    /// \param  state                   工具端坐标在基坐标系下位姿
    /// \return Pose                    基坐标系在工作坐标系下的位姿
    ///
    RM_SERVICESHARED_EXPORT Pose Service_Algo_Base2WorkFrame(Matrix matrix, Pose state);

    ///
    /// \brief  Algo_WorkFrame2Base     工作坐标系转基坐标系
    /// \param  matrix                  工作坐标系在基坐标系下的矩阵
    /// \param  state                   工具端坐标在工作坐标系下位姿
    /// \return Pose                    工作坐标系在基坐标系下的位姿
    ///
    RM_SERVICESHARED_EXPORT Pose Service_Algo_WorkFrame2Base(Matrix matrix, Pose state);

    ///
    /// \brief  Algo_Cartesian_Tool     计算沿工具坐标系运动位姿
    /// \param  curr_joint              当前关节角度
    /// \param  move_lengthx            沿X轴移动长度，米为单位
    /// \param  move_lengthy            沿Y轴移动长度，米为单位
    /// \param  move_lengthz            沿Z轴移动长度，米为单位
    /// \return Pose                    工作坐标系下的位姿
    ///
    RM_SERVICESHARED_EXPORT Pose Service_Algo_Cartesian_Tool(const float* const curr_joint, float move_lengthx,
                                                             float move_lengthy, float move_lengthz);

    ///
    /// \brief Algo_Set_WorkFrame       设置工作坐标系
    /// \param coord_work               坐标系数据
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Set_WorkFrame(const FRAME* const coord_work);

    ///
    /// \brief  Algo_Get_Curr_WorkFrame 获取当前工作坐标系
    /// \param  coord_work              当前工作坐标系
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Get_Curr_WorkFrame(std::shared_ptr<FRAME>& coord_work);
    RM_SERVICESHARED_EXPORT void Service_Algo_Get_Curr_WorkFrame(FRAME* coord_work);

    ///
    /// \brief Algo_Set_ToolFrame       设置工具坐标系
    /// \param coord_tool               坐标系数据
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Set_ToolFrame(const FRAME* const coord_tool);

    ///
    /// \brief  Algo_Get_Curr_ToolFrame 获取当前工具坐标系
    /// \param  coord_tool              当前工具坐标系
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Get_Curr_ToolFrame(std::shared_ptr<FRAME>& coord_tool);
    RM_SERVICESHARED_EXPORT void Service_Algo_Get_Curr_ToolFrame(FRAME* coord_tool);

    ///
    /// \brief Algo_Set_Joint_Max_Limit 设置关节最大限位
    /// \param joint_limit              单位°
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Set_Joint_Max_Limit(const float* const joint_limit);

    ///
    /// \brief Algo_Get_Joint_Max_Limit 获取关节最大限位
    /// \param joint_limit              返回关节最大限位
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Get_Joint_Max_Limit(float* joint_limit);

    ///
    /// \brief Algo_Set_Joint_Min_Limit 设置关节最小限位
    /// \param joint_limit              单位°
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Set_Joint_Min_Limit(const float* const joint_limit);

    ///
    /// \brief Algo_Get_Joint_Min_Limit 获取关节最小限位
    /// \param joint_limit              返回关节最小限位
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Get_Joint_Min_Limit(float* joint_limit);

    ///
    /// \brief Algo_Set_Joint_Max_Speed 设置关节最大速度
    /// \param joint_slim_max           RPM
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Set_Joint_Max_Speed(const float* const joint_slim_max);

    ///
    /// \brief Algo_Get_Joint_Max_Speed 获取关节最大速度
    /// \param joint_slim_max           返回关节最大速度
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Get_Joint_Max_Speed(float* joint_slim_max);

    ///
    /// \brief Algo_Set_Joint_Max_Acc   设置关节最大加速度
    /// \param joint_alim_max           RPM/s
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Set_Joint_Max_Acc(const float* const joint_alim_max);

    ///
    /// \brief Algo_Get_Joint_Max_Acc   获取关节最大加速度
    /// \param joint_alim_max           返回关节最大加速度
    ///
    RM_SERVICESHARED_EXPORT void Service_Algo_Get_Joint_Max_Acc(float* joint_alim_max);
};

#ifdef __cplusplus
}
#endif // RM_SERVICE_H

#endif
