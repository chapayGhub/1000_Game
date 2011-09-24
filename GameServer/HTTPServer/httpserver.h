/**
* @file httpserver.h
* @author Kharkunov Eugene
* @date 2.06.2011
* @brief �������� �������� ������, ������������ ������ HTTP �������
*/

#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QTcpServer>
#include <QString>

class ConnectionManager;
class HttpRequest;
class HttpResponse;

/**
* @class HttpServer
* @brief ��������� ������ ����������� Http �������
* @note ���������� � ������� �������� "���������"
*/
class HttpServer : public QTcpServer
{
    Q_OBJECT
    /**
    * @enum states
    * @brief ��������� ��������� �������
    */
enum states {Running, NotRunning};
public:
    /**
    * @brief �������� ������ ������ HTTP ������
    * @return ��������� �� ������ ������� ������
    */
    static HttpServer* getInstance();

    /**
    * @brief ���������� ������ ������� ������
    */
    static void destroy();

    /**
    * @brief ����������� �� ���������
    * @param port ����� �����, �� ������� ����� �������������� ��������
    * @param parent ��������� �� ������������ ������
    * @note ����� �������� ��������� ����� HttpServer::startServer() ��� ������� �������
    */
    explicit HttpServer(int port = 80, QObject *parent = 0);

    //! ����������� ����������
    ~HttpServer();

    /**
    * @brief ���������, ������� �� ������
    * @return Running       ���� ������ ��������
    *         NotRunning    ���� ������ �� �������
    */
    states serverState() const;

    /**
    * @brief �������, ������� ������������ ������ �������. � ������ ������������� ������,
    * �������� ��������� �� ���� ����������� �����������
    * @return true  ���� ������ ������� ��� ������
    *         false ���� ������ �� ������� ���������
    */
    bool startServer();

    /**
    * @brief ��������� ����������� �������
    */
    void stopServer();

    /**
    * @brief �������, ������� �������� ��� �������
    * @return ������, ���������� ��� �������
    */
    QString serverName() const;
private:
    //! ������ ������� ������
    static HttpServer* _mInstance;

    //! ��������� �������
    states currentState;

    //! �������� ����������
    ConnectionManager *manager;

    //! ����� �����, ������� �������������� ��������
    int mPort;

    //! ��� �������
    QString _mServerName;
signals:
    /**
    * @brief ������, ������� ���������� � ������ ������������� ������ ��������� � �������
    * @param mes ��������� ���������, ���������� ����� ������� � ������� ��� ��������
    */
    void newMessage(QString mes);
private slots:
    /**
    * @brief ����, ��������������� ��� �������� ���������� �� ��������� ����������
    * @param data ����������, ������� ���������� ��������
    */
    void writeData(QByteArray data);

    /**
    * @brief ���� ��� ������������� ��������� ���������� ����� �������� � ��������
    * @param req ������, ���������� �� �������
    * @param res �����, �������������� ��������
    * @note �� ������ ����� ���� �������� � ���� ���� ����� ������ � ��� �������
    */
    void finishTransaction(HttpRequest* req, HttpResponse* res);
public slots:
    /**
    * @brief ���� ��� �������� ������ ���������� ��� ������� �����������
    */
    void addNewConnection();

    /**
    * @brief ���� ��� ��������� �������� �� ������� ����������
    */
    void readClientInformation();
};

#endif // HTTPSERVER_H
