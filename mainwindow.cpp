#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    currentFile = filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
    }
    setWindowTitle("BhavyaPad" + filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
   QString fileName  = QFileDialog::getSaveFileName(this, "Save as");
   QFile file(fileName);
   if(!file.open(QFile::WriteOnly | QFile::Text)){
       QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
       return;
   }
   currentFile=fileName;
   setWindowTitle("BhavyaPad" + fileName);
   QTextStream out(&file);
   QString text = ui->textEdit->toPlainText();
   out << text;
   file.close();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot Acecss Printer");
        return;
    }
    ui->textEdit->print(&printer);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(
                    &ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok) {
        ui->textEdit->setFont(font);
    } else {
      return;
    }
}

void MainWindow::on_actionColor_triggered()
{
    QColorDialog *dialog = new QColorDialog(this);
    QColor color = dialog->getColor();
    QVariant variant = color;
    QString colorcode = variant.toString();
    ui->textEdit->setTextColor(colorcode);
}

void MainWindow::on_actionHighlight_triggered()
{
    QColorDialog *dialog = new QColorDialog(this);
    QColor color = dialog->getColor();
    QVariant variant = color;
    QString colorcode = variant.toString();
    ui->textEdit->setTextBackgroundColor(colorcode);
}

void MainWindow::on_actionTheme_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this);

    QPalette p = ui->textEdit->palette();
    p.setColor(QPalette::Base, color);
    ui->textEdit->setPalette(p);
}



void MainWindow::on_actionBackground_Color_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose an Image"), "", tr("Images(*.png *.jpg *.jpeg *.bmp *.gif *.heic)"));

    if(QString::compare(filename, QString()) != 0){

        QImage image;
        bool valid = image.load(filename);

        if(valid){
           image = image.scaledToWidth(ui->textEdit->width(), Qt::SmoothTransformation);
           QPalette palette;
           palette.setBrush(QPalette::Background, image);
           ui->textEdit->setPalette(palette);
        }else{

        }
    }
}
