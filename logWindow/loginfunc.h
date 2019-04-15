#ifndef LOGINFUNC_H
#define LOGINFUNC_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

enum return_value //返回值表
{
    EXIST_YES = 1000,        //存在
    EXIST_NO,                //不存在
    CHECK_PASWD_ERROR,       //密码错误
    RETURN_ERROR,             //出错
    RETURN_SUCCESS           //成功
};

//临时用户信息
typedef struct
{
    QString name;      //用户名
    QString passward;  //密码
    QString nickname;  //昵称
}UserData;

class loginFunc:public QObject
{
    Q_OBJECT
public:

    explicit loginFunc(QObject *parent = nullptr);

    void initDataBase();                                             //初始化数据库
    int isDataExist(UserData *userInf);                             //判断数据是否存在
    bool funcRegister(UserData *userInf);                            //注册函数
    int funcLogin(UserData *userInf);                                //登录函数
    bool setNickName(UserData *userInf);                             //设置昵称
    int isNickName(UserData *userInf);                               //判断是否有昵称

private:
    QSqlDatabase sqldb;                //数据库函数

};

#endif // LOGINFUNC_H
