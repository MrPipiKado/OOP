#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QString>
#include <QChar>
#include <iostream>
#include <ctype.h>
#include <string>
#include <math.h>
using namespace std;
bool unar_func(string&);
bool validator(string& str)
{
    int flag = 0;
    for(auto i : str)
    {
        if(flag<0)
            return false;
        if(i=='(')
            ++flag;
        if(i==')')
            --flag;
    }
    return flag == 0;
}

int find_expresion(string& str)
{
    int result = -1, left_pos, right;
    bool found = false, end = false;
    for(int i = 0; i<str.length(); ++i)
    {
        if(i+1<str.length()&&str[i]=='('&&str[i+1]=='-')
            continue;
        if(str[i]=='(')
        {
            result = right = i+1;
            while(right<str.length()&&((isdigit(str[right])||str[right]=='.')))
            {
                ++right;
                if(str[i]=='q'||str[i]=='w'||
                   str[i]=='r'||str[i]=='t'||
                   str[i]=='y'||str[i]=='u'||
                   str[i]=='i'||str[i]=='o'||
                   str[i]=='e'||str[i]=='*'||
                   str[i]=='-'||str[i]=='/'||
                   str[i]=='+'||str[i]=='^')
                    found=true;
                if(str[i]==')')
                {
                    end = true;
                    break;
                }
            }
        }
        if(found&&end)
            break;
    }
    return result;
}

bool remove_branches(string& str)
{
    int left_pos = -1, right_pos = -1, right;
    bool found = false;
    for(int i = 0; i<str.length(); ++i)
    {
        if(i+1<str.length()&&str[i]=='('&&str[i+1]=='-')
            continue;
        if(str[i]=='(')
        {
            left_pos = right = i+1;
            while(right<str.length()&&(isdigit(str[right])||str[right]=='.'))
                ++right;
            if(right<str.length()&&str[right]==')')
            {
                right_pos = right;
                found = true;
                break;
            }
        }
    }
    if(found)
    {
        str.erase(right_pos, 1);
        str.erase(left_pos-1, 1);
        return true;
    }

    for(int i = 0; i<str.length(); ++i)
    {
        if(i+2<str.length()&&str[i]=='('&&str[i+1]=='('&&str[i+2]=='-')
        {
            left_pos = right = i + 1;
            right+=2;
            while (right < str.length() && (isdigit(str[right]) || str[right] == '.'))
                ++right;
            if (right+1 < str.length() && str[right] == ')'&&str[right] == ')')
            {
                right_pos = right;
                found = true;
                break;
            }
        }
    }
    if(found)
    {
        str.erase(right_pos, 1);
        str.erase(left_pos-1, 1);
    }
    return found;
}

bool add_substract(string& str)
{
    while(unar_func(str));
    double left_oper, right_oper;
    int oper_pos = -1;
    int i = 0;
    if(find_expresion(str)>-1)
        i = find_expresion(str);
    for(; i<str.length(); ++i)
    {
        if(i-1>=0&&str[i]=='-'&&str[i-1]=='(')
            continue;
        if(str[i]=='+'||str[i]=='-')
        {
            oper_pos = i;
            break;
        }
    }
    if(oper_pos<0)return false;
    bool negative = false;
    int left  = oper_pos-1, right = oper_pos+1;
    if(left>=0&&str[left]==')'&&left-1>=0&&isdigit(str[left-1]))
    {
        --left;
        while(left>=0&&(isdigit(str[left])||str[left]=='.'))
            --left;
        if(left>=0&&str[left]=='-'&&left-1>=0&&str[left-1]=='(')
        {
            --left;
            negative = true;
        }
        if(left<0)left=0;
        left_oper = stod(str.substr(left+1, oper_pos-left-2));
    }
    if(!negative)
    {
        while(left>=0&&(isdigit(str[left])||str[left]=='.'))
            --left;
        ++left;
        if(left<0)left=0;
        left_oper = stod(str.substr(left, oper_pos-left));
    }

    negative = false;
    if(right<str.length()&&str[right]=='('&&right+1<str.length()&&str[right+1]=='-'
        &&right+2<str.length()&&isdigit(str[right+2]))
    {
        right+=2;
        while(right<str.length()&&(isdigit(str[right])||str[right]=='.'))
            ++right;
        if(right<str.length()&&str[right]==')')
        {
            right+=1;
            negative = true;
        }
        if(right==str.length())right =(int) str.length();
        right_oper = stod(str.substr(oper_pos+2, right-oper_pos-2));
    }
    if(!negative)
    {
        while(right<str.length()&&(isdigit(str[right])||str[right]=='.'))
            ++right;
        if(right==str.length())right =(int) str.length();
        right_oper = stod(str.substr(oper_pos+1, right-oper_pos));
    }


    if(str[oper_pos]=='+')
        left_oper+=right_oper;
    if(str[oper_pos]=='-')
        left_oper-=right_oper;
    string result = to_string(left_oper);
    str.erase(left, right-left);
    if(left_oper<0)
        result = '(' + result + ')';
    str.insert(left, result);
    while(remove_branches(str));
    return true;
}

