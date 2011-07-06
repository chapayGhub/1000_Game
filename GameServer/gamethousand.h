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

    //! ���������� ��������
    quint8 _mWidowCount;

    //! ���������� ���� � ������ �������
    quint8 _mWidowCardCount;

    //! ����� �������
    quint8 _mPlayerNumber;

    //! ������ ������������ � ������ ���� ����������
    QList<UserDescription> _mPlayerList;

    //! ID ������, ������� ������� � ������� �����
    quint16 _mCurrentDealer;

    //! ����, ������������, ���������� �� ������� �������� �����, ������� ��� ���������
    bool _mDealerMissingMove;

    //! ID ������, ������� ������ ������
    quint16 _mWidowBringer;

    //! ���������� �����, ����������� �� ������
    quint8 _mPointOrdered;

    //! ���������� �����, ������� ������ �������� �� ����� � ������� �������
    QMap<quint16, quint8> _mPlayerLaud;

    //! ������� ������� �����
    Suit _mTrumpSuit;

    /**
    * @brief ������ ������� �� �����. � ���� ����������� ������ ID, ����� ����� ��������� 900 �����.
    * ����� � ������ ����������� 3 ���� ���� � ��� �� ID, �� ���� ������ ����������(3 ���� ������ � �����)
    */
    QList<quint16> _mBarrelPlayer;

    //! ����������������� ����
    quint16 _mTimeout;

    //! ���� ������� ����������
    bool winnerExist;

    //! �����������
    quint16 _mWinner;

    //! ������ ����, ������� �� ����� � ������ ������ � �������(ID ������, ����� ����)
    QMap< quint16, CardPack > mapPlayer2CardSet;

    //! ������ ������, ������� �������� ������ �� ������� � ������� �������(ID ������, ����� ����)
    QMap< quint16, CardPack > mapPlayer2Trick;

    //! ����(ID ������, ��� �������� �����)
    QMap< quint16, QVector<qint16> > score;
    //! ������� ���� ������� �� �������(ID ������, ����)
    QMap< quint16, qint8 > currentPoints;
    //! ������� ������(������������)
    CardPack currentPack;

    //! ������� ���� �� ������� � �� ��������
    void distribute();

    //! ��������� ������ ����� �����
    void moveCycle();
signals:

public slots:

};

#endif // GAMETHOUSAND_H
