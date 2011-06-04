/**
* @file abstractgameserver.h
* @author Kharkunov Eugene
* @date 3.06.2011
*/
#ifndef ABSTRACTGAMESERVER_H
#define ABSTRACTGAMESERVER_H

#include <QTcpServer>

/**
* @class AbstractGameServer
* @brief ����� ������������� ��������� ��� ���������� �������� �������
*/
class AbstractGameServer : public QTcpServer
{
    Q_OBJECT
protected:
    /**
    * @enum states
    * @brief
    */
    enum states {Running, NotRunning};
public:
    /**
    * @brief ����������� �����������
    * @param port ����� �����, ������� ����� ������������ ������� ������
    * @param parent �������� ������
    */
    explicit AbstractGameServer(int port, QObject *parent = 0);

    /**
    * ����������� ����������
    */
    virtual ~AbstractGameServer();

    /**
    * @brief
    * @return
    */
    virtual bool startServer() = 0;

    /**
    *
    */
    virtual void stopServer() =0;

    virtual states serverState() const = 0;

    /**
    * @brief ����� ��� �������� ������ �������
    * @param array ������, ������� ���������� ���������
    * @param socket �����, �� ��������� �������� �������������� ����� � ��������
    */
    virtual void sendToClient(QByteArray &array, QTcpSocket *socket) = 0;

    /**
    * @brief ������������� ��� ������ �������
    */
    virtual bool initDatabases() = 0;

    virtual void disconnectDatabases() = 0;

public slots:

    virtual void addNewConnection() = 0;
    /**
    * ���� ��� ������ ����������, ���������� ��������
    */
    virtual void readClientInformation() = 0;
};

#endif // ABSTRACTGAMESERVER_H
