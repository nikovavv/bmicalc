#include "bmi_graphwidget.h"
#include <QPainter>
#include <QFontMetrics>
#include <QToolTip>
#include <QMouseEvent>

BMIGraphWidget::BMIGraphWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true); // Включаем отслеживание движения мыши
}

void BMIGraphWidget::setBMI(double bmi) {
    m_bmi = bmi;
    update();
}

QString BMIGraphWidget::getRecommendation() const {
    if (m_bmi < 18.5) {
        return "Дефицит массы тела\n\nРекомендации:\n"
               "• Увеличьте калорийность питания\n"
               "• Питайтесь 5-6 раз в день\n"
               "• Добавьте силовые тренировки\n"
               "• Проконсультируйтесь с диетологом";
    }
    else if (m_bmi < 25) {
        return "Нормальный вес\n\nРекомендации:\n"
               "• Поддерживайте текущий режим\n"
               "• Сбалансированное питание\n"
               "• Регулярная физическая активность\n"
               "• Контролируйте вес раз в месяц";
    }
    else if (m_bmi < 30) {
        return "Избыточный вес\n\nРекомендации:\n"
               "• Уменьшите калорийность питания\n"
               "• Увеличьте физическую активность\n"
               "• Ограничьте быстрые углеводы\n"
               "• Пейте больше воды";
    }
    else {
        return "Ожирение\n\nРекомендации:\n"
               "• Обязательно обратитесь к врачу\n"
               "• Постепенное снижение веса\n"
               "• Комплексный подход к лечению\n"
               "• Избегайте экстремальных диет";
    }
}

void BMIGraphWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int w = width();
    int h = 60;
    int textHeight = 15;
    int graphHeight = h -20;
    double minBMI = 10.0;
    double maxBMI = 40.0;

    auto bmiToX = [&](double bmi) -> int {
        return static_cast<int>(((bmi - minBMI) / (maxBMI - minBMI)) * w);
    };

    // Категории ИМТ
    struct BMICategory {
        double start, end;
        QString name;
        QColor color;
        QString tip;
    };

    const QVector<BMICategory> categories = {
        {10.0, 18.5, "Дефицит", QColor("#ADD8E6"), "Недостаточный вес - риск для здоровья"},
        {18.5, 25.0, "Норма", QColor("#90EE90"), "Здоровый вес - поддерживайте его"},
        {25.0, 30.0, "Избыток", QColor("#FFD580"), "Избыточный вес - пора заняться собой"},
        {30.0, 40.0, "Ожирение", QColor("#FF7F7F"), "Ожирение - обратитесь к специалисту"}
    };

    // Рисуем цветные зоны
    painter.setPen(Qt::NoPen);
    QFont font = painter.font();
    font.setPointSize(8);
    painter.setFont(font);

    for (const auto& cat : categories) {
        int x1 = bmiToX(cat.start);
        int x2 = bmiToX(cat.end);
        painter.setBrush(cat.color);
        painter.drawRect(x1, 0, x2-x1, graphHeight);

        // Подписи категорий
        painter.setPen(Qt::black);
        int textWidth = QFontMetrics(font).horizontalAdvance(cat.name);
        painter.drawText(x1 + (x2-x1-textWidth)/2, h-5, cat.name);
    }

    // Текущее значение ИМТ
    if (m_bmi > 0) {
        int x = qBound(bmiToX(minBMI), bmiToX(m_bmi), bmiToX(maxBMI));

        // Линия ИМТ
        painter.setPen(QPen(Qt::black, 2));
        painter.drawLine(x, 0, x, graphHeight);

        // Текст ИМТ
        QString bmiText = QString::number(m_bmi, 'f', 1);
        font.setBold(true);
        painter.setFont(font);
        int textWidth = QFontMetrics(font).horizontalAdvance(bmiText);
        painter.drawText(x-textWidth/2, graphHeight-5, bmiText);
    }

    // Граница
    painter.setPen(Qt::black);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(0, 0, w, graphHeight);
}

void BMIGraphWidget::mouseMoveEvent(QMouseEvent *event)
{
    // Показываем подсказку при наведении на категории
    double minBMI = 10.0;
    double maxBMI = 40.0;

    // Получаем позицию курсора
    QPoint pos = event->pos();
    double bmi = minBMI + (maxBMI-minBMI) * pos.x() / width();
    QPoint globalPos = event->globalPosition().toPoint();

    if (bmi < 18.5) {
        QToolTip::showText(globalPos, "Дефицит массы тела\nРекомендуется увеличить калорийность питания", this);
    }
    else if (bmi < 25) {
        QToolTip::showText(globalPos, "Нормальный вес\nПоддерживайте текущий режим питания", this);
    }
    else if (bmi < 30) {
        QToolTip::showText(globalPos, "Избыточный вес\nРекомендуется увеличить физическую активность", this);
    }
    else {
        QToolTip::showText(globalPos, "Ожирение\nРекомендуется консультация специалиста", this);
    }

    QWidget::mouseMoveEvent(event);
}
