#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QAction>
#include <QIcon>
#include <QList>
#include <QCoreApplication>
#include <QDebug>

#include <Phonon/AudioOutput>
#include <phonon>
#include <QTimer>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Phonon::MediaObject *audio;
    Phonon::AudioOutput *audioOutput;
    Phonon::MediaObject *msicinfoObj;
    Phonon::VolumeSlider *volumeSlider;
    Phonon::SeekSlider *seekSlider;
    QList<Phonon::MediaSource>  sourceList;
    Phonon::MediaSource currentSource;

    QIcon *iconPause ;
    QIcon *iconPlay ;
    QAction *remove;
    QAction *play;
    QAction *stop;
    QAction *open;
    QAction *sound;
    QAction *exit;

    QTimer songTimer;

    int currentIndex;
    int numberOfMusic;

private slots:
//    void on_toolButton_list_clicked(bool checked);
//    void on_toolButton_lrc_clicked(bool checked);
    void creatActions();
    void removeSlot();
    void refreshTime();

    void on_toolButton_playpause_clicked();
    void on_toolButton_playstop_clicked();
    void on_toolButton_stop_clicked();
    void on_toolButton_open_clicked();

    void on_toolButton_list_clicked();
    void on_toolButton_lrc_clicked();
    void on_toolButton_next_clicked();
    void on_toolButton_last_clicked();
};

#endif // FORM_H
