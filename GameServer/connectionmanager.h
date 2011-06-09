/**
* @file connectionmanager.h
* @author Kharkunov Eugene
* @date 2.06.2011
* @brief ���� �������� �������� ������ ��������� ����������, � ����� ������������ � ���������,
* ������� ��������� �����
*/

#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H
#include <QObject>
#include <QVector>
#include <QTcpSocket>

/**
* @enum SocketState
* @brief ��������� ��������� ������.
*
* ����� ����� ��������� � ���� ����������:
* 1. �� ��������� ������� ������ ��� ��������� ������ �� ������. ����� ���� �������� ������
* 2. ������ ��� �� ���������
*/
enum SocketState{
    //! ��������� ���������� �� ����������
    Undefined,
    //! �������� �������� �������
    WaitForQueryTransmission,
    //! �������� �������� ������
    WaitForDataTransmission
};

/**
* @struct SocketDesc
* @brief ��������� ��� �������� ����������� ������
*
* �������� � ���� ��������� �� ����� � ��� ���������
* @sa SocketState
*/
struct SocketDescr{
    //! ��������� �� �����
    QTcpSocket *socket;
    //! ��������� ������
    SocketState _mState;
};

/**
* @class ConnectionManager
* @brief ����� ��� ���������� ������������� �������������
*/
class ConnectionManager : public QObject
{
    Q_OBJECT
    friend class QueryHandler;
public:
    /**
    * @brief ����������� �����������
    * @param parent ��������� �� ������������ ������
    */
    ConnectionManager(QObject *parent = 0);

    /**
    * @brief ����������� ����������
    */
    ~ConnectionManager();

    /**
    * @brief �������� ��������� ���������� ������
    * @param socket ��������� �� �����, ��������� �������� ���������� ������
    * @return ��������� ������
    * @sa SocketState
    */
    SocketState socketState(QTcpSocket *socket) const;

    /**
    * @brief ������������� ��������� @p state ��� ������ @p socket
    * @param socket ��������� �� �����, ��������� �������� ���������� ��������
    * @param state  ��������� ������, ������� ���������� ����������
    * @sa SocketState
    */
    void setSocketState(QTcpSocket *socket, SocketState state);
public slots:
    /**
    * @brief ���� ��� ���������� ���������� � ������ ������������ ����������
    *
    * ����������� ����� ����� ��������� � ��������� SocketState::WaitForQueryTransmission
    * @param socket �����, ����������� �������� �������������� ����������
    */
    void addConnection(QTcpSocket *socket);

    /**
    * @brief ���� ��� �������� ���������� �� ������ ������������ ����������
    * @param socket �����, ������� ���������� ������� �� ������
    * @note ���� ����������� � �������� QAbstractSocket::disconnected()
    */
    void removeConnection(QTcpSocket *socket);
private:
    //! ������ ������� � �� ��������� ��� ������������ ����������
    QVector<SocketDescr> socketsArray;
};

#endif // CONNECTIONMANAGER_H
