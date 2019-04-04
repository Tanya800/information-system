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
    void set_data(QString ,QString,QString,int);
    QString return_name();
    QString return_surname();
    QString return_direction();
    int return_age();
    static void set_count(int);
    static int return_count();

private:
    static int count;
       QString name;
       QString surname;
       QString direction;
       int age;

};

#endif // PUPIL_H
