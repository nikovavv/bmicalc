#ifndef BMI_RECOMMENDATIONWIDGET_H
#define BMI_RECOMMENDATIONWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class BMIRecommendationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BMIRecommendationWidget(QWidget *parent = nullptr);
    void setRecommendation(double bmi);

private:
    QLabel *titleLabel;
    QLabel *recommendationLabel;
    QLabel *risksLabel;
};

#endif // BMI_RECOMMENDATIONWIDGET_H
