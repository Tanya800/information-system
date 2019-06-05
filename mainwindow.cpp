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
#include <ActiveQt/qaxobject.h>
#include <ActiveQt/qaxbase.h>
#include <QtGui>
#include<QMessageBox>
#include <ActiveQt/qaxobject.h>
#include <ActiveQt/qaxbase.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       QRegExp ipRegex ("^[1-9]{1}[0-9]{1}$");
       QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
       ui->lineEdit_age->setValidator(ipValidator);
       ui->lineEdit_age_find->setValidator(ipValidator);

       QRegExp Const_v ("^[А-Яа-я]{,50}$");
       QRegExpValidator *const_all = new QRegExpValidator(Const_v, this);
       ui->lineEdit_f->setValidator(const_all);
       ui->lineEdit_i->setValidator(const_all);
       ui->lineEdit_f_2->setValidator(const_all);
       ui->lineEdit_i_find->setValidator(const_all);

       QRegExp Const_dd ("^[0-9]+$");
       QRegExpValidator *const_delete = new QRegExpValidator(Const_dd, this);
       ui->lineEdit_delete->setValidator(const_delete);
       ui->lineEdit_edit->setValidator(const_delete);
       show_my_project();

       ui->pushButton_delete2->hide();
       ui->pushButton_delete3->hide();
       ui->comboBox_add2->hide();
       ui->comboBox_add3->hide();
       ui->pushButton_add_2->hide();
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
    QTableWidgetItem *Item5=new QTableWidgetItem();
    Item5->setTextAlignment(Qt::AlignCenter);

    if(!(ui->lineEdit_f->text().isEmpty()||ui->lineEdit_i->text().isEmpty()||ui->lineEdit_age->text().isEmpty())){

    Pupil new_people;

    ui->lineEdit_f->setText( ui->lineEdit_f->text().replace(0,1,ui->lineEdit_f->text().front().toUpper()));
    ui->lineEdit_f->setText(ui->lineEdit_f->text().replace(1,ui->lineEdit_f->text().size()-1,ui->lineEdit_f->text().mid(1,ui->lineEdit_f->text().size()-1).toLower()));
    ui->lineEdit_i->setText(ui->lineEdit_i->text().replace(0,1,ui->lineEdit_i->text().front().toUpper()));
    ui->lineEdit_i->setText(ui->lineEdit_i->text().replace(1,ui->lineEdit_i->text().size()-1,ui->lineEdit_i->text().mid(1,ui->lineEdit_i->text().size()-1).toLower()));

    if(ui->comboBox_add2->isHidden()==true){


    if(ui->radioButton_m->isChecked()||ui->radioButton_w->isChecked()){

        if(ui->radioButton_m->isChecked()){    new_people.set_data(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->lineEdit_age->text().toInt(),ui->radioButton_m->text());}
        else {
               new_people.set_data(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->lineEdit_age->text().toInt(),ui->radioButton_w->text());
        }
    }else  ui->statusBar->showMessage("Выберите пол",1500);}


    else if (ui->comboBox_add2->isHidden()==false&&ui->comboBox_add3->isHidden()==true){


        if(ui->radioButton_m->isChecked()||ui->radioButton_w->isChecked()){
            if(ui->radioButton_m->isChecked()){    new_people.set(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->comboBox_add2->currentText(),"",ui->lineEdit_age->text().toInt(),ui->radioButton_m->text());}
            else {
                   new_people.set(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->comboBox_add2->currentText(),"",ui->lineEdit_age->text().toInt(),ui->radioButton_w->text());
            }}else  ui->statusBar->showMessage("Выберите пол",1500);
    }


    else {


        if(ui->radioButton_m->isChecked()||ui->radioButton_w->isChecked()){
            if(ui->radioButton_m->isChecked()){    new_people.set(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->comboBox_add2->currentText(),ui->comboBox_add3->currentText(),ui->lineEdit_age->text().toInt(),ui->radioButton_m->text());}
            else {
                   new_people.set(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->comboBox_add2->currentText(),ui->comboBox_add3->currentText(),ui->lineEdit_age->text().toInt(),ui->radioButton_w->text());
            }}else  ui->statusBar->showMessage("Выберите пол",1500);
        }


    my_pupil.push_back(new_people);

    Item1->setText(my_pupil.back().return_surname().trimmed());

    Item2->setText(my_pupil.back().return_name().trimmed());

    if (my_pupil.back().return_direction_2().isEmpty()){
         Item3->setText( my_pupil.back().return_direction().trimmed());
    }
    else if (my_pupil.back().return_direction_3().isEmpty()){
        Item3->setText( my_pupil.back().return_direction().trimmed()+";\n"+my_pupil.back().return_direction_2());
    }
    else {
        Item3->setText( my_pupil.back().return_direction().trimmed()+";\n"+my_pupil.back().return_direction_2()+";\n"+my_pupil.back().return_direction_3());
    }
    Item4->setText(QString::number( my_pupil.back().return_age() ));

    Item5->setText( my_pupil.back().return_gender().trimmed());

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,0,Item1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,1,Item2);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,2,Item3);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,3,Item4);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,4,Item5);
    ui->tableWidget->setRowHeight(ui->tableWidget->rowCount()-1,53);
    ui->lineEdit_f->clear();
    ui->lineEdit_i->clear();
    ui->lineEdit_age->clear();
    ui->comboBox_add2->hide();
    ui->comboBox_add3->hide();
    ui->pushButton_add_2->hide();
    }else {
         ui->statusBar->showMessage("Заполните все поля",1500);
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
        if(ui->comboBox_add2->isHidden()==true&&ui->comboBox_add3->isHidden()==true){

        if(ui->radioButton_m->isChecked()||ui->radioButton_w->isChecked()){

            if(ui->radioButton_m->isChecked()){    edit_people.set_data(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->lineEdit_age->text().toInt(),ui->radioButton_m->text());}
            else {
                   edit_people.set_data(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->lineEdit_age->text().toInt(),ui->radioButton_w->text());
            }
        }else  ui->statusBar->showMessage("Выберите пол",1500);}

        else if (ui->comboBox_add2->isHidden()==false&&ui->comboBox_add3->isHidden()==true){
            if(ui->radioButton_m->isChecked()||ui->radioButton_w->isChecked()){
                if(ui->radioButton_m->isChecked()){    edit_people.set(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->comboBox_add2->currentText(),"",ui->lineEdit_age->text().toInt(),ui->radioButton_m->text());}
                else {
                       edit_people.set(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->comboBox_add2->currentText(),"",ui->lineEdit_age->text().toInt(),ui->radioButton_w->text());
                }}else  ui->statusBar->showMessage("Выберите пол",1500);
        }
        else if (ui->comboBox_add2->isHidden()==true&&ui->comboBox_add3->isHidden()==false){
            if(ui->radioButton_m->isChecked()||ui->radioButton_w->isChecked()){
                if(ui->radioButton_m->isChecked()){    edit_people.set(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->comboBox_add3->currentText(),"",ui->lineEdit_age->text().toInt(),ui->radioButton_m->text());}
                else {
                       edit_people.set(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->comboBox_add3->currentText(),"",ui->lineEdit_age->text().toInt(),ui->radioButton_w->text());
                }}else  ui->statusBar->showMessage("Выберите пол",1500);
        }
        else {
                if(ui->radioButton_m->isChecked()){    edit_people.set(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->comboBox_add2->currentText(),ui->comboBox_add3->currentText(),ui->lineEdit_age->text().toInt(),ui->radioButton_m->text());}
                else {
                       edit_people.set(ui->lineEdit_f->text(),ui->lineEdit_i->text(),ui->comboBox->currentText(),ui->comboBox_add2->currentText(),ui->comboBox_add3->currentText(),ui->lineEdit_age->text().toInt(),ui->radioButton_w->text());
                }
            }

        my_pupil[choice]=edit_people;
        choice=-1;
        ui->lineEdit_f->clear();
        ui->lineEdit_i->clear();
        ui->lineEdit_age->clear();
        on_pushButton_2_clicked();
        clear_lineEdit();
        ui->comboBox_add2->hide();
        ui->pushButton_delete2->hide();
        ui->pushButton_delete3->hide();
        ui->comboBox_add3->hide();
        ui->pushButton_add_2->hide();
        }
        else {
            ui->statusBar->showMessage("Заполните все поля",3000);
            }
    }