bool mult_devide(string& str)
{
    while(unar_func(str));
    double left_oper, right_oper;
    int oper_pos = -1;
    int i = 0;
    if(find_expresion(str)>-1)
        i = find_expresion(str);
    for(; i<str.length(); ++i)
    {
        if(str[i]=='*'||str[i]=='/')
        {
            oper_pos = i;
            break;
        }
    }
    if(oper_pos<0)return false;
    bool negative = false;
    int left  = oper_pos-1, right = oper_pos+1;
    if(left>=0&&str[left]==')'&&left-1>=0&&isdigit(str[left-1]))
    {
        --left;
        while(left>=0&&(isdigit(str[left])||str[left]=='.'))
            --left;
        if(left>=0&&str[left]=='-'&&left-1>=0&&str[left-1]=='(')
        {
            --left;
            negative = true;
        }
        if(left<0)left=0;
        left_oper = stod(str.substr(left+1, oper_pos-left));
    }
    if(!negative)
    {
        while(left>=0&&(isdigit(str[left])||str[left]=='.'))
            --left;
        ++left;
        if(left<0)left=0;
        left_oper = stod(str.substr(left, oper_pos-left));
    }

    negative = false;
    if(right<str.length()&&str[right]=='('&&right+1<str.length()&&str[right+1]=='-'
       &&right+2<str.length()&&isdigit(str[right+2]))
    {
        right+=2;
        while(right<str.length()&&(isdigit(str[right])||str[right]=='.'))
            ++right;
        if(right<str.length()&&str[right]==')')
        {
            right+=2;
            negative = true;
        }
        --right;
        if(right==str.length())right =(int) str.length();
        right_oper = stod(str.substr(oper_pos+2, right-oper_pos-2));
    }
    if(!negative)
    {
        while(right<str.length()&&(isdigit(str[right])||str[right]=='.'))
            ++right;
        if(right==str.length())right =(int) str.length();
        right_oper = stod(str.substr(oper_pos+1, right-oper_pos));
    }
    if(str[oper_pos]=='*')
        left_oper*=right_oper;
    if(str[oper_pos]=='/'&&right_oper!=0)
        left_oper/=right_oper;
    string result = to_string(left_oper);
    str.erase(left, right-left);
    if(left_oper<0)
        result = '(' + result + ')';
    str.insert(left, result);
    while(remove_branches(str));
    return true;
}

