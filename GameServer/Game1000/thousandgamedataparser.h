/**
* @file thousandgamedataparser.h
* @author Kharkunov Eugene
* @date 6.06.2011
* @brief �������� �������� ������, ������� ������������ ������ ��� ��������
*/

#ifndef THOUSANDGAMEDATAPARSER_H
#define THOUSANDGAMEDATAPARSER_H

#include "abstractdataparser.h"

class GameThousand;
class ThousandGameQueryHandler;

/**
* @class ThousandGameDataParser
* @brief �����, �������������� ���������� ��������� ����������� ������ � ���������� ������ ��� ��������
* ��������
*/
class ThousandGameDataParser : public AbstractDataParser
{
    Q_OBJECT
public:
    /**
    * @brief ����������� �����������
    * @param parentHandler  ��������� �� ������������ ���������� ��������
    * @param parent         ��������� �� ������������ ������
    */
    explicit ThousandGameDataParser(ThousandGameQueryHandler *parentHandler, QObject *parent = 0);

    /**
    * @brief ����������� ����������
    */
    ~ThousandGameDataParser();

    /**
    * @brief �������������� �� AbstractDataParser::inRegistration
    */
    RegistrationData inRegistration(const QByteArray &data);

    /**
    * @brief �������������� �� AbstractDataParser::outRegistration
    */
    QByteArray outRegistration(QVector<QString> &information);

    /**
    * @brief �������������� �� AbstractDataParser::inAuthorization
    */
    AuthorizationData inAuthorization(const QByteArray &data);

    /**
    * @brief �������������� �� AbstractDataParser::outAuthorization
    */
    QByteArray outAuthorization(QVector<QString> &information);

    /**
    * @brief �������������� �� AbstractDataParser::inPlayerStatistics
    */
    QString inPlayerStatistics(const QByteArray &data);

    /**
    * @brief �������������� �� AbstractDataParser::outPlayerStatistics
    */
    QByteArray outPlayerStatistics(const PlayerInformation &data);

    /**
    * @brief ������������� �� AbstractDataParser::outTotalStatistics
    */
    QByteArray outTotalStatistics(QVector<PlayerInformation> &data);

    /**
    * @brief �������������� �� AbstractDataParser::inNewGame
    */
    GameSettings inNewGame(const QByteArray &data);

    /**
    * @brief ��������� �������� ������ �� ������� ������ ���� ����� ���(��������� �������)
    *
    * �������� ������ ����������� � ��������� ����:
    *
    * [���������� ��� N]
    * <br><b>|</b> [ID 1 ����][������� ���������� ������� P]
    * <b>||</b> [������ ���� 1 ������][��� 1 ������]..[������ ���� P ������][��� P ������] <b>||</b>
    * [���������� ���������� ������� � 1 ����][������� ���� 1 ����]
    * <br>..
    * <br>[ID N ����][������� ���������� ������� P]
    * <b>||</b> [������ ���� 1 ������][��� 1 ������]..[������ ���� P ������][��� P ������] <b>||</b>
    * [���������� ���������� ������� � N ����][������� ���� N ����] <b>|</b>
    * @param list ������ ��� ��������� �������
    * @return ������ ����, � ������� ��������� ������� ��� �������� ����������
    */
    QByteArray outListAllNewGame(QList<GameThousand*> &list);

    /**
    * @brief ��������� �������� ������ �� ������� ������ ���� ������� ���
    *
    * �������� ������ ����������� � ��������� ����:
    *
    * [���������� ��� N]
    * <br><b>|</b> [ID 1 ����][���������� ���������� ������� � 1 ���� P]
    * <b>||</b> [������ ���� 1 ������][��� 1 ������]..[������ ���� P ������][��� P ������] <b>||</b>
    * [������� ���� 1 ����]
    * <br>..
    * <br>[ID N ����][���������� ���������� ������� � N ���� P]
    * <b>||</b> [������ ���� 1 ������][��� 1 ������]..[������ ���� P ������][��� P ������] <b>||</b>
    * [������� ���� N ����] <b>|</b>
    * @param list ������ ������� ���
    * @return ������ ����, � ������� ��������� ������� ��� �������� ����������
    */
    QByteArray outListAllCurrentGame(QList<GameThousand*> &list);
private:
    //! ��������� �� ���������� ������� ��������
    ThousandGameQueryHandler *handler;

signals:

public slots:

};

#endif // THOUSANDGAMEDATAPARSER_H
