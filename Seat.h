#ifndef SEAT_H
#include<QString>
#define SEAT_H
class Seat{
public:
    QString Sname;
    QString Snum;
    int Seat_num;
    int Flag;
    Seat()
    {

    }

    Seat (QString sname,QString snum,int seat_num,int flag=0)
    {
        this->Sname=sname;
        this->Snum=snum;
        this->Seat_num=seat_num;
        this->Flag=flag;
    }
    Seat (Seat &S)
    {
        this->Sname=S.Sname;
        this->Snum=S.Snum;
        this->Seat_num=S.Seat_num;
        this->Flag=S.Flag;
    }

};
class Room{
public:
    QString Rname;
    Seat *SEAT;
    int Snum;
//    int Rnum=0;
public:
    void setRname (QString Name)
    {
        this->Rname=Name;
    }
    void setSnum(int Num)
    {
        this->Snum=Num;
    }
    QString getRname()
    {
        return Rname;
    }
//    void setSeat(int num)
//    {
//        SEAT=new Seat[num];
//        Seat *it;
//        it =SEAT;
//        int num1=0;
//        qDebug()<<num;
//        for(int i;i<num;i++)
//        {
//            it->Flag=0;
//            it->Seat_num=num1;
//            it->Sname="";
//            it->Snum="";
//            it++;
//            num1++;
//        }
//    }

    //    Room(QString rname,Seat* seat,int snum)
    //    {
    //        this->Rname=rname;

    //    }


};

#endif // SEAT_H
