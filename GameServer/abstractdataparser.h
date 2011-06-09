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
    virtual void inRegistration(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������ ��� ����������� ������������
    * @param data ������ ��� �����������
    */
    virtual void inAuthorization(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������, ����������� ��� �������� ����� ���� �� �������
    * @param data ������ ��� �������� ����
    */
    virtual void inNewGame(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������ � ����������� ������ � ����
    * @param data ������ � ����������� � ��������� ����
    */
    virtual void inConnectToGame(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������ �� ���������� �� ����
    * @param data ������ �� ���������� ������ �� ��������� ����(�� ������� �������)
    */
    virtual void inDisconnectGame(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������ �� ������ ��������� ����
    * @param data ������, ���������� ���������� �� ������ ��������� ����
    */
    virtual void inCancelGame(const QByteArray &data) = 0;

    /**
    * @brief ��������� ������, ����������� ��� ��������� �������� �� ������
    * @param data ������, ���������� ����������, ����������� ��� ��������� �������� �� ������
    */
    virtual void inPlayerStatistics(const QByteArray &data) = 0;

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
    virtual QByteArray outInfoForNewConnection() = 0;

    /**
    * @brief �������������� ������ � ������������ ����� �����������
    * @return ������ � ������������������ ������������
    */
    virtual QByteArray outRegistration() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outAuthorization() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outMessage() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outNewGame() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outConnectGame() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outDisconnectGame() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outCancelGame() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outStartGame() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outFinishGame() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outListAllGame() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outListAllNewGame() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outTotalStatistics() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outPlayerStatistics() = 0;

    /**
    * @brief
    * @return
    */
    virtual QByteArray outMove() = 0;

    /** @}*/
signals:

public slots:

};

#endif // ABSTRACTDATAPARSER_H
