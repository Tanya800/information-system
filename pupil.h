#ifndef PUPIL_H
#define PUPIL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include<iostream>


class Pupil
{
public :
   Pupil();
    void set_data(QString ,QString,QString,int,QString);
    void set(QString ,QString ,QString ,QString,QString,int,QString);
    QString return_name();
    QString return_surname();
    QString return_direction();
    int return_age();
    QString return_gender();
    QString return_direction_2();
    QString return_direction_3();
private:
       QString name;
       QString surname;
       QString direction;
       QString direction_2;
       QString direction_3;
       int age;
       QString gender;

};

#endif // PUPIL_H
