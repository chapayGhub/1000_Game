/**
* @file abstractdataparser.h
* @author Kharkunov Eugene
* @date 9.06.2011
* @brief ���� �������� �������� ������, ���������������� ��������� ��� ���������� ��������� ������
* �� �������
*/
#ifndef ABSTRACTDATAPARSER_H
#define ABSTRACTDATAPARSER_H

#include <QObject>
#include <QString>
#include <QDataStream>
#include "protocol.h"

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
    * @return ������, ��������������� � ��������� RegistrationData
    */
    virtual RegistrationData inRegistration(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������ ��� ����������� ������������
    * @param data ������ ��� �����������
    * @return ������, ��������������� � ��������� AuthorizationData
    */
    virtual AuthorizationData inAuthorization(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������, ����������� ��� �������� ����� ���� �� �������
    * @param data ������ ��� �������� ����
    * @return ������� ���������
    */
    virtual GameSettings inNewGame(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������ � ����������� ������ � ����
    * @param data ������ � ����������� � ��������� ����
    */
    //    virtual void inConnectToGame(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������ �� ���������� �� ����
    * @param data ������ �� ���������� ������ �� ��������� ����(�� ������� �������)
    */
    //    virtual void inDisconnectGame(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������ �� ������ ��������� ����
    * @param data ������, ���������� ���������� �� ������ ��������� ����
    */
    //    virtual void inCancelGame(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������, ����������� ��� ��������� �������� �� ������
    * @param data ������, ���������� ����������, ����������� ��� ��������� �������� �� ������
    * @return ��� ������������, � ������� ������������� ����������
    */
    virtual QString inPlayerStatistics(const QByteArray &data) = 0;

    /** @}*/

    /**
    * @defgroup OutcommingData ���������� ������ ��� ��������
    * ������ �������, ��������������� ��� ���������� ������, ���������� �� �������, � �������� ��������
    * @{
    */

    /**
    * @brief �������������� ����� ������ ��� �������� �������, ������� ������ ��� ����������� � �������
    * @return ����� ������, ���������� ��� ����������� ������ �������
    */
    //    virtual QByteArray outInfoForNewConnection() = 0;

    /**
    * @brief �������������� ������ � ������������ ����� �����������
    * @param information ���������� � ���������� �����������
    * @return ���������, ������� �������� � ���� ������. � ������ ������, �������� � ���� ���������
    * "Registration successful!"
    */
    virtual QByteArray outRegistration(QVector<QString> &information) = 0;

    /**
    * @brief �������������� ������ � ���������� �����������
    * @param information ���������� � ����������� �����������
    * @return ���������, ������� �������� � ���� ������. � ������ ������, �������� � ���� ���������
    * "Authorization successful!"
    */
    virtual QByteArray outAuthorization(QVector<QString> &information) = 0;

    /**
    * @brief
    * @return
    */
//        virtual QByteArray outMessage(QList<AbstractGame*> &list) = 0;
    /**
    * @brief
    * @return
    */
    //    virtual QByteArray outNewGame() = 0;

    /**
    * @brief
    * @return
    */
    //    virtual QByteArray outConnectGame() = 0;

    /**
    * @brief
    * @return
    */
    //    virtual QByteArray outDisconnectGame() = 0;

    /**
    * @brief
    * @return
    */
    //    virtual QByteArray outCancelGame() = 0;

    /**
    * @brief
    * @return
    */
    //    virtual QByteArray outStartGame() = 0;

    /**
    * @brief
    * @return
    */
    //    virtual QByteArray outFinishGame() = 0;

    /**
    * @brief �������������� ���������� ���������� �� ������� � ������ ����
    * @param data ���������� ����������
    * @return ������ ����, ���������� ��� ���������� � ������������������ ������� �� ������ �������
    */
    virtual QByteArray outTotalStatistics(QVector<PlayerInformation> &data) = 0;

    /**
    * @brief �������������� ���������� � ������������ � ������ ����
    * @param data ���������� � ������������
    * @return ������ � ������� � ������������
    */
    virtual QByteArray outPlayerStatistics(const PlayerInformation &data) = 0;

    /**
    * @brief
    * @return
    */
    //    virtual QByteArray outMove() = 0;

    /** @}*/
signals:

public slots:

};

#endif // ABSTRACTDATAPARSER_H