ui->pushButton_add->show();

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
        QTableWidgetItem *Item5=new QTableWidgetItem();
        Item5->setTextAlignment(Qt::AlignCenter);
        Item1->setText(my_pupil[i].return_surname().toUtf8().trimmed());
        Item2->setText(my_pupil[i].return_name().toUtf8().trimmed());
        if(my_pupil[i].return_direction_2().isEmpty()&&my_pupil[i].return_direction_3().isEmpty()){
        Item3->setText(my_pupil[i].return_direction().trimmed());}
        else if (my_pupil[i].return_direction_3().isEmpty()){
            Item3->setText(my_pupil[i].return_direction().trimmed()+";\n"+my_pupil[i].return_direction_2());
        }
        else{ Item3->setText(my_pupil[i].return_direction().trimmed()+";\n"+my_pupil[i].return_direction_2()+";\n"+my_pupil[i].return_direction_3());}
        Item4->setText(QString::number(my_pupil[i].return_age()).trimmed());
        Item5->setText(my_pupil[i].return_gender().toUtf8().trimmed());
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setRowHeight(ui->tableWidget->rowCount()-1,53);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,0,Item1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,1,Item2);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,2,Item3);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,3,Item4);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,4,Item5);
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
        ui->statusBar->showMessage("Введите в поле номер строки для удаления.",3000);
}

