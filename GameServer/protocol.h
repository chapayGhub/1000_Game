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
    MESSANGE,
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
    LISTALLGAME,
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
    qulonglong size;
    /**
    * @brief ������������� �������� ��������� ������ � �����
    * @param stream ����� � �������
    * @param str    ������, ������� ���������� ��������� � �����
    * @return ����� � �������
    */
    friend QDataStream& operator <<(QDataStream &stream, const QueryStruct &str) {
        stream<<static_cast<quint32>(sizeof(str));
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
        quint32 size;
        stream>>size;
        stream>>type>>str.size;
        str.type = static_cast<QueryType>(type);
        return stream;
    }

    friend QByteArray& operator <<(QByteArray &array, const QueryStruct &str) {
        array.append(str.socketDescriptor);
        array.append(str.type);
        array.append(str.size);
        return array;
    }
};

#endif // PROTOCOL_H
