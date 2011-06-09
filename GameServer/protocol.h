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
    //!
    REGISTER,
    //!
    AUTHORIZATION,
    //!
    MESSANGE,
    //!
    NEWGAME,
    //!
    CONNECTGAME,
    //!
    DISCONNECTGAME,
    //!
    STARTGAME,
    //!
    CANCELGAME,
    //!
    FINISHGAME,
    //!
    LISTALLGAME,
    //!
    LISTALLNEWGAME,
    //!
    TOTALSTATISTICS,
    //!
    PLAYERSTATISTICS,
    //!
    MOVE
};

/**
* @struct QueryStruct
* @brief ��������� ��������� �������
*/
struct QueryStruct {
    //! ���������� ������
    quint16 socketDescriptor;
    //! ��� �������
    QueryType type;
    //! ������ ������������ ������
    qulonglong size;
    /**
    *
    */
    friend QDataStream& operator <<(QDataStream &stream, const QueryStruct &str) {
        stream<<str.type<<str.size;
        return stream;
    }
    friend QDataStream& operator >>(QDataStream &stream, QueryStruct &str) {
        int type = 0;
        stream>>type>>str.size;
        str.type = static_cast<QueryType>(type);
        return stream;
    }
};

#endif // PROTOCOL_H
