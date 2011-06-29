/**
* @file connectionmanager.h
* @author Kharkunov Eugene
* @date 2.06.2011
* @brief ���� �������� �������� ������ ��������� ����������, � ����� ������������ � ���������,
* ������� ��������� ����������� ������������
*/

#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H
#include <QObject>
#include <QList>
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
* @struct UserDescription
* @brief ��������� ��� �������� ����������� ������������
*/
struct UserDescription{
    //! ��������� �� �����
    QTcpSocket *socket;
    //! ��������� ������
    SocketState _mState;
    //! ��� ������������, ��������������� � ������ �����������
    QString UserNick;
    //! ���� �����������
    bool isAuthorize;
    /**
    * @brief ID ������������, ������� �� �������� ��� �����������.
    * @note �� ������� ������ � ID ������������, ������� �������� � �� �������
    * @sa PlayerInformation::ID
    */
    quint16 ConnectionID;
    /**
    * @brief ID ����, � ������� ��������� ������������.
    * @note ��� ������������, ������� �������� ����, ��� ID, ���������� ��� �����������, ��������� � ID ����
    */
    quint16 GameID;

};

/**
* @class ConnectionManager
* @brief ����� ��� ���������� ������������� �������������
*/
class ConnectionManager : public QObject
{
    Q_OBJECT
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
    * @return ��������� ������. ���������� ��������� SocketState::Undefined, ���� ��������� ����� �� ������
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

    /**
    * @brief ����� ������ �� ���������� �����������
    * @param descriptor ���������� ������, ������� ���������� �����
    * @return ��������� �� ��������� �����. ���� ����� �� ������, ���������� 0
    */
    QTcpSocket* findSocket(int descriptor) const;

    /**
    * @brief �������� ��� ������������, ������� ������������ � ������ �����������
    * @param socket �����, ����������� �������� �������������� ����������
    * @return ��� ������������
    */
    QString userNick(QTcpSocket *socket) const;

    /**
    * @brief ������������� ���������� ���������� ���� ��� ������� ����������
    * @param socket     �����, ����������� �������� �������������� ����������
    * @param nickName   ����� ��� ������������, ������� ����� ����������
    */
    void setUserNick(QTcpSocket *socket, QString nickName);

    /**
    * @brief �������� ������� ���������������� ������������ ��� ������� ����������
    * @param socket �����, ����������� ������� �������������� ����������
    * @return ������� ���������������� ������������
    */
    bool authorizationFlag(QTcpSocket *socket) const;

    /**
    * @brief ������������� ���� ����������� ��� ��������� ����������
    * @param socket �����, ����������� �������� ����������� ����������
    * @param flag   ������� ����������� ������������
    */
    void setAuthorizationFlag(QTcpSocket *socket, bool flag);

    /**
    * @brief ��������� ���������� � ������������ �� ID ��� ����������
    * @param ID ID ����������
    * @return ���������� � ������������
    */
    UserDescription getUserDescription(quint32 ID);
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

    /**
    * @brief ��������� ��� ������������ ���������� � ������� ������ ������������ �������������
    */
    void closeAllConnections();
private:
    //! ������ �������������, ������������ � �������
    QList<UserDescription> userList;
};

#endif // CONNECTIONMANAGER_H
