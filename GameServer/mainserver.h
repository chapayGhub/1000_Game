/**
* @file mainserver.h
* @author Kharkunov Eugene
* @date 2.06.2011
* @brief �������� ����� �������� ���� ����������
*/

#ifndef MAINSERVER_H
#define MAINSERVER_H

#include <QtGui/QMainWindow>
#include "httpserver.h"
#include <QItemSelectionModel>

class TableModel;
class QTableView;
class QTextEdit;

/**
* @class MainServer
* @brief �����, ����������� ������ � ��������� �������� �������
* @note ���������� ��� ���������
*/
class MainServer : public QMainWindow
{
    Q_OBJECT
public:
    /**
    * @brief ����� ��������� ������� ������ MainServer
    * @return ��������� �� ������ ������ MasinServer
    */
    static MainServer* getInstance();

    //! ���������� ��������� ������ ������ MainServer
    static void destroy();

    /**
    * @brief ����������� �� ���������
    * @param parent ��������� �� ������������ ������
    */
    explicit MainServer(QWidget *parent = 0);

    //! ���������� ����������
    ~MainServer();

private:
    /**
    * @brief �������� ����
    *
    * �������� � ���� ����� � �������� �������� �������� � �� �����������.
    */
    void createMenus();

    //! ������ ������ MainServer
    static MainServer *server;

    //! HTTP ������
    HttpServer *_mHttpServer;

    //! ������, �������������� ������ � ����������� �������
    QItemSelectionModel *selectionModel;

    //! ������ ���������� �� ���������� ������ � �������, � ��������� �� ���������� ������� ������ ��������
    QTimer *timer;

    //! ���� "����". �������� �������� ��������, ��������� � ���������� ��������� ��������
    QMenu *fileMenu;

    //! ���� "���������". �������� � ���� ��������� ��������
    QMenu *settingsMenu;

    //! ���� "������"
    QMenu *aboutMenu;

    //! ������, ���������� ���������� � ������������������ ������� ��������
    QDockWidget *serversList;

    //! ������, ���������� �������������� ���������, ����������� �� ����� ������ ��������
    QDockWidget *serversMessages;

    //! ��������� ������ ������������� ������
    TableModel *model;

    //! ������ ��� ����������� ������ � ���� �������
    QTableView *view;

    //! �������� ���������� � ������ ��������
    QTextEdit *messanges;

    QAction *actionStartServer;
    QAction *actionStopServer;
    QAction *actionRestartServer;
    QAction *actionStartAllServers;
    QAction *actionStopAllServers;
    QAction *actionRestartAllServers;
    QAction *actionChangePort;
private slots:
    //! ���� ������� ���������� �������
    void slotServerStart();

    //! ���� ��� ��������� ���������� �������
    void slotServerStop();

    //! ���� ��� ����������� ���������� �������
    void slotServerRestart();

    //! ���� ��� ������� ���� ��������� ��������
    void slotAllServersStart();

    //! ���� ��� ��������� ���� ��������� ��������
    void slotAllServersStop();

    //! ���� ��� ����������� ���� ��������� ��������
    void slotAllServersRestart();

    //! ���� ��� ��������� ������ ����� ��������� ��� ���������� �������
    void slotSetNewPort();

    //! ���� ��� ���������� ������ ����� ����������
    void retranslateApp();

    //! ���� ��� ������ ���������� � ����������
    void about();

    /**
    * @brief ���� ��� ��������� ��������� ������
    * @param ���������� ��������
    * @param ������������ ��������
    */
    void slotSelectionChanged(QItemSelection, QItemSelection);

public slots:
    //! ���� ��� ���������� ������ � ��������� �������
    void stateUpdate();

    /**
    * @brief ���� ��� ���������� ��������������� ��������� � ������ �������
    *
    * ��������� �������� � ���� ���� ������� � ��� �������, ������� ������� ������ ���������
    * @param mes �������������� ���������
    */
    void addServerMessage(QString mes);

    /**
    * @brief ���� ��� ���������� ������� ������ ���� ���������� ��������
    * @note ���������� ������������ � ������ ���������� ���������� ��������
    */
    void updateElapsedTime();
};

#endif // MAINSERVER_H
