/**
* @file abstractgameserver.h
* @author Kharkunov Eugene
* @date 3.06.2011
* @brief ���� �������� �������� ������������ ������, ���������������� ��������� ��� �����������
* ���������� �������� �������
*/
#ifndef ABSTRACTGAMESERVER_H
#define ABSTRACTGAMESERVER_H

#include <QTcpServer>
#include "protocol.h"

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
    * @brief ������������ ��������� ��������� �������� �������
    */
    enum states {
        //! ������ ��������
        Running,
        //! ������ ���������� ���� �� ��� �������
        NotRunning
    };

public:
    /**
    * @brief ����������� �����������
    * @param port ����� �����, ������� ����� ������������ ������� ������
    * @param parent ��������� �� ������������ ������
    */
    explicit AbstractGameServer(int port, QObject *parent = 0);

    /**
    * @brief ����������� ����������
    */
    virtual ~AbstractGameServer();

    /**
    * @brief ������ �������. ������ ��������� ��� ����������� ��� ������ ������� ���������.
    * @return ���������� ������� �������
    */
    virtual bool startServer() = 0;

    /**
    * @brief ������������� ���������� ������
    */
    virtual void stopServer() = 0;

    /**
    * @brief ���������� ������� ��������� �������� �������
    * @return ������� ��������� �������
    */
    virtual states serverState() const = 0;

    /**
    * @brief ����� ��� �������� ������ �������
    * @param array ������, ������� ���������� ���������
    * @param socket �����, �� ��������� �������� �������������� ����� � ��������
    */
    virtual void sendToClient(QByteArray &array, QTcpSocket *socket) = 0;

    /**
    * @brief ������������� ��� ������ �������
    * @return ���������� ������������� ���� ����������� ��
    */
    virtual bool initDatabases() = 0;

    /**
    * @brief ��������� ��� ��������� ����������� � ��
    */
    virtual void disconnectDatabases() = 0;

signals:
    //! ������ ����������, ���� � ������� �������� ��� �������� ����� ������
    void queryListChanged();

public slots:
    /**
    * @brief ���� ��� ���������� ������ ���������� � ��������
    */
    virtual void addNewConnection() = 0;
    /**
    * @brief ���� ��� ���������� �������, ������� �������� �� �������, � ������� ���������
    */
    virtual void addRequestQuery() = 0;
};

#endif // ABSTRACTGAMESERVER_H
