/*******************************************************************************
 * 文件名:Widget.h
 * 文件描述:widget
 * 创建日期:2018/07/26 13:45:12
 * 版本：Ver1.0
 *
 * Copyright © 2018 - 2018 mengqp.
 *
 * 历史版本：
 * 修改人                修改时间                修改版本        修改内容
 *
 *
 ******************************************************************************/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

/*******************************************************************************
 *功能描述:
 *******************************************************************************/
class CWidget : public QWidget
{
  public:
    /* constructor */
    explicit CWidget(QWidget *parent = 0);
    /* distructor */
    virtual ~CWidget(void);

  private:
    QPushButton *m_buttonTest;
    QLineEdit *m_lineTest;
    QLineEdit *m_lineTestNot;

  private:
    virtual void paintEvent(QPaintEvent *pPaint);

	void mousePressEvent(QMouseEvent *);

};


#endif /* WIDGET_H */

// This file is set to c + + mode when you set the following content to the bottom and reopen the file
// Local Variables:
// mode: c++
// End:
