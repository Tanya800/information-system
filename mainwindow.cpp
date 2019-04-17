#include "mainwindow.h"
#include "pupil.h"
#include<QFileDialog>
#include "ui_mainwindow.h"
#include<QFile>
#include<QDebug>
#include<QMenuBar>
#include<QVector>
#include<iostream>
#include <QTextCodec>
#include<QMessageBox>
#pragma once
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

       QRegExp ipRegex ("^[1-9]{1}[0-9]{1}$");
       QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
       ui->lineEdit_age->setValidator(ipValidator);

       QRegExp Const_v ("^[А-Яа-я]{,50}$");
       QRegExpValidator *const_all = new QRegExpValidator(Const_v, this);
       ui->lineEdit_f->setValidator(const_all);
       ui->lineEdit_i->setValidator(const_all);

       QRegExp Const_f ("^[А-Яа-я0-9]+$");
       QRegExpValidator *const_find = new QRegExpValidator(Const_f, this);
       ui->lineEdit_find->setValidator(const_find);

       QRegExp Const_dd ("^[0-9]+$");
       QRegExpValidator *const_delete = new QRegExpValidator(Const_dd, this);
       ui->lineEdit_delete->setValidator(const_delete);
       ui->lineEdit_edit->setValidator(const_delete);
       show_my_project();
}

MainWindow::~MainWindow()
{
    delete ui;
}


static QVector <Pupil> my_pupil;
static QString my_file="Новый проект";
static int choice=-1;



void MainWindow::on_pushButton_clicked()
{

    if(choice==-1){
    QTextCodec::setCodecForLocale( QTextCodec::codecForName( "UTF-8" ) );
    QStringList strList ;

    QTableWidgetItem *Item1=new QTableWidgetItem();
    Item1->setTextAlignment(Qt::AlignCenter);
    QTableWidgetItem *Item2=new QTableWidgetItem();
    Item2->setTextAlignment(Qt::AlignCenter);
    QTableWidgetItem *Item3=new QTableWidgetItem();
    Item3->setTextAlignment(Qt::AlignCenter);
    QTableWidgetItem *Item4=new QTableWidgetItem();
    Item4->setTextAlignment(Qt::AlignCenter);

    if(!(ui->lineEdit_f->text().isEmpty()||ui->lineEdit_i->text().isEmpty()||ui->lineEdit_age->text().isEmpty())){

    Pupil new_people;

    ui->lineEdit_f->setText( ui->lineEdit_f->text().replace(0,1,ui->lineEdit_f->text().front().toUpper()));
    ui->lineEdit_f->setText(ui->lineEdit_f->text().replace(1,ui->lineEdit_f->text().size()-1,ui->lineEdit_f->text().mid(1,ui->lineEdit_f->text().size()-1).toLower()));
    ui->lineEdit_i->setText(ui->lineEdit_i->text().replace(0,1,ui->lineEdit_i->text().front().toUpper()));
    ui->lineEdit_i->setText(ui->lineEdit_i->text().replace(1,ui->lineEdit_i->text().size()-1,ui->lineEdit_i->text().mid(1,ui->lineEdit_i->text().size()-1).toLower()));
    new_people.set_data(ui->lineEdit_f->text()+"\r\n",ui->lineEdit_i->text()+"\r\n",ui->comboBox->currentText()+"\r\n",ui->lineEdit_age->text().toInt());
    my_pupil.push_back(new_people);

    Item1->setText(my_pupil.back().return_surname().trimmed());

    Item2->setText(my_pupil.back().return_name().trimmed());

    Item3->setText( my_pupil.back().return_direction().trimmed());

    Item4->setText(QString::number( my_pupil.back().return_age() ));

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,0,Item1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,1,Item2);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,2,Item3);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,3,Item4);
    ui->lineEdit_f->clear();
    ui->lineEdit_i->clear();
    ui->lineEdit_age->clear();
    }else {
         ui->statusBar->showMessage("Заполните все поля",1000);
    }
    }
    else{

        if(!(ui->lineEdit_f->text().isEmpty()||ui->lineEdit_i->text().isEmpty()||ui->lineEdit_age->text().isEmpty())){
        Pupil edit_people;
        ui->lineEdit_f->setText(ui->lineEdit_f->text().trimmed());
        ui->lineEdit_i->setText(ui->lineEdit_i->text().trimmed());
        ui->lineEdit_age->setText(ui->lineEdit_age->text().trimmed());
        ui->lineEdit_f->setText( ui->lineEdit_f->text().replace(0,1,ui->lineEdit_f->text().front().toUpper()));
        ui->lineEdit_f->setText(ui->lineEdit_f->text().replace(1,ui->lineEdit_f->text().size()-1,ui->lineEdit_f->text().mid(1,ui->lineEdit_f->text().size()-1).toLower()));
        ui->lineEdit_i->setText(ui->lineEdit_i->text().replace(0,1,ui->lineEdit_i->text().front().toUpper()));
        ui->lineEdit_i->setText(ui->lineEdit_i->text().replace(1,ui->lineEdit_i->text().size()-1,ui->lineEdit_i->text().mid(1,ui->lineEdit_i->text().size()-1).toLower()));
        edit_people.set_data(ui->lineEdit_f->text().toUtf8()+"\r\n",ui->lineEdit_i->text().toUtf8()+"\r\n",ui->comboBox->currentText().toUtf8()+"\r\n",(ui->lineEdit_age->text()+"\r\n").toInt());
        my_pupil[choice]=edit_people;
        choice=-1;
        ui->lineEdit_f->clear();
        ui->lineEdit_i->clear();
        ui->lineEdit_age->clear();
        on_pushButton_2_clicked();
        clear_lineEdit();
        }else {
            ui->statusBar->showMessage("Заполните все поля",3000);
            }
    }


}