void MainWindow::on_pushButton_help_find_clicked()
{
     ui->statusBar->showMessage("Введите в поля данные об ученике,которого вы хотите найти.",3000);
}

void MainWindow::on_pushButton_find_clicked()
{

    QStringList str;
    int n=my_pupil.size();
    if(!(ui->lineEdit_i_find->text().isEmpty())||!ui->lineEdit_f_2->text().isEmpty()||!ui->lineEdit_age_find->text().isEmpty()||ui->comboBox_find_2->currentIndex()!=0||ui->comboBox_find->currentIndex()!=0){
        ui->lineEdit_i_find->setText( ui->lineEdit_i_find->text().replace(0,1,ui->lineEdit_i_find->text().front().toUpper()));
        ui->lineEdit_i_find->setText(ui->lineEdit_i_find->text().replace(1,ui->lineEdit_i_find->text().size()-1,ui->lineEdit_i_find->text().mid(1,ui->lineEdit_i_find->text().size()-1).toLower()));
        ui->lineEdit_f_2->setText( ui->lineEdit_f_2->text().replace(0,1,ui->lineEdit_f_2->text().front().toUpper()));
        ui->lineEdit_f_2->setText(ui->lineEdit_f_2->text().replace(1,ui->lineEdit_f_2->text().size()-1,ui->lineEdit_f_2->text().mid(1,ui->lineEdit_f_2->text().size()-1).toLower()));

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
        QTableWidgetItem *Item5=new QTableWidgetItem();
        Item5->setTextAlignment(Qt::AlignCenter);
        Item1->setText(my_pupil[i].return_surname().toUtf8().trimmed());
        Item2->setText(my_pupil[i].return_name().toUtf8().trimmed());
        if(my_pupil[i].return_direction_2().isEmpty()){
        Item3->setText(my_pupil[i].return_direction().trimmed());}
        else if (my_pupil[i].return_direction_3().isEmpty()){
            Item3->setText(my_pupil[i].return_direction().trimmed()+";\n"+my_pupil[i].return_direction_2());
        }
        else{ Item3->setText(my_pupil[i].return_direction().trimmed()+";\n"+my_pupil[i].return_direction_2()+";\n"+my_pupil[i].return_direction_3());}
        Item4->setText(QString::number(my_pupil[i].return_age()));
        Item5->setText(my_pupil[i].return_gender().toUtf8().trimmed());
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setRowHeight(ui->tableWidget->rowCount()-1,53);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,0,Item1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,1,Item2);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,2,Item3);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,3,Item4);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,4,Item5);
       if(!(ui->lineEdit_i_find->text()==my_pupil[i].return_name()||ui->lineEdit_f_2->text()==my_pupil[i].return_surname()||ui->lineEdit_age_find->text().toInt()==my_pupil[i].return_age()||ui->comboBox_find->currentText()==my_pupil[i].return_direction_2()||ui->comboBox_find->currentText()==my_pupil[i].return_direction_3()||ui->comboBox_find->currentText()==my_pupil[i].return_direction().trimmed()||ui->comboBox_find_2->currentText()==my_pupil[i].return_gender())){
           ui->tableWidget->hideRow(i);
           n--;
        }

    }
    clear_lineEdit();
    ui->comboBox_find->setCurrentIndex(0);
    ui->comboBox_find_2->setCurrentIndex(0);

    if(n==0) {
        ui->statusBar->showMessage("Ученик не найден.Попробуйте снова.",3000);
        on_pushButton_2_clicked();
    }else {
           ui->label_table->setText("Результаты поиска");
    }
    }

}

