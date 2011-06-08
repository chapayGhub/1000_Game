/**
* @file thousandgameserver.h
* @author Kharkunov Eugene
* @date 3.06.2011
* @brief ���� �������� �������� ������, ������������ ������ ������� ��������� ���� "������"
*/
#ifndef THOUSANDGAMESERVER_H
#define THOUSANDGAMESERVER_H

#include <QSqlDatabase>
#include <QReadWriteLock>
#include "abstractgameserver.h"

class ConnectionManager;
class QueryHandler;
class QReadWriteLock;

/**
* @class ThousandGameServer
* @brief �����, ����������� ������ ������� ��������� ���� "������"
*/
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
    * @brief ��������� ������� ������. ������������� ����������� ������������� ��� ������ ��� ������� �������.
    * � ������ ������������� ������ ���������� ��������� � ����������� ����������� � ��������� ������
    * @sa initDatabases()
    * @return <b>true</b>  ���� ������ ����������;
    *         <b>false</b> ���� �������� ������ ��� ������ �������
    */
    bool startServer();

    /**
    * @brief ������������� ���������� ������� ������. ��������� ��� ������������� ���������� � ���������
    * � ����������� �� �������������� ��� ������
    */
    void stopServer();

    /**
    * @brief ������������� ��� ������, � ������� �������� ��� ���������� ��� ������� �������� �������.
    * �� ��������� ��������� ������������, ���� ���� �� ���������� ���� ���������� � �� ����� ������� ���
    * ����������� ������
    * @return <b>true</b>  ���� ��� ���������� �� ������� ����������
    *         <b>false</b> ���� �� ����� ������������� ��������� ������ ����������� � ��
    */
    bool initDatabases();

    /**
    * @brief �n�-�� ���
    */
    void disconnectDatabases();

    /**
    *
    */
    void sendToClient(QByteArray &array, QTcpSocket *socket);

    /**
    * @brief
    */
    AbstractGameServer::states serverState() const;
private:
    //! ������ ������ ThousandGameServer
    static ThousandGameServer* _mInstance;

    //! ����� �����, �� ������� �������������� ������ �������
    int _mPort;

    //! ������� ��������� �������
    AbstractGameServer::states state;

    //! �������� ����������
    ConnectionManager* _mManager;

    //! ������� �������� �� ��������
    QList<QueryStruct> _mRequestQueries;

    //! ���������� ������� ��������
    QueryHandler *requestHandler;

    //! ������ ���� ������ ������� �������
    QList<QString> databaseNames;

    //! ������ ���������� ����� �� � �� ������������
    QMap<QString, QSqlDatabase> mapName2Database;

    //!
    QReadWriteLock locker;
signals:
    //! ������ ���������� � ������ ������� ���������� ����� �� ��������
    void connectionAborted(QTcpSocket*);

    //! ������ ����������, ���� � ������� �������� ��� �������� ����� ������
    void queryListChanged();
private slots:
    //! ����, ������������ ����������, ������� ����� ���������
    void slotConnectionAborted();

public slots:
    /**
    * @brief ���� ��� ���������� ������ ����������
    */
    void addNewConnection();

    /**
    * @brief ���� ��� ���������� �������, ������� �������� �� �������, � ������� ���������
    */
    void addRequestQuery();
};

#endif // THOUSANDGAMESERVER_H
