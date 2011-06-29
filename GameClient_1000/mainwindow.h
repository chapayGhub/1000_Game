#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "thousandclient.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    friend class ThousandClient;

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    void setupWidgets();

    ThousandClient *client;
    ThousandClientDataParser *parser;
public slots:
    void sendMessageToServer();
    void sendRegistrationDataToServer();
    void sendAuthorizationDataToServer();
    void sendMoveToServer();

    void addMessageInChatView(QString);
    void getSomeMessagesFromServer(QVector<QString>);
};


#endif // MAINWINDOW_H