void MainWindow::on_pushButton_2_clicked()
{


    ui->label_table->setText("Отображение всей информации");
    ui->tableWidget->setRowCount(0);

   if(! my_pupil.isEmpty()){
    for(int i=0;i<my_pupil.size();i++){
        QTableWidgetItem *Item1=new QTableWidgetItem();
        Item1->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem *Item2=new QTableWidgetItem();
        Item2->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem *Item3=new QTableWidgetItem();
        Item3->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem *Item4=new QTableWidgetItem();
        Item4->setTextAlignment(Qt::AlignCenter);
        Item1->setText(my_pupil[i].return_surname().toUtf8().trimmed());
        Item2->setText(my_pupil[i].return_name().toUtf8().trimmed());
        Item3->setText(my_pupil[i].return_direction().trimmed());
        Item4->setText(QString::number(my_pupil[i].return_age()).trimmed());
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,0,Item1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,1,Item2);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,2,Item3);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,3,Item4);
    }

   }
    }



void MainWindow::on_pushButton_delete_clicked()
{
    //удаление определенной строки
    bool find=false;
    if(!ui->lineEdit_delete->text().isEmpty()){
        for(int i=0;i<my_pupil.size();i++){
            if(ui->lineEdit_delete->text().toInt()-1==i){
                my_pupil.removeAt(i);
                find=true;
            }
        }

       ui->lineEdit_delete->clear();
       if(find==true){on_pushButton_2_clicked();
       ui->statusBar->showMessage("Элемент удален",1000);}
       else{ui->statusBar->showMessage("Строка не найдена.",1000);}
       clear_lineEdit();
    }
}

void MainWindow::on_pushButton_help_clicked()
{
        ui->statusBar->showMessage("Введите в поле номер строки для удаления",3000);
}

void MainWindow::on_pushButton_help_find_clicked()
{
     ui->statusBar->showMessage("Введите в поле данные об ученике,которого вы хотите найти",3000);
}

void MainWindow::on_pushButton_find_clicked()
{

    QStringList str;
    int n=my_pupil.size();
    if(!(ui->lineEdit_find->text().isEmpty())){
        ui->lineEdit_find->setText( ui->lineEdit_find->text().replace(0,1,ui->lineEdit_find->text().front().toUpper()));
        ui->lineEdit_find->setText(ui->lineEdit_find->text().replace(1,ui->lineEdit_find->text().size()-1,ui->lineEdit_find->text().mid(1,ui->lineEdit_find->text().size()-1).toLower()));
        ui->label_table->setText("Результаты поиска");
        ui->tableWidget->setRowCount(0);
    for(int i=0;i<my_pupil.size();i++){   
        QTableWidgetItem *Item1=new QTableWidgetItem();
        Item1->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem *Item2=new QTableWidgetItem();
        Item2->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem *Item3=new QTableWidgetItem();
        Item3->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem *Item4=new QTableWidgetItem();
        Item4->setTextAlignment(Qt::AlignCenter);
        Item1->setText(my_pupil[i].return_surname().toUtf8());
        Item2->setText(my_pupil[i].return_name().toUtf8());
        Item3->setText(my_pupil[i].return_direction());
        Item4->setText(QString::number(my_pupil[i].return_age()));

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,0,Item1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,1,Item2);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,2,Item3);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,3,Item4);

        if(!(ui->lineEdit_find->text()+"\r\n"==my_pupil[i].return_name()||ui->lineEdit_find->text()+"\r\n"==my_pupil[i].return_surname()||ui->lineEdit_find->text()+"\r\n"==my_pupil[i].return_direction()||ui->lineEdit_find->text().toInt()==my_pupil[i].return_age())){
           ui->tableWidget->hideRow(i);
           n--;
        }

    }
    clear_lineEdit();
    if(n==0) {
        ui->statusBar->showMessage("Ученик не найден.Попробуйте снова.",3000);
        on_pushButton_2_clicked();
        }
    }
    ui->lineEdit_find->clear();

}

