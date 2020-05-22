#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imgenc.cpp"


using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".",
          tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));

    if(flag==0)
    {
        Org_fn=fileName;
    }

    QStringList parts= fileName.split("/");
    filename = parts.at(parts.size()-1);

    qDebug() << filename;

       image= imread(fileName.toUtf8().data());
       if ( !image.data )
         {
           QMessageBox::information(
                   this,
                   tr("Alert"),
                   tr("No image chosen") );
           return;
         }
       namedWindow("Original Image");
       imshow("Original Image", image);


}



void MainWindow::on_lineEdit_textChanged(const QString &k)
{
   // qDebug() << key;
    key=k;
}

void MainWindow::on_pushButton_2_clicked()
{
       encrOpt(key.toUtf8().data(), fileName.toUtf8().data(),filename.toUtf8().data());
       flag=1;
}

void MainWindow::on_pushButton_3_clicked()
{

    QStringList parts= Org_fn.split("/");
    filename = parts.at(parts.size()-1);

    decrOpt(de_key.toUtf8().data(), fileName.toUtf8().data(),filename.toUtf8().data());
    flag=0;

}

void MainWindow::on_lineEdit_2_textChanged(const QString &k2)
{
    de_key=k2;
}
