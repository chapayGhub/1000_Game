/**
* @file connectionmanager.h
* @author Kharkunov Eugene
* @date 2.06.2011
*/

#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H
#include <QObject>
#include <QVector>
#include <QTcpSocket>

/**
* @class ConnectionManager
* @brief ����� ��� ���������� ������������� �������������
*/
class ConnectionManager : public QObject
{
    Q_OBJECT
public:
    /**
    * @brief ������� ��������� ������������� ������� ������� ������
    * @return ������ ������ @class ConnectionManager
    */
    static ConnectionManager* getInstance();

    /**
    * @brief ����������� �������
    */
    static void destroy();

    /**
    * @brief ����������� �����������
    * @param parent �������� ������
    */
    ConnectionManager(QObject *parent = 0);
public slots:
    /**
    * @brief ���� ��� ���������� ���������� � ������ ������������ ����������
    * @param socket ����, ����������� �������� �������������� ����������
    */
    void addConnection(QTcpSocket *socket);

    /**
    * @brief ���� ��� �������� ���������� �� ������ ������������ ����������
    * @param socket �����, ������� ���������� ������� �� ������
    * @note ���� ����������� � �������� @sa QAbstractSocket::disconnected()
    */
    void removeConnection(QTcpSocket *socket);
private:
    //! �r������� �� ������ ������ @class ConnectionManager
    static ConnectionManager* _mManager;

    //! ������ ������� ��� ������������ ����������
    QVector<QTcpSocket*> socketsArray;
};

#endif // CONNECTIONMANAGER_H