bool power(string& str)
{
    while(unar_func(str));
    double left_oper, right_oper;
    int oper_pos = -1;
    int i = 0;
    if(find_expresion(str)>-1)
        i = find_expresion(str);
    for(; i<str.length(); ++i)
    {
        if(str[i]=='^')
        {
            oper_pos = i;
            break;
        }
    }
    if(oper_pos<0)return false;
    bool negative = false;
    int left  = oper_pos-1, right = oper_pos+1;
    if(left>=0&&str[left]==')'&&left-1>=0&&isdigit(str[left-1]))
    {
        --left;
        while(left>=0&&(isdigit(str[left])||str[left]=='.'))
            --left;
        if(left>=0&&str[left]=='-'&&left-1>=0&&str[left-1]=='(')
        {
            --left;
            negative = true;
        }
        if(left<0)left=0;
        left_oper = stod(str.substr(left+1, oper_pos-left-2));
    }
    if(!negative)
    {
        while(left>=0&&(isdigit(str[left])||str[left]=='.'))
            --left;
        ++left;
        if(left<0)left=0;
        left_oper = stod(str.substr(left, oper_pos-left));
    }

    negative = false;
    if(right<str.length()&&str[right]=='('&&right+1<str.length()&&str[right+1]=='-'
       &&right+2<str.length()&&isdigit(str[right+2]))
    {
        right+=2;
        while(right<str.length()&&(isdigit(str[right])||str[right]=='.'))
            ++right;
        if(right<str.length()&&str[right]==')')
        {
            right+=2;
            negative = true;
        }
        --right;
        if(right==str.length())right =(int) str.length();
        right_oper = stod(str.substr(oper_pos+2, right-oper_pos-2));
    }
    if(!negative)
    {
        while(right<str.length()&&(isdigit(str[right])||str[right]=='.'))
            ++right;
        --right;
        if(right==str.length())right =(int) str.length();
        right_oper = stod(str.substr(oper_pos+1, right-oper_pos));
    }
    if(str[oper_pos]=='^')
        left_oper=pow(left_oper, right_oper);
    string result = to_string(left_oper);
    str.erase(left, right-left);
    if(left_oper<0)
        result = '(' + result + ')';
    str.insert(left, result);
    while(remove_branches(str));
    return true;
}

