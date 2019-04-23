#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <linkedlist.h>
#include <QRegExp>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

LinkedList L;
void MainWindow::on_addButton_clicked()
{
    QString item = ui->addLineEdit->text();
    QString pos = ui->addLineEdit_2->text();
    QRegExp e("\\s+$");
    QRegExp e1("\\D+$");
    QRegExp e2("0+$");
    bool ok;
    if(pos.toInt(&ok, 10) < 0)
    {
        QMessageBox::warning(this, "Предупреждение!", "Неверно указана позиция для вставки");
    }
    else if(item == "" || e.exactMatch(item))
        QMessageBox::warning(this, "Предупреждение!", "Вы ничего не ввели");
    else if(L.Cnt() >= 0 && (pos == "" || e1.exactMatch(pos) || e2.exactMatch(pos)))
        QMessageBox::warning(this, "Предупреждение!", "Неверно указана позиция для вставки");
    else
    {
        bool ok;
        L.Add(item, pos.toInt(&ok, 10));
        ui->statusBar->showMessage("Элемент добавлен");
    }
}
void MainWindow::on_delButton_clicked()
{
    QRegExp e("\\D+$");
    QRegExp e1("0+$");
    QString pos = ui->addLineEdit_3->text();
    bool ok;
    if(pos.toInt(&ok, 10) > L.Cnt())
    {
        QMessageBox::warning(this, "Предупреждение!", "Неверно указана позиция");
    }
    else if(pos.toInt(&ok, 10) < 0)
    {
        QMessageBox::warning(this, "Предупреждение!", "Неверно указана позиция");
    }
    else if(L.Cnt() == 0)
        QMessageBox::warning(this, "Предупреждение!", "Список пуст");
    else if(pos == "" || e.exactMatch(pos) || e1.exactMatch(pos))
        QMessageBox::warning(this, "Предупреждение!", "Неверно указана позиция элемента");
    else
    {
        bool ok;
        L.Remove(pos.toInt(&ok, 10));
        ui->statusBar->showMessage("Элемент удалён");
    }
}
void MainWindow::on_showButton_clicked()
{
    if(L.Cnt() == 0)
        QMessageBox::warning(this, "Предупреждение", "Список пуст");
    else
    {
        ui->showLinkedList->setText(*(L.Display()));
        ui->statusBar->showMessage("Вывод элементов");
    }
}

void MainWindow::on_showButtonReverse_clicked()
{
    if(L.Cnt() == 0)
        QMessageBox::warning(this, "Предупреждение", "Список пуст");
    else
    {
        ui->showLinkedList->setText(*(L.DisplayReverse()));
        ui->statusBar->showMessage("Вывод элементов");
    }
}
