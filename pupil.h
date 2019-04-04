#ifndef PUPIL_H
#define PUPIL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include<iostream>

#include<QStringList>

class Pupil
{
public :
   Pupil();
   static void set_f( QStringList );//изменение контейнера
   static QStringList show();
    void save( );//сохранение в файл
    static void save_new(QStringList);
    static QStringList continue_op();//считать данные из файла
    static void new_my_file(QString);
    static QString return_my_file();

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
       int age;//!
    static QStringList famile;
    static QString my_file;

};

#endif // PUPIL_H
