#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFile>
#include <QRandomGenerator>
#include <QtMath>
#include <QCoreApplication>
#include <QTextToSpeech>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentIndex(0),
    wordIndex(0)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    loadPoems();
    loadPhotos();

    arrangeCircle();

    if (!poems.isEmpty())
    {
        int poemIndex = QRandomGenerator::global()->bounded(poems.size());
        currentWords = poems[poemIndex].split(" ", Qt::SkipEmptyParts);
    }
    else
    {
        ui->label->setText("Нет считалок!");
    }

    crownItem = nullptr;

    removeSound = new QSoundEffect(this);
    removeSound->setSource(QUrl::fromLocalFile("sounds/remove.wav"));

    winSound = new QSoundEffect(this);
    winSound->setSource(QUrl::fromLocalFile("sounds/fireworks.wav"));

    speech = new QTextToSpeech(this);
    speech->setRate(-0.2);
    speech->setVolume(1.0);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::showAbout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadPoems()
{
    QString path = QCoreApplication::applicationDirPath() + "/poems.txt";

    QFile file(path);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QString line = file.readLine().trimmed();

            if (!line.isEmpty())
                poems.append(line);
        }

        file.close();
    }
}

void MainWindow::loadPhotos()
{
    QDir dir(QCoreApplication::applicationDirPath() + "/photo");

    QStringList files = dir.entryList(QStringList() << "*.jpg" << "*.png", QDir::Files);

    for (QString file : files)
    {
        QPixmap pix(dir.filePath(file));

        if (!pix.isNull())
        {
            QString name = file.split(".")[0];

            Person *p = new Person(name, pix.scaled(80, 80));
            people.append(p);
            scene->addItem(p);
        }
    }

    if (people.isEmpty())
    {
        ui->label->setText("Нет фото!");
    }
}

void MainWindow::arrangeCircle()
{
    int n = people.size();

    if (n == 0)
        return;

    int R = 200;

    for (int i = 0; i < n; i++)
    {
        double angle = 2 * M_PI * i / n;

        int x = R * cos(angle);
        int y = R * sin(angle);

        people[i]->setPos(x, y);
    }
}

void MainWindow::on_nextWordButton_clicked()
{
    if (people.size() <= 1)
        return;

    if (currentWords.isEmpty())
        return;

    QString word = currentWords[wordIndex];
    ui->label->setText(word);
    speech->say(word);

    for (int i = 0; i < people.size(); i++)
    {
        people[i]->highlight(false);
    }

    people[currentIndex]->highlight(true);

    wordIndex++;

    if (wordIndex >= currentWords.size())
    {
        removePerson(currentIndex);
        wordIndex = 0;
    }
    else
    {
        currentIndex = (currentIndex + 1) % people.size();
    }
}

void MainWindow::removePerson(int index)
{
    if (people.isEmpty())
        return;

    if (index < 0 || index >= people.size())
        return;

    Person *p = people[index];
    p->setPos(p->x() + 300, p->y() - 300);
    scene->removeItem(p);
    people.remove(index);

    if (index >= people.size())
        currentIndex = 0;

    arrangeCircle();

    checkWinner();
    removeSound->play();
}

void MainWindow::checkWinner()
{
    if (people.size() == 1)
    {
        Person *winner = people[0];
        winner->setPos(0, 0);

        ui->label->setText(QString("%1 WON!").arg(winner->getName()));

        QPixmap crownPix("images/crown.png");
        if (!crownPix.isNull())
        {
            crownItem = new QGraphicsPixmapItem(crownPix.scaled(50, 50));
            QRectF rect = crownItem->boundingRect();
            crownItem->setPos(
                winner->x() + winner->boundingRect().width() / 2 - rect.width() / 2,
                winner->y() - rect.height()
                );
            scene->addItem(crownItem);
        }

        if (winSound)
            winSound->play();
    }
}


void MainWindow::on_randomPoemButton_clicked()
{
    if (poems.isEmpty())
    {
        ui->label->setText("Нет считалок!");
        return;
    }

    int randomIndex = QRandomGenerator::global()->bounded(poems.size());

    currentWords = poems[randomIndex].split(" ", Qt::SkipEmptyParts);

    wordIndex = 0;
    currentIndex = 0;

    ui->label->setText("Случайная считалка №" + QString::number(randomIndex + 1));
}

void MainWindow::showAbout()
{
    QMessageBox::information(this, "Справка",
                             "Лабу СЧИТАЛОЧКУ сделал\n"
                             "Рубан Артём Витальевич\n "
                             "7 группа");
}
