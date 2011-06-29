/**
* @file gamethousand.h
* @author Sosnovitch Sergei
* @date 28.06.2011
* @brief ����� ���������� ���� 1000
*/

#ifndef GAMETHOUSAND_H
#define GAMETHOUSAND_H

#include <QThread>
#include <QTcpSocket>
#include "card.h"
#include "player.h"

/**
* @class GameThousand
* @brief �����, ����������� ���� � "������" � ��������� ������
*/
class GameThousand
{

public:
    /**
    * @brief ����������� ������
    * @param players    ������ �������
    * @param number     ����� ����������
    * @param time       ����������������� ����
    * @param parent     ��������� �� ������������ ������
    */
    explicit GameThousand(QList<Player> players, quint8 number, quint16 time);

    /**
    * @brief ����������� ����������
    */
    ~GameThousand();

    /**
    * @brief ��������� ������������ � ����
    * @param user   ������ � ������������
    * @return ���������� ���������� ��������
    */
    bool addPlayer(Player user);

    /**
    * @brief �������� ID ����
    * @return ID ����
    */
    quint16 gameID() const;

    /**
    * @brief ������������� ID ����
    * @param id      id ����
    */
    void setGameId(quint16 id);

    /**
    * @brief  �������� �������� ���� � ����
    * @return �������� ���� � ����
    */
    quint16 timeout() const;

    /**
    * @brief  ������������� �������� ���� � ����
    * @param  time    �������� ����
    */
    void setTimeout(quint16 time);

    /**
    * @brief  �������� ����� ������� � ����
    * @return ����� ������� � ����
    */
    quint8 playerNumber() const;

    /**
    * @brief  ������������� ����� ������� ����
    * @param  number ����� �������
    */
    void setPlayerNumber(quint8 number);

    /**
    * @brief  �������� ������ ������� � ����
    * @return ������ ������� � ����
    */
    QList<Player>& players();

private:
    //! ID ����
    quint16 ID;
    //! ����� �������
    quint8 PlayerNumber;
    //! ����������������� ����
    quint16 Timeout;
    //! ID ������, ������� ������� � ������� �����
    quint16 currentDealer;
    //! ������ ������������ � ������ ���� ����������
    QList<Player> PlayerList;
    //! ������� ������(������������)
    CardPack currentPack;


};

#endif // GAMETHOUSAND_H
