/**
* @file gameserverfactory.h
* @author Kharkunov Eugene
* @date 2.06.2011
* @brief �������� �������� �������� ������ ������� �������� �������
*/

#ifndef GAMESERVERFACTORY_H
#define GAMESERVERFACTORY_H

#include <QObject>
#include <QMap>
#include "abstractgameserver.h"

/**
* @class GameServerFactory
* @brief ����� ����������� ������� ��� �������� � ����������� ������������ ������� ��������
*/
class GameServerFactory : public QObject
{
    Q_OBJECT
public:
    /**
    * @brief ����������� �����������
    * @param parent ��������� �� ������������ ������
    */
    explicit GameServerFactory(QObject *parent = 0);

    /**
    * @brief ����������� ����������
    */
    virtual ~GameServerFactory();

    /**
    * @brief ������������ �������� �������
    * @param name       �������� �������� �������
    * @param port       ���� �������� �������
    * @param factory    ������� �������� �������
    */
    static void registerFactory(QString name, int port, GameServerFactory *factory);

    /**
    * @brief ������� ������������������ �������
    * @param name       �������� �������� �������
    */
    static void unregisterFactory(QString name);

    /**
    * @brief ������� ��� ������������������ �������
    */
    static void unregisterAllFactories();

    /**
    * @brief ���������� ������ ������������������ ������
    * @return ������ ������������������ ��������
    */
    static QList<AbstractGameServer*> registeredServer();

    /**
    * @brief ������� ������ ������ �������� �������
    */
    virtual AbstractGameServer* createServerInstance() = 0;
private:
    //! ������ ������������������ ������
    static QMap<QString, GameServerFactory*> factories;

    //! ������ �������� ��������
    static QList<AbstractGameServer*> servers;
signals:

public slots:

};

#endif // GAMESERVERFACTORY_H
