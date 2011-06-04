/**
* @file thousandgameserver.h
* @author Kharkunov Eugene
* @date 3.06.2011
*/
#ifndef THOUSANDGAMESERVER_H
#define THOUSANDGAMESERVER_H

#include <QSqlDatabase>
#include "abstractgameserver.h"

class ConnectionManager;

class ThousandGameServer : public AbstractGameServer
{
    Q_OBJECT
public:
    /**
    * @brief �������� ������ ������ @class ThousandGameServer
    * @return ������ ������
    */
    static ThousandGameServer* getInstance();

    /**
    * @brief ���������� ������ ������ @class ThousandGameServer
    */
    static void destroy();

    /**
    * @brief ����������� �����������
    * @param port ����, ������� ����� ������������ ������
    * @sa Config::portsForGameServers
    */
    explicit ThousandGameServer(int port, QObject *parent = 0);

    /**
    * @brief ����������� ����������
    */
    virtual ~ThousandGameServer();

    /**
    * @brief ��������� ������� ������
    * � ������ ������������� ������ ���������� ��������� � ����������� ����������� � ��������� ������
    * @return true  ���� ������ ����������
    *         false ���� �������� ������ ��� ������ �������
    */
    bool startServer();

    /**
    * @brief ������������� ���������� ������� ������
    */
    void stopServer();

    /**
    * @brief ������������� ��� ������, � ������� �������� ��� ���������� ��� ������� �������� �������
    */
    bool initDatabases();

    void disconnectDatabases();

    /**
    *
    */
    void sendToClient(QByteArray &array, QTcpSocket *socket);
    AbstractGameServer::states serverState() const;
private:
    static ThousandGameServer* _mInstance;
    int _mPort;
    AbstractGameServer::states state;
    ConnectionManager* _mManager;
    QList<QString> databaseNames;
    QMap<QString, QSqlDatabase> mapName2Database;
//    QSqlDatabase dbUserInfo;
signals:
    void connectionAborted(QTcpSocket*);
private slots:
    void slotConnectionAborted();

public slots:
    void addNewConnection();

    void readClientInformation();
};

#endif // THOUSANDGAMESERVER_H
