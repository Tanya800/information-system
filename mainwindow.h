#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_help_clicked();

    void on_pushButton_help_find_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_edit_2_clicked();

    void on_action_2_triggered();

    void on_action_6_triggered();

    void on_action_4_triggered();

    void on_action_3_triggered();

    void on_action_5_triggered();

    void on_tableWidget_cellClicked(int row);

    void show_my_project();

    void clear_lineEdit();




    void on_pushButton_add_clicked();

    void on_pushButton_add_2_clicked();

    void on_action_Excel_triggered();

    void on_pushButton_delete2_clicked();

    void on_pushButton_delete3_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
