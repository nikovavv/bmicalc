#pragma once

#include <QWidget>

class BMIGraphWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BMIGraphWidget(QWidget *parent = nullptr);
    void setBMI(double bmi);
    QString getRecommendation() const;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    double m_bmi = 0.0;
};
