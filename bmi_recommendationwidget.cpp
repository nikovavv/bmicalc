#include "bmi_recommendationwidget.h"
#include <QVBoxLayout>

BMIRecommendationWidget::BMIRecommendationWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(10);

    titleLabel = new QLabel("Рекомендации по ИМТ");
    titleLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

    recommendationLabel = new QLabel();
    recommendationLabel->setWordWrap(true);

    risksLabel = new QLabel();
    risksLabel->setWordWrap(true);
    risksLabel->setStyleSheet("color: #800000;");

    layout->addWidget(titleLabel);
    layout->addWidget(recommendationLabel);
    layout->addWidget(risksLabel);
}

void BMIRecommendationWidget::setRecommendation(double bmi)
{
    if (bmi < 18.5) {
        titleLabel->setText("Дефицит массы тела");
        recommendationLabel->setText("У вас недостаточная масса тела. Если значение индекса массы тела "
                                     "близко к 18,4 – не отчаивайтесь! Начните питаться рационально и "
                                     "сбалансированно – еще чуть-чуть и ваш вес придет в норму, которая "
                                     "будет полезна для вашего здоровья. Рекомендуем вам обратиться за "
                                     "консультацией к диетологу или терапевту, он назначит вам индивидуальные "
                                     "рекомендации.");
        risksLabel->setText("Чем опасен дефицит массы тела:\n"
                            "• Поражение иммунитета (организм меньше сопротивляется болезням)\n"
                            "• Остеопороз (повышенная хрупкость костей)\n"
                            "• Выпадение волос\n"
                            "• Гормональные сбои у женщин");
    }
    else if (bmi < 25) {
        titleLabel->setText("Нормальный вес");
        recommendationLabel->setText("У вас здоровый вес. Вы молодец, но расслабляться не надо. Нужно стараться, "
                                     "чтобы ваш индекс массы тела находился примерно в среднем значении и не "
                                     "приближался к границам значений нормального веса. Поэтому, питайтесь правильно "
                                     "и поддерживайте ежедневный умеренный уровень физической активности.");
        risksLabel->setText("");
    }
    else if (bmi < 30) {
        titleLabel->setText("Избыточный вес");
        recommendationLabel->setText("У вас избыточная масса тела, но не расстраивайтесь! Это еще не ожирение – вам "
                                     "просто нужно взять себя в руки, ведь вам нужно совсем немного сбросить, чтобы "
                                     "индекс массы тела показал нормальное значение. Однако, помните: без ваших усилий "
                                     "вы быстро перейдете границу 30-ти, а это уже стадия ожирения.");
        risksLabel->setText("Чем опасен избыточный вес:\n"
                            "• Развитие ожирения\n"
                            "• Артериальная гипертония\n"
                            "• Сахарный диабет\n"
                            "• Ишемическая болезнь сердца");
    }
    else {
        titleLabel->setText("Ожирение");
        recommendationLabel->setText("У вас ожирение, а это значит, что лучше обратиться за квалифицированной "
                                     "помощью к врачу-специалисту, чтобы начать снижение веса. Помните, на "
                                     "данном этапе ваше здоровье уже пошатнулось, не изнуряйте организм "
                                     "голодовками и тяжелыми изматывающими тренировками.");
        risksLabel->setText("Чем опасно ожирение:\n"
                            "• Сахарный диабет\n"
                            "• Артериальная гипертония\n"
                            "• Атеросклероз\n"
                            "• Инфаркт и инсульт\n"
                            "• Нарушение работы ЖКТ\n"
                            "• Скелетно-мышечные нарушения");
    }
}
