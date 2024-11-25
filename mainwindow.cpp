#include "mainwindow.h"
#include "tcpfileserver.h"
#include "tcpfilesender.h"
#include <QTabWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 創建 QTabWidget
    tabWidget = new QTabWidget(this);

    // 創建 TcpFileServer 和 TcpFileSender 物件
    fileServer = new TcpFileServer(this);
    fileSender = new TcpFileSender(this);

    // 創建 Tab 頁簽，並將它們加入 QTabWidget 中
    tabWidget->addTab(fileServer, QStringLiteral("SERVER"));
    tabWidget->addTab(fileSender, QStringLiteral("SENDER"));

    // 設定主佈局
    setCentralWidget(tabWidget);  // 使用 setCentralWidget 設置 QTabWidget 作為中央小部件

    setWindowTitle("檔案傳送與伺服器");
}

MainWindow::~MainWindow()
{
    delete fileServer;
    delete fileSender;
}
