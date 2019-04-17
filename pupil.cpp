#include "pupil.h"
#include "mainwindow.h"
#include <QTextCodec>
#include<QDebug>
#include<iostream>

#pragma once

Pupil::Pupil(){}


void Pupil::set_data(QString a,QString b,QString c,int d){
    surname=a;
    name=b;
    direction=c;
    age=d;
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
