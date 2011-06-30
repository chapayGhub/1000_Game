/**
* @file card.h
* @author Kharkunov Eugene
* @date 18.06.2011
* @brief �������� �������� ������� ����. �������� ���������������� ���� ������ � ������� ���������� ������ ����
*/

#ifndef CARD_H
#define CARD_H

#include <QPair>
#include <QVector>

/**
* @enum Suit
* @brief ������������ �������� ����� ����, ������� ������������� ���������� �����, ������� �����������
* �� ����� ��������������� �����
*/
enum Suit {
    //! ������ �����
    EMPTY        = 0,
    //! ����
    SPADES      = 40,
    //! �����
    CLUBS       = 60,
    //! �����
    DIAMONDS    = 80,
    //! �����
    HEARTS      = 100
};

/**
* @enum Value
* @brief ������������ �������� �������� ����, ����������� � ���� "������", ������� �������������
* ���������� �����, ����������� �� ������ �������
*/
enum Value {
    //! �������
    NINE    = 0,
    //! �����
    JACK    = 2,
    //! ����
    QUEEN   = 3,
    //! ������
    KING    = 4,
    //! �������
    TEN     = 10,
    //! ���
    ACE     = 11
};

/**
* @typedef QPair<Suit, Value> Card
* @brief ���������� ���� "�����"
*/
typedef QPair<Suit, Value> Card;

/**
* @typedef QVector<Card> CardPack
* @brief ���������� ���� "������ ����"
*/
typedef QVector<Card> CardPack;

//! ������ ����
static CardPack pack = CardPack();

/**
* @brief ������������� ������ ����
* @note ����������� ��� ������ ����. �������� �������� �� ������������� ��� ������ � ����������� ��������
*/
static void packInit() {
    if (pack.isEmpty()) {
    pack.push_back(qMakePair(SPADES, NINE));
    pack.push_back(qMakePair(SPADES, JACK));
    pack.push_back(qMakePair(SPADES, QUEEN));
    pack.push_back(qMakePair(SPADES, KING));
    pack.push_back(qMakePair(SPADES, TEN));
    pack.push_back(qMakePair(SPADES, ACE));
    pack.push_back(qMakePair(CLUBS, NINE));
    pack.push_back(qMakePair(CLUBS, JACK));
    pack.push_back(qMakePair(CLUBS, QUEEN));
    pack.push_back(qMakePair(CLUBS, KING));
    pack.push_back(qMakePair(CLUBS, TEN));
    pack.push_back(qMakePair(CLUBS, ACE));
    pack.push_back(qMakePair(DIAMONDS, NINE));
    pack.push_back(qMakePair(DIAMONDS, JACK));
    pack.push_back(qMakePair(DIAMONDS, QUEEN));
    pack.push_back(qMakePair(DIAMONDS, KING));
    pack.push_back(qMakePair(DIAMONDS, TEN));
    pack.push_back(qMakePair(DIAMONDS, ACE));
    pack.push_back(qMakePair(HEARTS, NINE));
    pack.push_back(qMakePair(HEARTS, JACK));
    pack.push_back(qMakePair(HEARTS, QUEEN));
    pack.push_back(qMakePair(HEARTS, KING));
    pack.push_back(qMakePair(HEARTS, TEN));
    pack.push_back(qMakePair(HEARTS, ACE));
    }
}

#endif // CARD_H
