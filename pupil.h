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
    QString return_name();
    QString return_surname();
    QString return_direction();
    int return_age();
    QString return_gender();

private:
       QString name;
       QString surname;
       QString direction;
       int age;
       QString gender;

};

#endif // PUPIL_H
