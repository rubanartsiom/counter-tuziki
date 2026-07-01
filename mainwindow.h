#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>
#include <QStringList>
#include <QTextToSpeech>
#include "person.h"
#include <QSoundEffect>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_nextWordButton_clicked();
    void on_randomPoemButton_clicked();
    void showAbout();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QVector<Person*> people;
    QStringList poems;
    QStringList currentWords;

    int currentIndex;
    int wordIndex;

    QTextToSpeech *speech;
    QGraphicsPixmapItem *crownItem;
    QSoundEffect *removeSound;
    QSoundEffect *winSound;

    void loadPoems();
    void loadPhotos();
    void arrangeCircle();
    void removePerson(int index);
    void checkWinner();
};

#endif // MAINWINDOW_H