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
#include "connectionmanager.h"

class ThousandGameQueryHandler;
class GameThousand;

/**
* @class ThousandGameServer
* @brief �����, ����������� ������ ������� ��������� ���� "������"
*/
class ThousandGameServer : public AbstractGameServer
{
    Q_OBJECT
    friend class ThousandGameQueryHandler;
public:
    /**
    * @brief �������� ������ ������
    * @return ������ ������
    */
    static ThousandGameServer* getInstance();

    /**
    * @brief ���������� ������ ������
    */
    static void destroy();

    /**
    * @brief ����������� �����������
    * @param port ����, ������� ����� ������������ ������
    * @param parent ��������� �� ������������ ������
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
    * @brief ��������� �������� ��������� �������
    * @return ��������� �������
    * @sa AbstractGameServer::States
    */
    AbstractGameServer::States serverState() const;

    /**
    * @brief ������� ����� ����
    * @param creater    ���������� � ������������, ������� ������� ����
    * @param setting    ��������� ����
    * @return ���������� ��������
    */
    bool createNewGame(UserDescription creater, GameSettings settings);

    /**
    * @brief
    * @param gameID
    * @param user
    * @return
    */
    bool connectToGame(quint16 gameID, UserDescription user);
private:
    /**
    * @brief ����� ���� � ��������� @p ID
    * @param list   ��������� �� ������ ���, � ������� ���������� ���������� �����
    * @param ID     ID ����
    * @return ��������� �� ����. ���� ���� �� ������� ���������� 0
    */
    GameThousand* findGame(QList<GameThousand*> *list, quint16 ID);

    //! ������ ������ ThousandGameServer
    static ThousandGameServer* _mInstance;

    //! ����� �����, �� ������� �������������� ������ �������
    int _mPort;

    //! ������� ��������� �������
    AbstractGameServer::States state;

    //! �������� ����������
    ConnectionManager* _mManager;

    //! ������� �������� �� ��������
    QList<QueryStruct> _mRequestQueries;

    //! ������� �����, ������� ��������� �� ���� ��������
    QList<QueryStruct> _mMoveQueries;

    //! ���������� ������� ��������
    ThousandGameQueryHandler *requestHandler;

    //! ������ ��� ������ ������� �������
    QList<QString> databaseNames;

    //! ������ ���������� ����� �� � �� ������������
    QMap<QString, QSqlDatabase> mapName2Database;

    //! ����������� ������ ��� ����������� ������������������� ������� � ������� ��������
    QReadWriteLock locker;

    //! ������ ��������� ���, ������� ������� ������
    QList<GameThousand*> listNewGame;

    //! ������ ������� ���������� ���
    QList<GameThousand*> listCurrentGame;

    //! ������ ���������� ���������� � ��������
    QMap<QTcpSocket*, QString> mapConnection2Nick;
signals:
    //! ������ ���������� � ������ ������� ���������� ����� �� ��������
    void connectionAborted(QTcpSocket*);

    //! ������ ���������� ��� ���������� ������ ������� � ������� ��������� �����
    void moveListChanged();
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