bool unar_func(string& str)
{
    double right_oper;
    int oper_pos = -1;
    int i = 0;
    //if(find_expresion(str)>-1)
      //  i = find_expresion(str);
    for(; i<str.length(); ++i)
    {
        if(str[i]=='q'||str[i]=='w'||
            str[i]=='r'||str[i]=='t'||
            str[i]=='y'||str[i]=='u'||
            str[i]=='i'||str[i]=='o'||
            str[i]=='e')
        {
            oper_pos = i;
            break;
        }
    }
    if(oper_pos<0)return false;
    int right = oper_pos+1;
    bool negative = false;
    if(right<str.length()&&str[right]=='('&&right+1<str.length()&&str[right+1]=='-'
       &&right+2<str.length()&&isdigit(str[right+2]))
    {
        right+=2;
        while(right<str.length()&&(isdigit(str[right])||str[right]=='.'))
            ++right;
        if(right<str.length()&&str[right]==')')
        {
            right+=2;
            negative = true;
        }
        --right;
        if(right==str.length())right =(int) str.length();
        right_oper = stod(str.substr(oper_pos+2, right-oper_pos-2));
    }
    if(!negative)
    {
        while(right<str.length()&&(isdigit(str[right])||str[right]=='.'))
            ++right;
        --right;
        if(right==str.length())right =(int) str.length();
        if(right==oper_pos)
            return false;
        right_oper = stod(str.substr(oper_pos+1, right-oper_pos));
    }
    if(str[oper_pos]=='q')
        right_oper=cos(right_oper);
    if(str[oper_pos]=='w')
        right_oper=sin(right_oper);
    if(str[oper_pos]=='e')
        right_oper=tan(right_oper);
    if(str[oper_pos]=='r')
        right_oper=cos(right_oper)/sin(right_oper);
    if(str[oper_pos]=='t')
        right_oper=log(right_oper);
    if(str[oper_pos]=='y')
        right_oper=log10(right_oper);
    if(str[oper_pos]=='u')
        right_oper=log2(right_oper);
    if(str[oper_pos]=='i')
        right_oper=abs(right_oper);
    if(str[oper_pos]=='o')
        right_oper=sqrt(right_oper);
    string result = to_string(right_oper);
    str.erase(oper_pos, right-oper_pos+1);
    if(right_oper<0)
        result = '(' + result + ')';
    str.insert(oper_pos, result);
    while(remove_branches(str));
    return true;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->toShow = "";
    this->result = "(";
    connect(ui->bt0, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->bt1, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->bt2, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->bt3, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->bt4, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->bt5, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->bt6, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->bt7, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->bt8, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->bt9, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->btPoint, SIGNAL(clicked()), this, SLOT(event_headler()));

    connect(ui->btPlus, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->btDevide, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->btMinus, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->btMultiplay, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->btLeft, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->btRight, SIGNAL(clicked()), this, SLOT(event_headler()));
    connect(ui->btPow, SIGNAL(clicked()), this, SLOT(event_headler()));

    connect(ui->btAnswer, SIGNAL(clicked()), this, SLOT(answer()));
    connect(ui->btClear, SIGNAL(clicked()), this, SLOT(clear()));
    //connect(ui->btUndo, SIGNAL(clicked()), this, SLOT(undo()));
    connect(ui->pbExit, SIGNAL(clicked()), this, SLOT(exit()));

    connect(ui->btSin, SIGNAL(clicked()), this, SLOT(unar_func_h()));
    connect(ui->btCos, SIGNAL(clicked()), this, SLOT(unar_func_h()));
    connect(ui->btTan, SIGNAL(clicked()), this, SLOT(unar_func_h()));
    connect(ui->btCot, SIGNAL(clicked()), this, SLOT(unar_func_h()));
    connect(ui->btLn, SIGNAL(clicked()), this, SLOT(unar_func_h()));
    connect(ui->btLog10, SIGNAL(clicked()), this, SLOT(unar_func_h()));
    connect(ui->btLog2, SIGNAL(clicked()), this, SLOT(unar_func_h()));
    connect(ui->btAbs, SIGNAL(clicked()), this, SLOT(unar_func_h()));
    connect(ui->btSqrt, SIGNAL(clicked()), this, SLOT(unar_func_h()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::event_headler()
{
    QPushButton *button = (QPushButton*)sender();
    if(button->text()=="x^y")
    {
        this->toShow = this->toShow + '^';
        this->result = this->result + '^';
    }
    else
    {
        this->toShow = this->toShow + button->text();
        this->result = this->result + button->text().toUtf8().constData();
    }

    this->ui->lbResult->setText(this->toShow);
}

void MainWindow::undo()
{
    QString result = this->ui->lbResult->text();
    result = result.left(result.length()-1);
    this->ui->lbResult->setText(result);
}

void MainWindow::answer()
{
    this->result = this->result + ')';
    string kaka = this->result;
    while(find_expresion(kaka)!=-1)
        {
            while(unar_func(kaka));
            while(power(kaka));
            while(mult_devide(kaka));
            while(add_substract(kaka));
            remove_branches(kaka);
        }
    this->ui->lbResult->setText(QString::fromStdString(kaka));
}

void MainWindow::unar_func_h()
{
    QPushButton *button = (QPushButton*)sender();
    if(button->text()=="sin(x)")
    {
        this->toShow = this->toShow + "sin(";
        this->result = this->result + "q";
    }
    if(button->text()=="cos(x)")
    {
        this->toShow = this->toShow + "cos(";
        this->result = this->result + "w";
    }
    if(button->text()=="tan(x)")
    {
        this->toShow = this->toShow + "tan(";
        this->result = this->result + "e";
    }
    if(button->text()=="cot(x)")
    {
        this->toShow = this->toShow + "cot(";
        this->result = this->result + "r";
    }
    if(button->text()=="ln(x)")
    {
        this->toShow = this->toShow + "ln(";
        this->result = this->result + "t";
    }
    if(button->text()=="log10(x)")
    {
        this->toShow = this->toShow + "log10(";
        this->result = this->result + "y";
    }
    if(button->text()=="log2(x)")
    {
        this->toShow = this->toShow + "log2(";
        this->result = this->result + "u";
    }
    if(button->text()=="abs(x)")
    {
        this->toShow = this->toShow + "abs(";
        this->result = this->result + "i";
    }
    if(button->text()=="sqrt(x)")
    {
        this->toShow = this->toShow + "sqrt(";
        this->result = this->result + "o";
    }
    this->ui->lbResult->setText(this->toShow);
}

void MainWindow::clear()
{
    this->toShow = "";
    this->result = "(";
    this->ui->lbResult->setText("");
}

void MainWindow::exit()
{
    this->close();
}
