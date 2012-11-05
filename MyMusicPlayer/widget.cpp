#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Media Player"));
    audio=new Phonon::MediaObject();
    audio->setTickInterval(1);
    audioOutput=new Phonon::AudioOutput(Phonon::VideoCategory);
    Phonon::createPath(audio,audioOutput);
    msicinfoObj=new Phonon::MediaObject(this);

    volumeSlider=new Phonon::VolumeSlider(audioOutput,this);
    volumeSlider->move(190,100);
    volumeSlider->resize(50,20);
    volumeSlider->setStyleSheet("background-color:rgb(255,255,255,255,100)");
    volumeSlider->setFixedWidth(100);

    seekSlider=new Phonon::SeekSlider(audio,this);
    seekSlider->move(10,35);
    seekSlider->resize(170,20);
    seekSlider->setStyleSheet("background-color:rgb(255,255,255,255,100)");
    creatActions();


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_toolButton_list_clicked(bool checked)
{

}

void Widget::on_toolButton_lrc_clicked(bool checked)
{

}

void Widget::on_toolButton_playpause_clicked()
{
    if(sourceList.isEmpty())
    {
        QMessageBox::information(this,tr("No Music"),tr("No Files to play!"));
        return ;
    }
    audio->setQueue(sourceList);
    if(audio->state()=QPhonon::PlayingState)
        audio->pause();
    else
        audio->paly();
}

void Widget::on_toolButton_stop_clicked()
{
    audio->stop();
}


void Widget::on_toolButton_open_clicked()
{
    QStringList files=QFileDialog::getOpenFileNames(this,tr("selete files to play"));
    QString file;
    foreach(file,files)
    {
        ui->listWidget->addItem(file);
        sourceList.append(file);

    }

}

void Widget::creatActions()
{
    QIcon iconremove(":/images/remove.png");
    QIcon iconstop(":/images/gtk-media-stop.png");
    QIcon iconopen(":/images/gtk-open.png");
    QIcon iconsound(":/images/sound.png");
    QIcon iconexit(":/images/exit.png");
    iconPause=new QIcon(":/images/gtk-media-pause.png");
    iconPlay=new QIcon(":/images/gtk-media-play-ltr.png");

    remove=new QAction(iconremove,tr("clear the list"),this);
    connect(remove,SIGNAL(triggered()),this,SLOT(removeSlot()));

    play=new QAction(*iconPlay,tr("play"),this);
    connect(paly,SIGNAL(triggered()),this,SLOT(on_toolButton_playpause_clicked()));

    stop=new QAction(iconstop,tr("stop"),this);
    connect(stop,SIGNAL(triggered()),this,SLOT(stop()));

    open=new QAction(iconopen,tr("open"),this);
    connect(stop,SIGNAL(triggered()),this,SLOT(on_toolButton_open_clicked()));

    sound=new QAction(iconsound,tr("quite"),this);
    sound->setChecked(true);
    connect(sound,SIGNAL(triggered(bool)),audioOutput,SLOT(setMuted(bool)));

    exit=new QAction(iconexit,tr("exit"),this);
    connect(exit,SIGNAL(triggered()),this,SLOT(exitSlot()));
}