void MainWindow::on_pushButton_edit_clicked()
{
    if(!(ui->lineEdit_edit->text().isEmpty())){
    if(! my_pupil.isEmpty()){
    on_pushButton_edit_2_clicked();
        if(ui->lineEdit_edit->text().toInt()-1<=my_pupil.size()&&ui->lineEdit_edit->text().toInt()>0){
        ui->statusBar->showMessage("Ученик найден. Заполните поля:Фамиля,Имя,Возраст,Направление и нажмите кнопку \"Добавить\".",3000);
        ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,0)->setBackground(Qt::green);
        ui->lineEdit_f->setText(ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,0)->text().trimmed());
        ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,1)->setBackground(Qt::green);
        ui->lineEdit_i->setText(ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,1)->text().trimmed());

        ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,2)->setBackground(Qt::green);
        ui->comboBox->setCurrentText(ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,2)->text().section(";",0,0).trimmed());
        if(!my_pupil[ui->lineEdit_edit->text().toInt()-1].return_direction_2().isEmpty()&&my_pupil[ui->lineEdit_edit->text().toInt()-1].return_direction_3().isEmpty()){
            ui->comboBox_add2->show();
            ui->pushButton_add->hide();
            ui->pushButton_delete2->show();
            ui->pushButton_add_2->show();
            ui->comboBox_add2->setCurrentText(ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,2)->text().section(";",1,1).trimmed());
        }
        else if (!my_pupil[ui->lineEdit_edit->text().toInt()-1].return_direction_2().isEmpty()&&!my_pupil[ui->lineEdit_edit->text().toInt()-1].return_direction_3().isEmpty()){
            ui->pushButton_add->hide();
            ui->pushButton_add_2->hide();
            ui->comboBox_add2->show();
            ui->pushButton_delete2->show();
            ui->pushButton_delete3->show();
            ui->comboBox_add3->show();
             ui->comboBox_add2->setCurrentText(my_pupil[ui->lineEdit_edit->text().toInt()-1].return_direction_2().trimmed());
             ui->comboBox_add3->setCurrentText(my_pupil[ui->lineEdit_edit->text().toInt()-1].return_direction_3().trimmed());
        }
        ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,3)->setBackground(Qt::green);
        ui->lineEdit_age->setText(ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,3)->text().trimmed());
        ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,4)->setBackground(Qt::green);
        if (ui->radioButton_m->text()==ui->tableWidget->item(ui->lineEdit_edit->text().toInt()-1,4)->text().trimmed()) {ui->radioButton_m->setChecked(true);ui->radioButton_w->setChecked(false);}
        else { ui->radioButton_w->setChecked(true);ui->radioButton_m->setChecked(false);}
        choice=ui->lineEdit_edit->text().toInt()-1;
        }

    else  ui->statusBar->showMessage("Ученик не найден. Попробуйте снова.",3000);
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
                   ui->tableWidget->item(choice,4)->setBackground(Qt::white);
               }

               ui->lineEdit_f->clear();
               ui->lineEdit_i->clear();
               ui->lineEdit_age->clear();
               ui->comboBox_add3->hide();
               ui->comboBox_add2->hide();
               ui->pushButton_delete2->hide();
               ui->pushButton_delete3->hide();
               ui->pushButton_add_2->hide();
               ui->pushButton_add->show();
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

