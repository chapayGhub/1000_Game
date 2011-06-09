/**
* @file gameserverfactory.h
* @author Kharkunov Eugene
* @date 2.06.2011
*/

#ifndef GAMESERVERFACTORY_H
#define GAMESERVERFACTORY_H

#include <QObject>
#include <QMap>


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
    * @param port       ���� �������� ������� � ������ @p name
    */
    static void unregisterFactory(QString name, int port);

    /**
    * @brief ������� ��� ������������������ �������
    */
    static void unregisterAllFactories();

    /**
    * @brief ���������� ������ ������������������ ������
    * @return ������ ������������������ ��������
    */
    static QList<QString> registeredServer();

    /**
    * @brief ������� ������ ������ �������� �������
    */
    virtual void createServerInstance() = 0;
private:
    //! ������ ������������������ ������
    static QMap<QString, GameServerFactory*> factories;
signals:

public slots:

};

#endif // GAMESERVERFACTORY_H
