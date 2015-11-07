/*
 * 这是一个简单的排座小程序,你可以在此基础上修改和
 * 添加新的功能
 * Dug and
 *
 *
 *
*/







#include "mainwindow.h"
#include"Seat.h"
#include"qdebug.h"
#include<iostream>
#include<QFile>
#include <sstream>
#include <QFileInfo>
#include<QMessageBox>
#include<qmath.h>
#include<QStringList>
#include<QFileDialog>
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int Sum=0;
void MainWindow::on_pushButton_clicked()
{

    Room *Room1;
    Room1 = new Room();
    Sum++;
//    Room.Rnum
    Room1->setRname (ui->Room->text ());
    Room1->setSnum (ui->Seat_num->text().toInt ());

    Room1->SEAT = new Seat[ui->Seat_num->text().toInt ()];
    for(int i=0;i<Room1->Snum;i++)
    {
        Room1->SEAT[i].Sname="";
        Room1->SEAT[i].Snum="";
        Room1->SEAT[i].Flag=0;//标志 用于记录该位置是否已经排过学生
        Room1->SEAT[i].Seat_num=i+1;
    }
//    qDebug()<<Sum<<endl;
    QFile File_out("Seat.txt");
    if(!File_out.open(QFile::Append))
    {
        QMessageBox::warning(this,
                             tr("txt文件状态"),
                             tr("txt文件失败"),
                             QMessageBox::NoButton,
                             QMessageBox::NoButton
                             );
        return ;
    }
    QTextStream out(&File_out);
    //    QString line;
//    qDebug()<<Room1->Snum;
    for(int i=0;i<Room1->Snum;i++)
    {
        out<<Room1->Rname<<":"<<Room1->Snum<<":"<<Room1->SEAT[i].Sname<<":"
          <<Room1->SEAT[i].Snum<<":"<<Room1->SEAT[i].Seat_num<<":"<<Room1->SEAT[i].Flag<<endl;
        //        out<<line<<endl;
    }
    File_out.close ();
    //delete Room1->SEAT;





    //    Room1.setRname (ui->Room->text());
}
QStringList files;
void MainWindow::on_Read_clicked()
{
    QString str = "Now don,t have null room";
//    if(Sum==0)
//        ui->Result->setText (str);
//        ui->Result->insert ("当前没有空的考场");
    //    else
    //    {
    Room *room;
    room=new Room[30];       //初始化房间对象

    //    }

    QFileDialog::Options options;
    QString openFilesPath = ".";
    //    if (!native->isChecked())
    //        options |= QFileDialog::DontUseNativeDialog;
    QString selectedFilter;
    files = QFileDialog::getOpenFileNames(
                this, tr("OpenFile"),
                openFilesPath,
                tr("txt(*.txt)"),
                &selectedFilter,
                options);
    QFile File_in(files.at(0));
    if( !File_in.open( QFile::ReadOnly | QFile::Text ))
    {
        QMessageBox::warning(this,
                             tr("txt文件状态"),
                             tr("txt文件失败"),
                             QMessageBox::NoButton,
                             QMessageBox::NoButton
                             );
        return ;
    }                                   //打开文本文件
//    if(Sum==0)
//        ui->Result->setText (str);
    QTextStream in(&File_in);
    int j=0;
    while (!in.atEnd())        //读取文本内容
    {
//        int Room_Num= in.readLine ().toInt ();
        for(j=0;!in.atEnd ();j++)
        {
            QString line = in.readLine ();
            QStringList s1 = line.split (":");
            room[j].Rname = s1.at (0);
            room[j].Snum = s1.at (1).toInt ();
            QString Name = s1.at (0);
            int Num = s1.at (1).toInt ();
            room[j].SEAT = new Seat[Num];         //初始化座位对象
            room[j].SEAT[0].Flag=s1.at (5).toInt ();
            room[j].SEAT[0].Seat_num=s1.at (4).toInt ();
            room[j].SEAT[0].Sname=s1.at (2);
            room[j].SEAT[0].Snum=s1.at (3);
            //        line=Room1->Rname+":"+Room1->Snum+":"+Room1->SEAT[i].Sname+":"+Room1->SEAT[i].Snum
            //                +":"+Room1->SEAT[i].Seat_num+":"+Room1->SEAT[i].Flag;
            for(int i=1;i<Num;i++)
            {
                QString line = in.readLine ();
                QStringList s1 = line.split (":");
                room[j].SEAT[i].Flag=s1.at (5).toInt ();
                room[j].SEAT[i].Seat_num=s1.at (4).toInt ();
                room[j].SEAT[i].Sname=s1.at (2);
                room[j].SEAT[i].Snum=s1.at (3);

            }
        }


    }
    File_in.close ();
    QString Stu_Name = ui->Name->text ();
    QString Stu_Num = ui->Num->text ();
    int m=j;
    int flag=0;
    if(QFile::exists("Seat.txt") )
    {
        QFile::remove("Seat.txt");
        qDebug()<<"文本文件已删除";
    }

    QFile File_out("Seat.txt");
    if(!File_out.open(QFile::Append))
    {
        QMessageBox::warning(this,
                             tr("txt文件状态"),
                             tr("txt文件失败"),
                             QMessageBox::NoButton,
                             QMessageBox::NoButton
                             );
        return ;
    }
    QTextStream out(&File_out);
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<room[j].Snum;i++)
        {
            if(room[j].SEAT[i].Flag==0 && flag!=1)
            {
                room[j].SEAT[i].Sname = Stu_Name;
                room[j].SEAT[i].Snum = Stu_Num;
                room[j].SEAT[i].Flag = 1;
                flag =1;
                //QString s = QString::number(i);
                QString line = room[j].Rname +" "+QString::number(room[j].SEAT[i].Seat_num);
                ui->Result->setText (line);

//                qDebug()<<room[j].Rname<<" "<<room[j].Snum<<" "<<room[j].SEAT[i].Seat_num<<" "
//                 <<room[j].SEAT[i].Sname<<" "<<room[j].SEAT[i].Flag<<" "<<room[j].SEAT[i].Snum<<endl;

            }
            out<<room[j].Rname<<":"<<room[j].Snum<<":"<<room[j].SEAT[i].Sname<<":"
              <<room[j].SEAT[i].Snum<<":"<<room[j].SEAT[i].Seat_num<<":"<<room[j].SEAT[i].Flag<<endl;

        }
//        File_out.close ();


    }
    if(flag ==0)
        ui->Result->insert ("当前没有空考场,请创建");

}





void MainWindow::on_Quit_clicked()
{
    close ();
}

