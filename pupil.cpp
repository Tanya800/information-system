#include "pupil.h"
#include "mainwindow.h"
#include <QTextCodec>
#include<QDebug>
#include<iostream>


Pupil::Pupil(){
}


void Pupil::set_data(QString a,QString b,QString c,int d,QString f ){
    surname=a;
    name=b;
    direction=c;
    age=d;
    gender =f;
}

void Pupil::set(QString a,QString b,QString dir1,QString dir2,QString dir3,int d,QString f ){
    surname=a;
    name=b;
    direction=dir1;
    direction_2=dir2;
    direction_3=dir3;
    age=d;
    gender =f;
}
QString Pupil::return_name(){
    return name;

}
QString Pupil::return_surname(){
    return surname;

}
QString Pupil::return_direction(){
    return direction;
}
int Pupil::return_age(){
    return age;
}

QString Pupil::return_gender(){
    return gender;
}
QString Pupil::return_direction_2(){
    return direction_2;
}
QString Pupil::return_direction_3(){
    return direction_3;
}
