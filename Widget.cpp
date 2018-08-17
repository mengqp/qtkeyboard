/*******************************************************************************
 * 文件名:Widget.cpp
 * 文件描述:
 * 创建日期:2018/07/26 13:45:36
 * 版本：Ver1.0
 *
 * Copyright © 2018 - 2018 mengqp.
 *
 * 历史版本：
 * 修改人                修改时间                修改版本        修改内容
 *
 *
 ******************************************************************************/

#include "Widget.h"
#include <QModelIndex>
#include <QAbstractItemView>
#include <QApplication>
#include "Global.h"
#include "KbNum.h"
#include "KbInput.h"

/*******************************************************************************
 * 功能描述:构造函数
 ******************************************************************************/
CWidget::CWidget (QWidget *parent) : QWidget ( parent )
{
    this->resize( 480, 800 );
    this->setWindowTitle("EM761_BV2");
    this->setObjectName("EM761_BV2");

    m_buttonTest = new QPushButton( this );
    m_buttonTest->setGeometry(10, 10, 20, 20 );

    m_lineTest = new QLineEdit( this );
    m_lineTest->setGeometry( 10 , 50, 100, 20 );

    m_lineTestNot = new QLineEdit( this );
    m_lineTestNot->setGeometry( 10 , 80, 100, 20 );
    m_lineTestNot->setReadOnly(true);
}   /*-------- end 构造函数 -------- */

/*******************************************************************************
 * 功能描述:析构函数
 ******************************************************************************/
CWidget::~CWidget (void)
{
    if( NULL != m_lineTest )
    {
        delete m_lineTest;
        m_lineTest = NULL;
    }
    if( NULL != m_buttonTest )
    {
        delete m_buttonTest;
        m_buttonTest = NULL;
    }

}   /*-------- end 析构函数 -------- */

void CWidget::paintEvent(QPaintEvent * pPaintEvent )
{
    // QStyleOption opt;
    // opt.init(this);
    // QPainter p(this);
    // style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    // this->clearFocus();
    // if ( m_buttonTest->hasFocus() )
    // {
    //     printf("paintevent\n");
    //     m_buttonTest->clearFocus();
    // }
    // QWidget *focusWidget = QApplication::focusWidget();

    if ( KB_NUM_MODE == GlobalGetKbMode() )
    {
        if ( CKbInput::Instance()->isVisible() )
        {
            CKbInput::Instance()->setVisible(false);
            CKbNum::Instance()->ShowKeyBoard();
        }
    }
    else if ( KB_INPUT_MODE == GlobalGetKbMode() )
    {
        if ( CKbNum::Instance()->isVisible() )
        {
            CKbNum::Instance()->setVisible(false);
            CKbInput::Instance()->ShowKeyBoard();
        }
    }


}

void CWidget::mousePressEvent(QMouseEvent * pMouseEvent )
{
    printf("mousepressevent\n");
    // QWidget *focusWidget = QGui::QApplication::focusWidget();
    // QWidget *focusWidget = this->focusWidget();
    QWidget *focusWidget = qApp->focusWidget();
    printf("focuswidget=%lu\n", ( long )focusWidget);
    printf("this=%lu\n", ( long )this);
    if ( NULL != focusWidget )
    {
        printf("clearfocus\n");
        // m_buttonTest->clearFocus();
        focusWidget->clearFocus();
        CKbNum::Instance()->setVisible( false );

        // focusWidget->hide();
    }

}
