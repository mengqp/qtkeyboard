/*******************************************************************************
 * 文件名:KbNum.h
 * 文件描述:数字键盘
 * 创建日期:2018/08/16 11:57:16
 * 版本：Ver1.0
 *
 * Copyright © 2018 - 2018 mengqp.
 *
 * 历史版本：
 * 修改人                修改时间                修改版本        修改内容
 *
 *
 ******************************************************************************/

#ifndef KBNUM_H
#define KBNUM_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QPushButton>
#include <QTimer>
#include <QEvent>

namespace Ui
{
class CKbNum;
}

class CKbNum : public QWidget
{
    Q_OBJECT

public:
    explicit CKbNum(QWidget *parent = 0);
    ~CKbNum();

    //单例模式,保证一个程序只存在一个输入法实例对象
    static CKbNum *Instance() {
        if (!_instance) {
            _instance = new CKbNum;
        }
        return _instance;
    }

    //初始化面板状态,包括字体大小
    void Init(QString style, int fontSize);
    // showui
    void ShowKeyBoard(void);


  protected:
    //鼠标拖动事件
    void mouseMoveEvent(QMouseEvent *e);
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *e);
    //鼠标松开事件
    void mouseReleaseEvent(QMouseEvent *);
    //事件过滤器,处理鼠标按下弹出输入法面板
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    //焦点改变事件槽函数处理
    void focusChanged(QWidget *oldWidget, QWidget *nowWidget);
    //输入法面板按键处理
    void btn_clicked();
    //改变输入法面板样式
    void changeStyle(QString topColor, QString bottomColor,
                     QString borderColor, QString textColor);
    //定时器处理退格键
    void reClicked();

private:
    Ui::CKbNum *ui;
    static CKbNum *_instance;       //实例对象
    QWidget *m_widgetLast;          // 上一个键盘显示界面

    bool isPress;                   //是否长按退格键
    QPushButton *btnPress;          //长按按钮
    QTimer *timerPress;             //退格键定时器
    bool checkPress();              //校验当前长按的按钮

    QPoint mousePoint;              //鼠标拖动自定义标题栏时的坐标
    bool mousePressed;              //鼠标是否按下

    bool isFirst;                   //是否首次加载
    // bool isClose;
    void InitForm();                //初始化窗体数据
    void InitProperty();            //初始化属性
    void ChangeStyle();             //改变样式

    QWidget *currentWidget;         //当前焦点的对象
    QLineEdit *currentLineEdit;     //当前焦点的单行文本框
    QTextEdit *currentTextEdit;     //当前焦点的多行文本框
    QPlainTextEdit *currentPlain;   //当前焦点的富文本框
    QTextBrowser *currentBrowser;   //当前焦点的文本浏览框

    QString currentEditType;        //当前焦点控件的类型
    QString currentStyle;           //当前输入法面板样式
    int currentFontSize;            //当前输入法面板字体大小
    void insertValue(QString value);//插入值到当前焦点控件
    void deleteValue();             //删除当前焦点控件的一个字符

};

#endif /* KBNUM_H */
