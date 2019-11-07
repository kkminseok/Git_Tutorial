#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    data=32767;
    qDebug()<<data;
    data=200;
    qDebug()<<data;
    dataou=32.767;
    qDebug()<<dataou;
    databoo=true;
    qDebug()<<databoo;
    datastr="KMS";
    qDebug()<<datastr;

    int ban=10;
    qDebug()<<"원의 넓이 = "<<pi*ban*ban;
    qDebug()<<"원의 둘레 = "<<2*pi*ban;

    //
    oper1=10;
    oper2=3;

    //산술 연산
    qDebug()<<"oper1 + oper2 ="<<oper1+oper2;
    qDebug()<<"oper1 - oper2 ="<<oper1-oper2;
    qDebug()<<"oper1 * oper2 ="<<oper1*oper2;
    qDebug()<<"oper1 / oper2 ="<<oper1/oper2;
    qDebug()<<"oper1 % oper2 ="<<oper1%oper2;

    //논리연산
    qDebug()<<QString("(oper1<11) && (oper2>2) =%1").arg(((oper1<11)&&(oper2>2)));
    qDebug()<<QString("(oper1<11) || (oper2>2) =%1").arg(((oper1<11)||(oper2>2)));
    qDebug()<<QString("!(oper1<11) = %1").arg((!(oper1<11)));

    //조건문
    //if(조건식) {명령문 ;}

    int kms;
    kms=50;

    if(kms<60)
    {
        qDebug()<<"낙제";
        qDebug()<<"재수강";
        qDebug()<<"ㅠ";
    }
    else
    {
        qDebug()<<"낙제가 아닙니다.";
        qDebug()<<"야호.";
    }
    qDebug()<<"점수는"<<kms<<"점 입니다.";

    //else if  예시

    if(kms >= 90)
    {
      qDebug() << "A 학점입니다.";
    }
    else if(kms >= 80)
    {
      qDebug() << "B 학점입니다.";
    }
    else if(kms >= 70)
    {
      qDebug() << "C 학점입니다.";
    }
    else if(kms >= 60)
    {
      qDebug() << "D 학점입니다.";
    }
    else // elseif가 아님
    {
      qDebug() << "F 학점입니다.";
    }

    //switch와 enum문
    enum weekday
    {
        Monday,TUesday,Wednesday,Thursday,Friday,Saturday,Sunday
    };

    int today,yestday;

    today=Saturday;

    yestday=today-1;

    switch(yestday)
    {
    case Friday:
    case Saturday: qDebug()<<"Burning";break;
    case Monday: qDebug()<<"Hell Mode";break;
    default:
        qDebug("Fighting!!");
    }

    //반복문
    // c++문법과 같다.

    int sum=0;
    for(int i=0;i<10;++i)
    {
        sum+=i;
        qDebug()<<i<<"까지의 합은"<<sum<<"입니다.";
    }

    int w=0;
    sum=0;
    do
    {
        w++;
        sum+=w;
        qDebug()<<w<<"까지의 합은"<<sum<<"입니다.";
    }while(w<3);


    //배열
    //마찬가지로 문법이 같다.

    int score[11];
    for(int i=1;i<11;++i)
    {
        score[i]=i*2;
        qDebug()<<"i = "<<score[i];
    }

    //동적배열
    //c++ 문법같다.

    int* score2=new int[11];
    for(int i=1;i<11;++i)
    {
        score2[i]=i*2;
        qDebug()<<"i = "<<score2[i];
    }
    delete[]score2;

    //다차원 배열
    //Qt를 컴파일하는  gcc경우 10차원이 넘는 배열 선언가능./.. 쓸모있나?

    int doublearr[3][5];
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<5;++j)
        {
            doublearr[i][j]=i*j;
            qDebug()<<i<<"*"<<j<<"="<<doublearr[i][j];
        }
    }

    //응용 구구단 프로그램

    int gugu[10][10];
    for(int i=1;i<10;++i)
    {
        for(int j=1;j<10;++j)
        {
            gugu[i][j]=i*j;
            qDebug()<<i<<"*"<<j<<"="<<gugu[i][j];
        }
    }
    //구조체

    struct Sample
    {
       int data;
       Sample(int _data): data(_data){}

       int getdata()
       {
           return data;
       }
    };

    Sample A1(50);
    qDebug()<<A1.getdata();

}

Dialog::~Dialog()
{
    delete ui;
}
