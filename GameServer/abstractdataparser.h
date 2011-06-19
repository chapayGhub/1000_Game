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
//#include <QByteArray>

/**
* @defgroup DataStructure ��������� ������ ��� ��������
* @brief ���������, ������� ��������� ������, ������������ �� ����������������� ��������� ��������
* @{
*/

/**
* @struct RegistrationData
* @brief ��������� ��������� ������, ������� ���������� �� ������� � ������� � ������ ����������� ������
* ������������
*/
struct RegistrationData {
    //! ��� ������������(��� ��������� ��� ����� ��� �����������)
    QString nickName;
    //! ������
    QString password;
    //! ��������� ���
    //! TODO: ���������� ������������� � ������� ������
    QString realName;

    /**
    * @brief ������������� �������� ��������� ������ � ����������� ������������ � �����
    * @param stream ����� � �������
    * @param data   ������, ������� ���������� ��������� � �����
    * @return ����� � �������
    */
    friend QDataStream& operator <<(QDataStream &stream, const RegistrationData &data) {

        stream<<data.nickName.size()
              <<data.nickName
              <<data.password.size()
              <<data.password
              <<data.realName.size()
              <<data.realName;
        return stream;
    }

    /**
    * @brief ������������� �������� ���������� ������  � ����������� ������������ �� ������
    * @param stream ����� � �������
    * @param data   ����������� ������
    * @return ����� � �������
    */
    friend QDataStream& operator >>(QDataStream &stream, RegistrationData &data) {
        quint32 strSize;
        stream>>strSize;
        data.nickName.resize(strSize);
        stream>>data.nickName;
        stream>>strSize;
        data.password.resize(strSize);
        stream>>data.password;
        stream>>strSize;
        data.realName.resize(strSize);
        stream>>data.realName;
        return stream;
    }
};

/**
* @struct AuthorizationData
* @brief ���������, ������� �������� ������, ����������� ��� ����������� ������������ �� �������
*/
struct AuthorizationData {
    //! ����� ������������(��������� � �����)
    QString login;
    //! ������
    QString password;

    /**
    * @brief ������������� �������� ��������� ��������������� ������ � �����
    * @param stream ����� � �������
    * @param data   ������, ������� ���������� ��������� � �����
    * @return ����� � �������
    */
    friend QDataStream& operator <<(QDataStream &stream, const AuthorizationData &data) {
        stream<<data.login.size()
              <<data.login
              <<data.password.size()
              <<data.password;
        return stream;
    }

    /**
    * @brief ������������� �������� ���������� ��������������� ������ �� ������
    * @param stream ����� � �������
    * @param data   ����������� ������
    * @return ����� � �������
    */
    friend QDataStream& operator >>(QDataStream &stream, AuthorizationData &data) {
        quint32 strSize;
        stream>>strSize;
        data.login.resize(strSize);
        stream>>data.login;
        stream>>strSize;
        data.password.resize(strSize);
        stream>>data.password;
        return stream;
    }
};

/**
* @struct PlayerInformation
* @brief ��������� ��������� ���������� � ������������, ������� �������� � �� �������
*/
struct PlayerInformation {
    /**
    * @brief ID ������������ � ��.
    * @note �� ������� ������ � ID ������������, ������� ������������� ��� ����������� � �������.
    * @sa UserDescription::connectionID
    */
    quint16 ID;
    //! ��� ������������
    QString Nickname;
    //! ��������� ��� ������������
    QString RealName;
    //! ����� ����� ���
    quint16 totalNumber;
    //! ����� �����
    quint16 wins;
    //! ����� ���������
    quint16 loses;

    //! ����������� ������ ���������
    PlayerInformation() :
        ID(0),
        Nickname(""),
        RealName(""),
        totalNumber(0),
        wins(0),
        loses(0) {}

