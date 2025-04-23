// bmi_graphwidget.cpp
#include "bmi_graphwidget.h"
#include <QPainter>

BMIGraphWidget::BMIGraphWidget(QWidget *parent)
    : QWidget(parent)
{
    // Инициализация виджета
}

void BMIGraphWidget::setBMI(double bmiValue)
{
    bmi = bmiValue;
    update();  // Обновляем виджет для перерисовки
}

void BMIGraphWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Отображаем график ИМТ
    int width = this->width();
    int height = this->height();

    // Пример: рисуем горизонтальную линию для ИМТ
    painter.setPen(QPen(Qt::black, 2));
    painter.drawLine(0, height / 2, width, height / 2); // линия посередине

    // Рисуем точку для ИМТ
    int x = static_cast<int>(bmi * 10);  // Преобразуем ИМТ в x-координату (пример)
    painter.setBrush(QBrush(Qt::red));
    painter.drawEllipse(x, height / 2 - 10, 10, 10);  // Рисуем точку

    QWidget::paintEvent(event);
}
