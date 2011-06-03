/**
* @file mainserver.h
* @author Kharkunov Eugene
* @date 2.06.2011
*/

#ifndef MAINSERVER_H
#define MAINSERVER_H

#include <QWidget>


/**
* @class MainServer
* @brief �����, ����������� ������ �������� �������
* @note ���������� ��� ���������
*/
class MainServer : public QWidget
{
    Q_OBJECT
public:
    /**
    * @brief ����� ��������� ������� ������ MainServer
    * @return ��������� �� ������ ������ MasinServer
    */
    static MainServer* getInstance();

    //! ���������� ��������� ������ ������ MainServer
    static void destroy();

    /**
    * @brief ����������� �� ���������
    * @param parent �������� ������
    */
    explicit MainServer(QWidget *parent = 0);

    //! ���������� ����������
    ~MainServer();

private:
    static MainServer *server;
};

#endif // MAINSERVER_H
