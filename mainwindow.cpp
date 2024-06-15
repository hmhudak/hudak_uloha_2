#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , factorialThread(new FactorialThread)
    , primesThread(new PrimesThread)
{
    ui->setupUi(this);

    connect(factorialThread, &FactorialThread::progress, this, &MainWindow::updateFactorialProgress);
    connect(factorialThread, &FactorialThread::finished, this, &MainWindow::onFactorialFinished);

    connect(primesThread, &PrimesThread::progress, this, &MainWindow::updatePrimesProgress);
    connect(primesThread, &PrimesThread::finished, this, &MainWindow::onPrimesFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete factorialThread;
    delete primesThread;
}

void MainWindow::on_buttonFactorial_clicked()
{
    if (!factorialThread->isRunning()) {
        ui->progressFactorial->setValue(0);
        setFactorialRunning(true);
        factorialThread->start();
    }
}

void MainWindow::on_buttonPrimes_clicked()
{
    if (!primesThread->isRunning()) {
        ui->progressPrimes->setValue(0);
        setPrimesRunning(true);
        primesThread->start();
    }
}

void MainWindow::updateFactorialProgress(int value)
{
    ui->progressFactorial->setValue(value);
}

void MainWindow::updatePrimesProgress(int value)
{
    ui->progressPrimes->setValue(value);
}

void MainWindow::onFactorialFinished()
{
    setFactorialRunning(false);
}

void MainWindow::onPrimesFinished()
{
    setPrimesRunning(false);
}

void MainWindow::setFactorialRunning(bool running)
{
    ui->buttonFactorial->setEnabled(!running);
    ui->buttonFactorial->setText(running ? "Calculating Factorial" : "Start Factorial Calculation");
}

void MainWindow::setPrimesRunning(bool running)
{
    ui->buttonPrimes->setEnabled(!running);
    ui->buttonPrimes->setText(running ? "Calculating Primes" : "Start Primes Calculation");
}

void FactorialThread::run()
{
    const int n = 20;
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
        emit progress((i * 100) / n);
        QThread::msleep(100);
    }
    emit finished();
}

void PrimesThread::run()
{
    const int limit = 100000;
    QVector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    int processed = 0;
    for (int p = 2; p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * 2; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
        processed++;
        if (processed % (limit / 100) == 0) {
            emit progress((processed * 100) / limit);
            QThread::msleep(10);
        }
    }
    emit finished();
}
