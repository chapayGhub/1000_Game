#ifndef THOUSANDCLIENT_H
#define THOUSANDCLIENT_H

#include "abstractclient.h"
#include "protocol.h"
#include "thousandclientdataparser.h"

class ThousandClientDataParser;
class ThousandClient : public AbstractClient
{
friend class ThousandClientDataParser;

  Q_OBJECT
public:
    ThousandClient(quint16 port,QString ip="127.0.0.1",QObject *parent = 0);
    //!������� ��� ������������� � �������
    void connectToServer();
    /**
    * @brief ������� ��������� ����� ������
    * @param ip - ip-����� �������
    */
    void setHostAddress(const QString ip);

    /**
    * @brief ������� ���������� ��������� �� ������ ������
    * @return ��������� �� ������ ������
    */
    ThousandClientDataParser* getDataParser();

public slots:
    //! ���� ��� ����������� �������� ����������� � ����� � ����
    void serverConnected();
    /**
    * @brief ���� ��� ��������� ������ ����������
    * @param QAbstractSocket::SocketError - ���������� ��� �������� ������
    */
    void connectEror(QAbstractSocket::SocketError);
    /**
    * @brief ���� ��� �������� ������ �� ������
    * @param data - ������ ��� �������� �� �����
    * @param query - ������ � ������� ����������� ��� ���������� ������
    */
    void sendToServer(QByteArray &data, const QueryType &type);
    //! ���� �������������� ������ ��� ������ � �������� ����������� ����� ������ ��������� ������
    void serverReady();

private:
   //! ����� ��� ���������� � ��������
   QTcpSocket *connection;
   //! ���������� ��� �������� ������ �������
   QHostAddress hostAddress;
   //! ���������� �������� ��� ������������
   QString *name;
   //! ���������� �������� ip-����� �������
   QString serverIp;
   //! ���������� �������� ������ ������������
   QString *password;
   //! ���������� �������� ���� �������
   quint16 serverPort;
   //! ���������� ������������ ����������� �� ����������
   bool connectComplite;
   //! ���������� �������� ������ ���������� ����� ������ �� �������
   quint16 nextBlocSize;
   //! ���������� ��������� �� ������ ThousandClientDataParser
   ThousandClientDataParser *dataParser;
signals:
   void erorText(QString eror);

};

#endif // THOUSANDCLIENT_H
