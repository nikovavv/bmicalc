#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <cmath>
#include "bmi_graphwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QFileDialog>
#include "bmi_recommendationwidget.h"
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BMIGraphWidget *graph = new BMIGraphWidget(this);
    graph->setFixedHeight(60); // Фиксируем высоту
    graph->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Горизонтальное растяжение

    // Добавляем в layout с минимальным растяжением
    ui->verticalLayout->insertWidget(0, graph, 0);
    this->bmiGraph = graph;
    connect(ui->pushButton_save, &QPushButton::clicked, this, &MainWindow::on_pushButton_save_clicked);
    connect(ui->pushButton_import, &QPushButton::clicked, this, &MainWindow::on_pushButton_import_clicked);
    recommendationWidget = new BMIRecommendationWidget(this);
    recommendationWidget->setMinimumHeight(150);
    ui->verticalLayout->addWidget(recommendationWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_female_clicked()
{
    gender = "женский";
}

void MainWindow::on_radioButton_male_clicked()
{
    gender = "мужской";
}
void MainWindow::on_radioButton_european_toggled(bool checked)
{
    if (checked) {
        ui->label_weight1->setText("кг");
        ui->label_height1->setText("см");
    }
}

void MainWindow::on_radioButton_american_toggled(bool checked)
{
    if (checked) {
        ui->label_weight1->setText("фунты");
        ui->label_height1->setText("футы");
    }
}

void MainWindow::on_radioButton_chr_clicked()
{
    hasChronicDiseases = ui->radioButton_chr->isChecked();
}
void MainWindow::on_pushButton_result_clicked()
{
    if (!ui->radioButton_european->isChecked() && !ui->radioButton_american->isChecked()) {
        QMessageBox::warning(this, "Ошибка", "Выберите систему измерения!");
        return;
    }

    if (gender.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите пол!");
        return;
    }

    double weight = ui->lineEdit_2->text().toDouble();
    double height = ui->lineEdit_1->text().toDouble();

    if (weight <= 0 || height <= 0) {
        ui->label->setText("Ошибка: введите корректные данные!");
        return;
    }
    if (ui->radioButton_american->isChecked()) {
        weight *= 0.453592;
        height *= 30.48;
    }
    int age = ui->lineEdit_age->text().toInt();
    if (age <= 0 || age > 120) {
        ui->label->setText("Ошибка: введите корректный возраст!");
        return;
    }
    height /= 100.0;
    QString activityLevel = ui->comboBox_activity->currentText();
    double activityFactor = 1.0;

    if (activityLevel == "Низкий") activityFactor = 1.0;
    else if (activityLevel == "Средний") activityFactor = 0.95;
    else if (activityLevel == "Высокий") activityFactor = 0.9;
    double bmi = weight / (height * height);
    QString category;
    if (hasChronicDiseases) {
        if (bmi < 20) category = "Недостаточный вес (риск!)";
        else if (bmi < 23) category = "Норма (безопасный диапазон)";
        else if (bmi < 27) category = "Избыточный вес (риск!)";
        else category = "Ожирение (высокий риск!)";
    } else if (age < 18) {
        category = "Для оценки ИМТ у детей и подростков обратитесь к педиатру.";
    } else if (age >= 65) {
        if (bmi < 23) category = "Недостаточный вес (пожилой возраст)";
        else if (bmi < 28) category = "Норма (для пожилых)";
        else if (bmi < 30) category = "Избыточный вес";
        else category = "Ожирение";
    } else if (gender == "женский") {
        if (bmi < 18.5) category = "Недостаточный вес";
        else if (bmi < 24) category = "Норма";
        else if (bmi < 30) category = "Избыточный вес";
        else category = "Ожирение";
    } else {
        if (bmi < 20) category = "Недостаточный вес";
        else if (bmi < 25) category = "Норма";
        else if (bmi < 30) category = "Избыточный вес";
        else category = "Ожирение";
    }
    double fatPercent = 0.0;
    if (gender == "мужской")
        fatPercent = (1.20 * bmi + 0.23 * age - 16.2) * activityFactor;
    else
        fatPercent = (1.20 * bmi + 0.23 * age - 5.4) * activityFactor;
    QString chronicInfo = hasChronicDiseases ? " (хронические заболевания)" : "";
    recommendationWidget->setRecommendation(bmi);

    // Обновляем график
    bmiGraph->setBMI(bmi);

    // Выводим краткую информацию
    ui->label->setText(QString("ИМТ: %1 (%2)\nПроцент жира: %3%")
                           .arg(bmi, 0, 'f', 1)
                           .arg(category)
                           .arg(fatPercent, 0, 'f', 1));
}




void MainWindow::on_pushButton_save_clicked()
{
    if (ui->label->text().isEmpty() || ui->label->text().startsWith("Ошибка")) {
        QMessageBox::warning(this, "Ошибка", "Сначала рассчитайте ИМТ!");
        return;
    }
    QString fileName = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss") + "_bmi_report.txt";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось создать файл для сохранения!");
        return;
    }

    QTextStream out(&file);
    out << "Отчет об ИМТ\n";
    out << "Дата: " << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "\n\n";

    out << "Основные данные:\n";
    out << "Пол: " << gender << "\n";
    out << "Возраст: " << ui->lineEdit_age->text() << " лет\n";
    out << "Хронические заболевания: " << (hasChronicDiseases ? "да" : "нет") << "\n";
    out << "Уровень активности: " << ui->comboBox_activity->currentText() << "\n\n";

    out << "Параметры тела:\n";
    if (ui->radioButton_european->isChecked()) {
        out << "Рост: " << ui->lineEdit_1->text() << " см\n";
        out << "Вес: " << ui->lineEdit_2->text() << " кг\n";
    } else {
        out << "Рост: " << ui->lineEdit_1->text() << " футов\n";
        out << "Вес: " << ui->lineEdit_2->text() << " фунтов\n";
    }

    out << "\nРезультаты:\n";
    out << ui->label->text() << "\n";

    file.close();
    QMessageBox::information(this, "Сохранено", "Данные успешно сохранены в файл: " + fileName);
}


