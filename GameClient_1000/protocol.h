/**
* @file protocol.h
* @author Kharkunov Eugene
* @date 5.06.2011
* @brief ���� �������� �������� ���� �������� ����������������� ��������� ��������, � ����� ���������
* ������ �������
*/

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QDataStream>

/**
* @enum QueryType
* @brief ������������ ��������� �������� �������, ������������� � ����������������
* ���������
*/
enum QueryType {
    //! ������ �� ����������� ������ ���������
    REGISTER,
    //! ������ �� ����������� ������������
    AUTHORIZATION,
    //! ������ �� �������� ��������� � ���
    MESSAGE,
    //! ������ �� �������� ����� ����
    NEWGAME,
    //! ������ �� ����������� ������ � ��������� ����
    CONNECTGAME,
    //! ������ �� ���������� ������ �� ��������� ����
    DISCONNECTGAME,
    //! ������ �� ������ ��������� ����
    STARTGAME,
    //! ������ �� ������ ��������� ����
    CANCELGAME,
    //! ������ �� ������� ����������� �� ��������� ����
    FINISHGAME,
    //! ������ �� ��������� ������� ������ ��� �� �������
    LISTALLCURRENTGAME,
    //! ������ �� ��������� ������ ��������� ���, ��������� �������
    LISTALLNEWGAME,
    //! ������ �� ��������� ���������� �� �������
    TOTALSTATISTICS,
    //! ������ �� ��������� ���������� ����������� ������������
    PLAYERSTATISTICS,
    //! ������ �� ��������� ������������ ����
    MOVE
};

/**
* @struct QueryStruct
* @brief ��������� ��������� ������� ����������������� ��������� �������� ������
*/
struct QueryStruct {
    //! ���������� ������
    quint16 socketDescriptor;
    //! ��� �������
    QueryType type;
    //! ������ ������������ ������
    qlonglong size;
    /**
    * @brief ������������� �������� ��������� ������ � �����
    * @param stream ����� � �������
    * @param str    ������, ������� ���������� ��������� � �����
    * @return ����� � �������
    */
    friend QDataStream& operator <<(QDataStream &stream, const QueryStruct &str) {
        stream<<str.type<<str.size;
        return stream;
    }

    /**
    * @brief ������������� �������� ���������� ������ �� ������
    * @param stream ����� � �������
    * @param str    ����������� ������
    * @return ����� � �������
    */
    friend QDataStream& operator >>(QDataStream &stream, QueryStruct &str) {
        int type = 0;
        stream>>type>>str.size;
        str.type = static_cast<QueryType>(type);
        return stream;
    }
};

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
};

/** @}*/

#endif // PROTOCOL_H
