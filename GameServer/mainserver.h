/**
* @file mainserver.h
* @author Kharkunov Eugene
* @date 2.06.2011
*/

#ifndef MAINSERVER_H
#define MAINSERVER_H

#include <QtGui/QMainWindow>

/**
* @class MainServer
* @brief �����, ����������� ������ �������� �������
* @note ���������� ��� ���������
*/
class MainServer : public QMainWindow
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
    * @param parent ��������� �� ������������ ������
    */
    explicit MainServer(QWidget *parent = 0);

    //! ���������� ����������
    ~MainServer();

private:
    /**
    * @brief �������� ����
    */
    void createMenus();
    //! ������ ������ MainServer
    static MainServer *server;

    //!
    QMenu *fileMenu;
    QMenu *settingsMenu;
    QMenu *aboutMenu;

    QDockWidget *serversList;
    QDockWidget *controlButtons;
    QDockWidget *errorMessages;
private slots:
    void retranslateApp();
    void aboutQt();
};

#endif // MAINSERVER_H
