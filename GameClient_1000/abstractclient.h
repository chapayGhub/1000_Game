/**
* @file abstractClient.h
* @brief ������������ ���� ������ AbstractClient
*/
#ifndef ABSTRACTCLIENT_H
#define ABSTRACTCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include "protocol.h"


/**
* @class AbstractClient
* @brief ��������� ������ ������� ��� ������������ ����
*/
class AbstractClient : public QObject
{
    Q_OBJECT
public:
  /**
  * @brief ����������� ������ ��� ������ �������
  * @param parent ��������� �� �������� ������
  */
  explicit AbstractClient(QObject *parent = 0);

    virtual ~AbstractClient();

  //!������� ��� ������������� � �������
  virtual void connectToServer() = 0;
  /**
  * @brief ������� ��������� ����� ������
  * @param ip - ip-����� �������
  */
  virtual void setHostAddress(const QString ip) = 0;

signals:

public slots:
  //! ���� ��� ����������� �������� ����������� � ����� � ����
  virtual void serverConnected() = 0;
  /**
  * @brief ���� ��� ��������� ������ ����������
  * @param QAbstractSocket::SocketError - ���������� ��� �������� ������
  */
  virtual void connectEror(QAbstractSocket::SocketError) = 0;
  /**
  * @brief ���� ��� �������� ������ �� ������
  * @param data - ������ ��� �������� �� �����
  * @param query - ������ � ������� ����������� ��� ���������� ������
  */
  virtual void sendToServer(QByteArray &data,const QueryType &query) = 0;
  //! ���� �������������� ������ ��� ������ � �������� ����������� ������ ��� ����� ������ �������� ������
  virtual void serverReady() = 0;

};

#endif // ABSTRACTCLIENT_H