void MainWindow::on_pushButton_edit_clicked()
{
    if(!(ui->lineEdit_edit->text().isEmpty())){
    if(! my_pupil.isEmpty()){
    on_pushButton_edit_2_clicked();
    for(int i=0;i<my_pupil.size();i++){
        if(ui->lineEdit_edit->text().toInt()-1==i){
        ui->statusBar->showMessage("Ученик найден. Заполните поля:Фамиля,Имя,Возраст,Направление и нажмите кнопку \"Добавить\".",3000);
        ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,0)->setBackground(Qt::green);
        ui->lineEdit_f->setText(ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,0)->text().trimmed());
        ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,1)->setBackground(Qt::green);
        ui->lineEdit_i->setText(ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,1)->text().trimmed());
        ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,2)->setBackground(Qt::green);
        ui->comboBox->setCurrentText(ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,2)->text().trimmed());
        ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,3)->setBackground(Qt::green);
        ui->lineEdit_age->setText(ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,3)->text().trimmed());
        choice=ui->lineEdit_edit->text().toInt()-1;
        }
    }
    if(choice==-1)  ui->statusBar->showMessage("Ученик не найден. Попробуйте снова.",3000);

        }
    }

}



void MainWindow::on_pushButton_edit_2_clicked()
{

    if( !ui->lineEdit_edit->text().isEmpty()){
           if(! my_pupil.isEmpty()){
               if(choice!=-1) {ui->tableWidget->item(choice,0)->setBackground(Qt::white);
                   ui->tableWidget->item(choice,1)->setBackground(Qt::white);
                   ui->tableWidget->item(choice,2)->setBackground(Qt::white);
                   ui->tableWidget->item(choice,3)->setBackground(Qt::white);
               }

               ui->lineEdit_f->clear();
               ui->lineEdit_i->clear();
               ui->lineEdit_age->clear();
               choice=-1;
           }
    }
}

void MainWindow::on_action_2_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this, tr("Создать"), QDir::currentPath(), tr("File (*.txt)"));
    if(!filename.isEmpty()){
    QFile new_file(filename);
    new_file.open(QIODevice::WriteOnly);
    new_file.close();
    my_file=filename;
    my_pupil.clear();
    on_pushButton_2_clicked();
    show_my_project();
    }
}

void MainWindow::on_action_6_triggered()
{
    QMessageBox:: StandardButton reply = QMessageBox::question(this,"Выход","Вы действительно хотите выйти?",QMessageBox::Yes | QMessageBox::No);
     if (reply==QMessageBox::Yes)
     {
         QApplication::quit();

     }
}



//сохранить как
void MainWindow::on_action_4_triggered()
{
    on_action_3_triggered();
    QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить как"), QDir::currentPath(), tr("File (*.txt)") );
    if(!filename.isEmpty()){
    QFile young(filename);
    QFile old(my_file);
    old.close();
    young.open(QIODevice::WriteOnly);
    old.open(QIODevice::ReadOnly);
    QByteArray my_buf = old.readAll();
    young.write(my_buf);
    young.close();
    my_file=filename;
    show_my_project();
    QMessageBox::information(this,"Результат","Файл сохранен","ОК");

    }

}
//сохранить
void MainWindow::on_action_3_triggered()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    if(my_file=="Новый проект"){
         QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить как"), QDir::currentPath(), tr("File (*.txt)") );
         if(!filename.isEmpty()){
             my_file=filename;}
    }
    else{
   QStringList save_project;
   for(int i=0;i<my_pupil.size();i++){
       save_project<<my_pupil[i].return_surname().toUtf8();
       save_project<<my_pupil[i].return_name().toUtf8();
       save_project<<my_pupil[i].return_direction().toUtf8();
       save_project<<QString::number(my_pupil[i].return_age())<<"\r\n";
   }
   QFile file(my_file);
   if ((file.exists())&&(file.open(QIODevice::WriteOnly))){
           QTextStream stream(&file);
            foreach(QString s, save_project)
           {
               stream<<s;
           }
   }
   file.close();
    }
    show_my_project();
}


//открываем файл
void MainWindow::on_action_5_triggered()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
   QString filename =  QFileDialog::getOpenFileName(this, tr("Открыть"), QDir::currentPath(), tr("File (*.txt)"));
   QStringList open_project;
   if(!filename.isEmpty()){
     my_file=filename;
     my_pupil.clear();

     QFile file(my_file);
     if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
     {

       while(!file.atEnd())
       {
         open_project<<file.readLine( ) ;
        }

    }
     file.close();

     for(int i=0;i<open_project.size();i+=4){
        Pupil temp;
        temp.set_data(open_project[i],open_project[i+1],open_project[i+2],open_project[i+3].toInt());
        my_pupil.push_back(temp);
     }
     clear_lineEdit();
     on_pushButton_2_clicked();
     show_my_project();
   }

}

void MainWindow::on_tableWidget_cellClicked(int row)
{
    ui->lineEdit_delete->setText(QString::number(row+1));
    ui->lineEdit_edit->setText(QString::number(row+1));
}

void MainWindow::show_my_project(){
    QWidget::setWindowTitle("Информационно-поисковая система \"Музыкальная школа\" "+my_file);
}

void MainWindow::clear_lineEdit(){
    ui->lineEdit_edit->clear();
    ui->lineEdit_delete->clear();

}
