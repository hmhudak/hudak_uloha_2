#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class FactorialThread;
class PrimesThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonFactorial_clicked();
    void on_buttonPrimes_clicked();
    void updateFactorialProgress(int value);
    void updatePrimesProgress(int value);
    void onFactorialFinished();
    void onPrimesFinished();

private:
    Ui::MainWindow *ui;
    FactorialThread *factorialThread;
    PrimesThread *primesThread;

    void setFactorialRunning(bool running);
    void setPrimesRunning(bool running);
};

class FactorialThread : public QThread
{
    Q_OBJECT

public:
    void run() override;

signals:
    void progress(int value);
    void finished();
};

class PrimesThread : public QThread
{
    Q_OBJECT

public:
    void run() override;

signals:
    void progress(int value);
    void finished();
};

#endif // MAINWINDOW_H
