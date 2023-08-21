#include "widget.h"
#include "ui_widget.h"
#include<bits/stdc++.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_speed = ui->speed->value();
    m_weight = ui->weight->value();
    m_time = ui->time->value();
    connect(ui->speed, SIGNAL(valueChanged(double)), this, SLOT(change_speed(double)));
    connect(ui->weight, SIGNAL(valueChanged(double)), this, SLOT(change_weight(double)));
    connect(ui->time, SIGNAL(valueChanged(double)), this, SLOT(change_time(double)));

    // connect(this, SIGNAL(calory_count_changed()), ui->caloryCountLabel, SLOT(setText(QString::number(calory_count))));
    connect(this, &Widget::calory_count_changed, [=](){
        ui->caloryCountLabel->setText(QString::number(calory_count));
    });
    count_calories();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::count_calories(){
    calory_count = ((0.0215 * (m_speed*m_speed*m_speed)) - (0.1765 * (m_speed*m_speed)) + (0.8710 * m_speed) + 1.4577) * m_weight * m_time;
    qDebug()<<calory_count;
    emit calory_count_changed();
}

void Widget::change_time(double time){
    m_time = time;
    count_calories();
}

void Widget::change_speed(double speed){
    m_speed = speed;
    count_calories();
}

void Widget::change_weight(double weight){
    m_weight = weight;
    count_calories();
}

