#include "pupil.h"
#include "mainwindow.h"
#include<QFile>
#include <QTextCodec>
#include<QDebug>
#include<iostream>

#pragma once

Pupil::Pupil(){}

QStringList Pupil::famile{""};

void Pupil::set_f( QStringList str){
famile=str;
}

void Pupil::save_new(QStringList str){
     QFile file(return_my_file());
    if ((file.exists())&&(file.open(QIODevice::WriteOnly))){
        QTextStream stream(&file);
         foreach(QString s, str)
        {
            stream<<s;
        }
        }
    file.close();
    famile=str;
    }


void Pupil::save( ){
     QFile file(return_my_file());
     //сохраняем новые данные в файл
     if ((file.exists())&&(file.open(QIODevice::Append))){
     QTextStream stream(&file);
     foreach(QString s,famile)
       {
           stream<<s;
       }
     }
       file.close();
}
QStringList Pupil::continue_op(){
    famile.clear();
     QFile file(return_my_file());
     /*Считываем исходный файл в контейнер*/
     if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
     {

       while(!file.atEnd())
       {
         famile<<file.readLine( ) ;
        }

    }
     return famile;
}

QString Pupil::my_file="Новый проект";

QString Pupil::return_my_file(){
    return my_file;
}
void Pupil::new_my_file(QString new_file){
    my_file=new_file;
}


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
int Pupil::count=0;

void Pupil::set_count(int new_count){
    count =new_count;
}
int Pupil::return_count(){
    return count;
}

