#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void count_calories();
    void change_time(double time);
    void change_speed(double speed);
    void change_weight(double weight);
signals:
    void calory_count_changed();
private:
    Ui::Widget *ui;
    double m_time;
    double m_speed;
    double m_weight;
    int calory_count;
};
#endif // WIDGET_H
