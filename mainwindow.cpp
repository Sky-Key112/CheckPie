
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QChart>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>

/***************DataFrame库引入**************************/
#include <DataFrame/DataFrame.h>                   // Main DataFrame header
#include <DataFrame/DataFrameFinancialVisitors.h>  // Financial algorithms
#include <DataFrame/DataFrameMLVisitors.h>         // Machine-learning algorithms
#include <DataFrame/DataFrameStatsVisitors.h>      // Statistical algorithms
#include <DataFrame/Utils/DateTime.h>              // Cool and handy date-time object
using namespace hmdf;
using StrDataFrame = StdDataFrame<std::string>;
/**********************************************/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec()) {
        ui->lineEdit->clear();
        QStringList files = dialog.selectedFiles();

        ui->lineEdit->setText(files.join(";"));
    }
}

void MainWindow::openfile()
{
    QString Path =ui->lineEdit->text();
    QFileInfo fileInfo(Path);
    if (fileInfo.isDir()) { // 如果是一个文件夹
        QDir dir(Path);
        QStringList nameFilters;
        nameFilters << "*.csv"; //文件名过滤器
        QStringList csvFiles = dir.entryList(nameFilters, QDir::Files | QDir::NoDotAndDotDot);

        if (csvFiles.isEmpty()) {
            QMessageBox::warning(this, "Warning", "No CSV files found in the directory");
            return;
        }
        foreach (const QString &csvFile, csvFiles) {
            QString filePath = Path + "/" + csvFile;
            openCsvFile(filePath);
        }
    }else { // 如果是一个单独的.csv文件
        if (fileInfo.suffix() == "csv") {
            openCsvFile(Path);
        } else {
            QMessageBox::warning(this, "Warning", "Please select a CSV file or directory containing CSV files");
            return;
        }
    }
}
    void MainWindow::openCsvFile(const QString &filePath)
    {
        StrDataFrame csv_df;
    try {
        qDebug() <<filePath.toStdString().c_str()<<Qt::endl;
        csv_df.read(filePath.toStdString().c_str(),io_format::csv);

    } catch (const DataFrameError &ex) {
        QMessageBox::warning(this,"Warning","打开csv错误");
        qDebug() <<"打开csv错误:" << ex.what() << Qt::endl;
        }
    csv_df.write("csv_test.csv");


    }
