#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionTheme_triggered();

    void on_actionHighlight_triggered();

    void on_actionBackground_Color_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};
#endif // MAINWINDOW_H
