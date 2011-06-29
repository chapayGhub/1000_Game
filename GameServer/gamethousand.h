/**
* @file gamethousand.h
* @author Kharkunov Eugene
* @date 4.06.2011
* @brief �������� �������� ������, ������������ ���� "������"
*/

#ifndef GAMETHOUSAND_H
#define GAMETHOUSAND_H

#include <QThread>
#include <QTcpSocket>
#include "connectionmanager.h"
#include "card.h"

class QFile;

/**
* @class GameThousand
* @brief �����, ����������� ���� � "������" � ��������� ������
*/
class GameThousand : public QThread
{
    Q_OBJECT
public:
    /**
    * @brief ����������� ������
    * @param creater    ID ����������� ����
    * @param number     ����� ����������
    * @param time       ����������������� ����
    * @param parent     ��������� �� ������������ ������
    */
    explicit GameThousand(UserDescription creater, quint8 number, quint16 time, QObject *parent = 0);

    /**
    * @brief ����������� ����������
    */
    ~GameThousand();

    /**
    * @brief ��������� ������������ � ����
    * @param user   ������ � ������������
    * @return ���������� ���������� ��������
    */
    bool addPlayer(UserDescription user);

    /**
    * @brief ���������� ID ����
    * @return ID ����(������)
    */
    quint16 gameID() const;

    /**
    * @brief ���������� �����, ������� ��������� ������ ��� ���������� ����
    * @return ����� � ��������. ����� ���������� ������������ ����� ��������
    */
    quint16 timeout() const;

    /**
    * @brief ���������� ���������� �������, �� ������� ��������� ������ ����.
    * @return ����� �������. ����� ��������� �������� �� 2 �� 4
    */
    quint8 playerNumber() const;

    /**
    * @brief ���������� ������ ���������� ������ ����
    * @return ������ ����������
    */
    QList<UserDescription>& players();

    /**
    * @brief ������������ ������� ����
    */
    void run();

    /**
    * @brief ������� ����� � ����� ���������
    */
    void calculatePoints();

    /**
    * @brief ������������� ���� � ������ ���������
    */
    void shuffle();

    /**
    * @brief ������� ��� ����
    *
    * ��� ������ � ���� ��� �������� �����. ����������� � ����� ����
    * @return ����, �������� ��� ����. �������� ����� � ���� ����_����� ����������.txt
    */
    QFile createLog();
private:
    //! ID ����
    quint16 _mID;
    //! ����� �������
    quint8 _mPlayerNumber;
    //! ����������������� ����
    quint16 _mTimeout;
    //! ID ������, ������� ������� � ������� �����
    quint16 currentDealer;
    //! ������ ������������ � ������ ���� ����������
    QList<UserDescription> _mPlayerList;
    //! ������ ����, ������� �� ����� � ������ ������ � �������(ID ������, ����� ����)
    QMap< quint16, CardPack > mapPlayer2CardSet;
    //! ����(ID ������, ��� �������� �����)
    QMap< quint16, QVector<qint8> > score;
    //! ������� ���� ������� �� �������(ID ������, ����)
    QMap< quint16, quint8 > currentPoints;
    //! ������� ������(������������)
    CardPack currentPack;
signals:

public slots:

};

#endif // GAMETHOUSAND_H
