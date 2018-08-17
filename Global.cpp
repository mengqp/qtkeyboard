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

static int gs_keyboardmode = KB_NUM_MODE;

/*------------------------------------------------------------------------------
 * 函数名:GlobalSetKbMode
 * 功能描述:设置键盘的类型
 * 参数: int mode 0 为数字键盘 1 为字母
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void GlobalSetKbMode( int mode )
{
    gs_keyboardmode =mode;
    if ( KB_NUM_MODE == mode )
    {
        CKbNum::Instance()->ShowKeyBoard();
    }
    else if ( KB_INPUT_MODE == mode )
    {
        CKbInput::Instance()->ShowKeyBoard();
    }
}   /*-------- end GlobalSetKbMode -------- */

/*------------------------------------------------------------------------------
 * 函数名:GlobalGetKbMode
 * 功能描述:
 * 参数:void
 * 被调用:
 * 返回值:int
 ------------------------------------------------------------------------------*/
int GlobalGetKbMode(void)
{
    return gs_keyboardmode;
}   /*-------- end GlobalGetKbMode -------- */
