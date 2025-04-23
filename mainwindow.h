#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bmi_graphwidget.h"
#include "bmi_recommendationwidget.h"
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_result_clicked();

    void on_radioButton_european_toggled(bool checked);

    void on_radioButton_female_clicked();

    void on_radioButton_male_clicked();

    void on_radioButton_chr_clicked();

    void on_radioButton_american_toggled(bool checked);

    void on_pushButton_save_clicked();

    void on_pushButton_import_clicked();
private:
    Ui::MainWindow *ui;
    QString gender;
    bool hasChronicDiseases;
    BMIGraphWidget *bmiGraph;
    void importFromCSV(const QString &fileName);
    void importFromTXT(const QString &fileName);
    BMIRecommendationWidget *recommendationWidget;
};
#endif // MAINWINDOW_H
