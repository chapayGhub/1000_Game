/**
* @file httpconnection.h
* @brief ���� � ��������� ������ HTTP ����������
* @author Kharkunov Eugene
* @date 16.09.2011
*/
#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H

#include <QThread>

class QTcpSocket;
class HttpRequest;
class HttpResponse;

/**
* @class HttpConnection
* @brief �����, ����������� ��������� �������� � ���������� ������� � ��������� ������
*/
class HttpConnection : public QThread
{
    Q_OBJECT
public:
    /**
    * @brief ����������� ������, ��������� ���������� ����������� ���������� ������
    * @param socket �����, ������� ������������ ����� ������� ����� �������� � ��������
    * @param name   ��� �������, ��� �������� ��������� ����������
    * @param parent ��������� �� ������������ ������
    */
    explicit HttpConnection(QTcpSocket *socket, QString name, QObject *parent = 0);

    /**
    * @brief ����������� ����������
    */
    virtual ~HttpConnection();

    /**
    * @brief ����� ���������� � ���� ����������� ��� ������
    *
    * ���������� ��������� �������, ���������� �� �������, � ������������ ���������������� ������
    */
    void run();

    /**
    * @brief �������� ��������� �� �����, ����������� ������� �������������� �������� ������
    * @return ��������� �� �����
    */
    QTcpSocket* socket() const;

private:
    //! ��������� �� �����, �������������� ����������
    QTcpSocket *_mSocket;

    //! ��� �������, ��� �������� ������� ������ ����������
    QString _mServerName;

    //! ������, ��������� �� �������
    HttpRequest *_mRequest;

    //! �����, �������������� �� ��������� ������ �������
    HttpResponse *_mResponse;

signals:
    /**
    * @brief ������, ������� ���������� � ������, ���� ���� ������ ��� ������
    */
    void readyRead();

    /**
    * @brief ������, ������� ������������� � ���, ��� ������ ������������ � �������� ����� ����������
    * @param data ������, ��� ��������
    */
    void dataReady(QByteArray data);

    /**
    * @brief ������, ������� ����������, ����� ��� ��������� ������ ���������
    * @param res ������, ��������� �� �������
    * @param req �����, �������������� ��������
    */
    void transactionDone(HttpRequest* req, HttpResponse* res);
};

#endif // HTTPCONNECTION_H
