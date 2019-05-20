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
