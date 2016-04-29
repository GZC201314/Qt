#include "mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <string>
#include <QTextStream>
#include <iostream>
#include <ostream>
#include <fstream>
#include <QFile>
#include <sstream>
#include <QFileInfo>
#include<QDebug>
#include<QTextCodec>
#include<QStringList>
#include<QDateTime>
#include<stdio.h>
#include<stdlib.h>
#include<QTime>
#include "ui_mainwindow.h"
QStringList files;
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

void MainWindow::on_pushButton_clicked()
{
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
    //qDebug()<<"files"<<files;

}

void MainWindow::on_pushButton_2_clicked()
{
    if (files.count())
    {

            QFile File_in(files.at(0));
            qDebug()<<files.at(0);
            if( !File_in.open( QFile::ReadOnly | QFile::Text ))
            {
                QMessageBox::warning(this,
                                     tr("txt文件状态"),
                                     tr("txt文件失败"),
                                     QMessageBox::NoButton,
                                     QMessageBox::NoButton
                                     );
                return ;
            }
            QTextStream in(&File_in);
            int Unum;
            QString Action;
             int flag=0;
            while (!in.atEnd())
            {
              QString  line = in.readLine();
                //qDebug()<<"line"<<line;
               QStringList action=line.split("   ");
                QStringList Time=action.at(2).split(",");
                QStringList Time_1=Time.at(0).split("[");
                int time=Time_1.at(1).toInt();
                qDebug()<<time;

               for(int i=0;i<=action.count();i++)
               {
                   if(i==0)
                       Action=action.at(i).trimmed();
                   if(i==1)
                   {
                       Unum=action.at(i).trimmed().toInt();
                       break;
                   }
               }
               if(ui->Time->value()-50<=time&&ui->Time->value()+50>=time && ui->Unum->value()==Unum)
               {
                    ui->textBrowser->insertPlainText(Time_1.at(1));
                    ui->textBrowser->insertPlainText("       ");
                    ui->textBrowser->insertPlainText(Action);
                    ui->textBrowser->insertPlainText("\n");


                    flag=1;
               }
            }
            if(flag==0)
                ui->textBrowser->append("没有找到与该球员相关的数据,可能是该周期内球员没有带球！");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}
