/*******************************************************************************
 * 文件名:Global.cpp
 * 文件描述:
 * 创建日期:2018/08/15 14:55:04
 * 版本：Ver1.0
 *
 * Copyright © 2018 - 2018 mengqp.
 *
 * 历史版本：
 * 修改人                修改时间                修改版本        修改内容
 *
 *
 ******************************************************************************/

#include "Global.h"
#include "KbNum.h"
#include "KbInput.h"

static int gs_keyboardmode = 0;

/*------------------------------------------------------------------------------
 * 函数名:setkeyboardmode
 * 功能描述:设置键盘的类型
 * 参数: int mode 0 为数字键盘 1 为字母
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void setkeyboardmode( int mode )
{
    gs_keyboardmode =mode;
    if ( 0 == mode )
    {
        CKbNum::Instance()->ShowKeyBoard();
    }
    else
    {
        CKbInput::Instance()->ShowKeyBoard();
    }
}   /*-------- end setkeyboardmode -------- */

/*------------------------------------------------------------------------------
 * 函数名:getkeyboardmode
 * 功能描述:
 * 参数:void
 * 被调用:
 * 返回值:int
 ------------------------------------------------------------------------------*/
int getkeyboardmode(void)
{
    return gs_keyboardmode;
}   /*-------- end getkeyboardmode -------- */
