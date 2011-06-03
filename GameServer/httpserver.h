/**
* @file httpserver.h
* @author Kharkunov Eugene
* @date 2.06.2011
*/

#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QTcpServer>

class ConnectionManager;

/**
* @class HttpServer
* @brief ��������� ������ ����������� Http �������
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
    * @brief ����������� �� ���������
    * @param port ����� �����, �� ������� ����� �������������� ��������
    * @param parent ��������� �� �������� ������
    * @note ����� �������� ��������� ����� @sa HttpServer::startServer() ��� ������� �������
    */
    explicit HttpServer(int port = 8080, QObject *parent = 0);

    //! ����������� ����������
    ~HttpServer();

    /**
    * @brief ���������, ������� �� ������
    * @return Running       ���� ������ ��������
    *         NotRunning    ���� ������ �� �������
    */
    states serverState() const;

    /**
    * @brief �������, ����������� ������
    * @return
    */
    bool startServer();
private:
    //! ��������� �������
    states currentState;

    //! �������� ����������
    ConnectionManager *manager;

    //! ����� �����, ������ �������������� ��������
    int mPort;
signals:
    /**
    * @brief ������, ������� ���������� ���
    * ������� ����������, ������� �������������� ����������� @p QTcpSocket
    * @note ���������� � ����� @sa HttpServer::slotConnectionAborted()
    */
    void connectionAborted(QTcpSocket*);
private slots:
    /**
    * @brief ����, ���
    */
    void slotConnectionAborted();

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
