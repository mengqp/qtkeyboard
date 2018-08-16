/*******************************************************************************
 *文件名:main.cpp
 * 文件描述: 主函数入口
 * 创建日期:2018/08/15 14:05:43
 * 版本：Ver1.0
 *
 * Copyright © 2018 - 2018 mengqp.
 *
 * 历史版本：
 * 修改人                修改时间                修改版本        修改内容
 *
 *
 ******************************************************************************/

#include <QApplication>
#include "Widget.h"
#include "frmnum.h"
#include "frminput.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv );

    frmNum::Instance()->Init("brown",10);//set brown--灰黑色
    frmInput::Instance()->Init("control", "black", 10, 10);

    CWidget w;
    w.show();

    return a.exec();
}