    /**
    * @brief ������������� �������� ��������� ���������� � ������������ � ����� ������
    * @param stream ����� � �������
    * @param info   ���������� � ������������
    * @return ����� � ����������� � ���� ������� � ������������
    */
    friend QDataStream& operator <<(QDataStream& stream, const PlayerInformation &info) {
        stream<<info.ID
              <<info.Nickname.size()
              <<info.Nickname
              <<info.RealName.size()
              <<info.RealName
              <<info.totalNumber
              <<info.wins
              <<info.loses;
        return stream;
    }

    /**
    * @brief ������������� �������� ���������� ���������� � ������������ �� ������ ������
    * @param stream ����� � �������
    * @param info   ���������� � ������������
    * @return ����� � ������������ �������
    */
    friend QDataStream& operator >>(QDataStream& stream, PlayerInformation &info) {
        quint32 strSize;
        stream>>info.ID;
        stream>>strSize;
        info.Nickname.resize(strSize);
        stream>>info.Nickname;
        stream>>strSize;
        info.RealName.resize(strSize);
        stream>>info.RealName
              >>info.totalNumber
              >>info.wins
              >>info.loses;
        return stream;
    }

    /**
    * @brief ������������� �������� ��������� ������ � ������������ � ������ ����
    * @param array  ������ ����
    * @param info   ���������� � ������������
    * @return ������ ���� � ���������� � ���� �����������
    */
    friend QByteArray& operator <<(QByteArray &array, const PlayerInformation &info) {
        array.clear();
        array.append(info.ID);
        array.append(info.Nickname.size());
        array.append(info.Nickname);
        array.append(info.RealName.size());
        array.append(info.RealName);
        array.append(info.totalNumber);
        array.append(info.wins);
        array.append(info.loses);
        return array;
    }
};

/**
* @struct GameSettings
* @brief ��������� ��������� ������, ����������� ��� ��������� ����������� ����
*/
struct GameSettings {
    //! ID ������, ������� ������� ����
    quint16 createrID;
    /**
    * @brief ���������� �������, �� ������� ���������� ����������� ����
    * @note ������ ���� �� 2 �� 4
    */
    quint8   playersNumber;
    /**
    * @brief �����, ������� ��������� ���������, ����� ������� ��� (�������� ���������� � ��������)
    * @note ������ ���� � �������� �� 30 �� 90 ������(��������� ��������: 30, 45, 60, 90)
    */
    quint16  timeout;

    /**
    * @brief ������������� �������� ��������� ������� �������� � ����� ������
    * @param stream     ����� � �������
    * @param settings   ������� ���������
    * @return ����� � ����������� � ���� �������� �����������
    */
    friend QDataStream& operator <<(QDataStream& stream, const GameSettings &settings) {
        stream<<settings.createrID
             <<settings.playersNumber
            <<settings.timeout;
        return stream;
    }

    /**
    * @brief ������������� �������� ���������� ������� �������� �� ������ ������
    * @param stream     ����� � �������
    * @param settings   ������� ���������
    * @return ����� � ������������ �������
    */
    friend QDataStream& operator >>(QDataStream& stream, GameSettings &settings) {
        stream>>settings.createrID
             >>settings.playersNumber
            >>settings.timeout;
        return stream;
    }

    /**
    * @brief ������������� �������� ��������� ������� �������� � ������ ����
    * @param array      ������ ����
    * @param settings   ������� ���������
    * @return ������ ���� � ����������� � ���� �����������
    */
    friend QByteArray& operator <<(QByteArray &array, const GameSettings &settings) {
        array.clear();
        array.append(settings.createrID);
        array.append(settings.playersNumber);
        array.append(settings.timeout);
        return array;
    }
};

/** @}*/

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
    //    virtual QByteArray outMessage() = 0;

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
    * @brief
    * @return
    */
    //    virtual QByteArray outListAllGame() = 0;

    /**
    * @brief
    * @return
    */
    //    virtual QByteArray outListAllNewGame() = 0;

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