void MainWindow::on_pushButton_import_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл с данными",
                                                    "", "Текстовые файлы (*.txt);;CSV файлы (*.csv);;Все файлы (*)");
    if (fileName.isEmpty()) {
        return;
    }

    if (fileName.endsWith(".csv", Qt::CaseInsensitive)) {
        importFromCSV(fileName);
    } else {
        importFromTXT(fileName);
    }
}

void MainWindow::importFromTXT(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
        return;
    }

    QTextStream in(&file);
    QString line;
    QMap<QString, QString> data;

    while (!in.atEnd()) {
        line = in.readLine();
        if (line.contains(":")) {
            QStringList parts = line.split(":");
            if (parts.size() >= 2) {
                QString key = parts[0].trimmed();
                QString value = parts[1].trimmed();
                data[key] = value;
            }
        }
    }
    file.close();

    // Заполняем поля формы
    if (data.contains("Пол")) {
        if (data["Пол"] == "женский") {
            ui->radioButton_female->setChecked(true);
            gender = "женский";
        } else if (data["Пол"] == "мужской") {
            ui->radioButton_male->setChecked(true);
            gender = "мужской";
        }
    }

    if (data.contains("Возраст")) {
        QString ageStr = data["Возраст"].split(" ")[0];
        bool ok;
        int age = ageStr.toInt(&ok);
        if (ok && age > 0 && age <= 120) {
            ui->lineEdit_age->setText(ageStr);
        }
    }

    if (data.contains("Хронические заболевания")) {
        hasChronicDiseases = (data["Хронические заболевания"] == "да");
        ui->radioButton_chr->setChecked(hasChronicDiseases);
    }

    if (data.contains("Уровень активности")) {
        int index = ui->comboBox_activity->findText(data["Уровень активности"]);
        if (index >= 0) {
            ui->comboBox_activity->setCurrentIndex(index);
        }
    }

    if (data.contains("Рост")) {
        QString heightStr = data["Рост"].split(" ")[0];
        bool ok;
        double height = heightStr.toDouble(&ok);
        if (ok && height > 0) {
            ui->lineEdit_1->setText(heightStr);

            if (data["Рост"].contains("см")) {
                ui->radioButton_european->setChecked(true);
            } else if (data["Рост"].contains("футов")) {
                ui->radioButton_american->setChecked(true);
            }
        }
    }

    if (data.contains("Вес")) {
        QString weightStr = data["Вес"].split(" ")[0];
        bool ok;
        double weight = weightStr.toDouble(&ok);
        if (ok && weight > 0) {
            ui->lineEdit_2->setText(weightStr);
        }
    }

    QMessageBox::information(this, "Импорт завершен", "Данные успешно загружены из файла!");
}
void MainWindow::importFromCSV(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть CSV файл!");
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine(); // Пропускаем заголовок

    if (in.atEnd()) {
        QMessageBox::warning(this, "Ошибка", "Файл пуст или имеет неверный формат!");
        return;
    }

    line = in.readLine();
    QStringList fields = line.split(";");

    if (fields.size() < 9) {
        QMessageBox::warning(this, "Ошибка", "Неверный формат CSV файла!");
        return;
    }

    // Заполняем данные из CSV
    if (fields[1] == "женский") {
        ui->radioButton_female->setChecked(true);
        gender = "женский";
    } else {
        ui->radioButton_male->setChecked(true);
        gender = "мужской";
    }

    ui->lineEdit_age->setText(fields[2]);
    ui->radioButton_chr->setChecked(fields[3] == "да");
    hasChronicDiseases = (fields[3] == "да");

    int activityIndex = ui->comboBox_activity->findText(fields[4]);
    if (activityIndex >= 0) {
        ui->comboBox_activity->setCurrentIndex(activityIndex);
    }

    ui->lineEdit_1->setText(fields[5]);
    ui->lineEdit_2->setText(fields[6]);

    file.close();
    QMessageBox::information(this, "Импорт CSV", "Данные успешно загружены из CSV файла!");
}