void MainWindow::on_action_4_triggered()
{

    QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить как"), QDir::currentPath(), tr("File (*.txt)") );
    if(!filename.isEmpty()){
        my_file=filename;
        QStringList save_project;
        for(int i=0;i<my_pupil.size();i++){
            save_project<<my_pupil[i].return_surname().toUtf8();
            save_project<<my_pupil[i].return_name().toUtf8();
            save_project<<my_pupil[i].return_direction().toUtf8()<<";";
            save_project<<my_pupil[i].return_direction_2()<<";";
            save_project<<my_pupil[i].return_direction_3()<<";";
            save_project<<QString::number(my_pupil[i].return_age())<<"\r\n";
        }
        QFile file(my_file);
        if (file.open(QIODevice::WriteOnly)){
                QTextStream stream(&file);
                 foreach(QString s, save_project)
                {
                    stream<<s;
                }
        }
        file.close();
    show_my_project();
    QMessageBox::information(this,"Результат","Файл сохранен","ОК");

    }

}
void MainWindow::on_action_3_triggered()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    if(my_file=="Новый проект"){
         QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить"), QDir::currentPath(), tr("File (*.txt)") );
         if(!filename.isEmpty()){
             my_file=filename;}
    }
   QStringList save_project;
   for(int i=0;i<my_pupil.size();i++){
       save_project.push_back(my_pupil[i].return_surname().toUtf8()+";");
       save_project.push_back(my_pupil[i].return_name().toUtf8()+";");
       save_project.push_back(my_pupil[i].return_direction().toUtf8()+";");
       save_project.push_back(my_pupil[i].return_direction_2().toUtf8()+";");
       save_project.push_back(my_pupil[i].return_direction_3().toUtf8()+";");
       save_project.push_back(QString::number(my_pupil[i].return_age())+";");
       save_project.push_back(my_pupil[i].return_gender().toUtf8()+";");

   }

  for (int i =0;i<save_project.size();i++){
      for(int j=0;j<save_project[i].size();j++){
          save_project[i][j].unicode()+=6;
      }
  }
   QFile file(my_file);
   if (file.open(QIODevice::WriteOnly)){
           QTextStream stream(&file);
            foreach(QString s, save_project)
           {
               stream<<s;
           }
   }
   file.close();
    show_my_project();
}

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
          open_project<< file.readAll();

        }

    }
     file.close();
int f=0;
     for (int i =0;i<open_project.size();i++){
         for(int j=0;j<open_project[i].size();j++){
             open_project[i][j].unicode()-=6;
if(open_project[i][j]==";") f++;
         }
     }


         for(int i=0;i<f;i+=7){

           Pupil temp;
           temp.set(open_project[0].section(";",i,i),open_project[0].section(";",i+1,i+1),open_project[0].section(";",i+2,i+2),open_project[0].section(";",i+3,i+3),open_project[0].section(";",i+4,i+4),open_project[0].section(";",i+5,i+5).toInt(),open_project[0].section(";",i+6,i+6));
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
    ui->lineEdit_age_find->clear();
    ui->lineEdit_i_find->clear();
    ui->lineEdit_f_2->clear();

}


void MainWindow::on_pushButton_add_clicked()
{
    ui->pushButton_add->hide();
    ui->comboBox_add2->show();
    ui->pushButton_add_2->show();

}

void MainWindow::on_pushButton_add_2_clicked()
{
    ui->pushButton_add_2->hide();
    ui->comboBox_add3->show();

}

void MainWindow::on_action_Excel_triggered()
{
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QString file_project = QFileDialog::getSaveFileName(this,tr("Сохранить"),QDir::currentPath(),tr("Документы Excel (*.csv);"),0,QFileDialog::DontConfirmOverwrite);
    QString save_project;
     if (!file_project.isNull()){
     QFile f(file_project);
     QFile::remove(file_project);
         if( f.open( (QIODevice::WriteOnly) ))
         {
             QTextStream stream(&f);
             stream.setCodec("Windows-1251");

             QStringList strList;
                      strList << "\" \"";
                     for( int c = 0; c < ui->tableWidget->horizontalHeader()->count(); ++c ) strList << "\""+ui->tableWidget->model()->headerData(c, Qt::Horizontal).toString()+"\"";
                     stream << strList.join( ";" )+"\n";

                     for( int r = 0; r < ui->tableWidget->verticalHeader()->count(); ++r )
                     {
                         strList.clear();
                         strList << "\""+ui->tableWidget->model()->headerData(r, Qt::Vertical).toString()+"\"";
                         for( int c = 0; c < ui->tableWidget->horizontalHeader()->count(); ++c )
                         {
                                   strList << "\""+ui->tableWidget->model()->data(ui->tableWidget->model()->index(r, c), Qt::DisplayRole).toString()+"\"";
                         }

                         stream << strList.join( ";" )+"\n";
                     }

         }

     f.close();
}
}

void MainWindow::on_pushButton_delete2_clicked()
{
    ui->pushButton_add->show();
    ui->comboBox_add2->hide();
    ui->pushButton_delete2->hide();
}

void MainWindow::on_pushButton_delete3_clicked()
{
    ui->pushButton_add_2->show();
    ui->comboBox_add3->hide();
     ui->pushButton_delete3->hide();
}
