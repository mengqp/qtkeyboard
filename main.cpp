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
#include <QTextCodec>
#include "Widget.h"
#include "KbNum.h"
#include "KbInput.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv );
    //QT5 版本以上默认就是采用 UTF-8 编码
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    CKbNum::Instance()->Init("brown",10);//set brown--灰黑色
    CKbInput::Instance()->Init("control", "black", 10, 10);

    CWidget w;
    w.show();

    return a.exec();
}
