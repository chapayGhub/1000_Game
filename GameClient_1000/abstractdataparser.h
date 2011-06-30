/**
* @file abstractdataparser.h
* @author Sosnovitch Sergei
* @date 21.06.2011
* @brief ���� �������� �������� ������, ���������������� ��������� ��� ���������� ��������� ������
* �� �������
*/
#ifndef ABSTRACTDATAPARSER_H
#define ABSTRACTDATAPARSER_H

#include <QObject>
#include <QString>
#include <QDataStream>
#include "protocol.h"
#include "card.h"
#include "gamethousand.h"

/**
* @class AbstractDataParser
* @brief ����������� �����, ��������������� ��������� ��� ���������� ������� ���������
* �������� � �������� � ������� ������
*/
class AbstractDataParser : public QObject
{
    Q_OBJECT
public:
    /**
    * @brief ����������� �����������
    * @param parent ��������� �� ������������ ������
    */
    explicit AbstractDataParser(QObject *parent = 0);

    /**
    * @brief ����������� ����������
    */
    virtual ~AbstractDataParser();

    /**
    * @defgroup IncommingData ��������� �������� ������
    * ������ ������� ��� ��������� ����������� �� ������� ������
    * @{
    */

    /**
    * @brief ��������� ������ � ����������� ������ ������������
    * @param data ������ � ������������
    */
    virtual void inRegistration(QByteArray &data) = 0;

    /**
    * @brief ��������� ������ ��� ����������� ������������
    * @param data ������ ��� �����������
    */
    virtual void inAuthorization(QByteArray &data) = 0;

    /**
    * @brief ��������� ������, ����������� ��� �������� ����� ���� �� �������
    * @param data ������ ��� �������� ����
    */
    virtual void inNewGame(QByteArray &data) = 0;

    virtual void inMessage(QByteArray &data) = 0;

    /**
    * @brief ��������� ������ � ����������� ������ � ����
    * @param data ������ � ����������� � ��������� ����
    */
    virtual void inConnectToGame(QByteArray &data) = 0;

    /**
    * @brief ��������� ������ �� ���������� �� ����
    * @param data ������ �� ���������� ������ �� ��������� ����(�� ������� �������)
    */
    virtual void inDisconnectGame(QByteArray &data) = 0;

    virtual void inStartGame(QByteArray &data) = 0;

    virtual void inFinishGame(QByteArray &data) = 0;

    /**
    * @brief ��������� ������ �� ������ ��������� ����
    * @param data ������, ���������� ���������� �� ������ ��������� ����
    */
    virtual void inCancelGame(QByteArray &data) = 0;

    /**
    * @brief ��������� ������, ����������� ��� ��������� �������� �� ������
    * @param data ������, ���������� ����������, ����������� ��� ��������� �������� �� ������
    */
    virtual void inPlayerStatistics(QByteArray &data) = 0;

    virtual void inTotalStatistics(QByteArray &data) = 0;

    virtual void inMove(QByteArray &data) = 0;

    virtual void inListAllGame(QByteArray &data) = 0;

    virtual void inListAllNewGame(QByteArray &data) = 0;
    /** @}*/

signals:

public slots:
    /**
    * @defgroup OutcommingData ���������� ������ ��� ��������
    * ������ �������, ��������������� ��� ���������� ������, ���������� �� �������, � �������� ��������
    * @{
    */

    /**
    * @brief �������������� ������ � ������������ ����� �����������
    * @return ������ � ������������������ ������������
    */
    virtual void outRegistration(const RegistrationData &info) = 0;

    /**
    * @brief
    * @return
    */
    virtual void outAuthorization(const AuthorizationData &info) = 0;

    /**
    * @brief
    * @return
    */
    virtual void outMessage(const QString &message) = 0;

    /**
    * @brief
    * @return
    */
    virtual void outNewGame(const GameSettings &game) = 0;

    /**
    * @brief
    * @return
    */
    virtual void outConnectGame(const quint16 &gameID) = 0;

    /**
    * @brief
    * @return
    */
    virtual void outDisconnectGame(const quint16 &gameID) = 0;

    /**
    * @brief
    * @return
    */
    virtual void outCancelGame(const quint16 &gameID) = 0;

    /**
    * @brief
    * @return
    */
    virtual void outStartGame(const GameSettings &game) = 0;

    /**
    * @brief
    * @return
    */
    virtual void outFinishGame(const quint16 &gameID) = 0;

    /**
    * @brief
    * @return
    */
    virtual void outListAllGame() = 0;

    /**
    * @brief
    * @return
    */
    virtual void outListAllNewGame() = 0;

    /**
    * @brief
    * @return
    */
    virtual void outTotalStatistics() = 0;

    /**
    * @brief
    * @return
    */
    virtual void outPlayerStatistics(const PlayerInformation &player) = 0;

    /**
    * @brief
    * @return
    */
    virtual void outMove(const Card &card) = 0;

    /** @}*/

};

#endif // ABSTRACTDATAPARSER_H
