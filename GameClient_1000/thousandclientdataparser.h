#ifndef THOUSANDCLIENTDATAPARSER_H
#define THOUSANDCLIENTDATAPARSER_H

#include "abstractdataparser.h"
#include "thousandclient.h"
#include "protocol.h"

class ThousandClient;
class ThousandClientDataParser : public AbstractDataParser
{
    Q_OBJECT
public:
    ThousandClientDataParser(ThousandClient *client,QObject *parent=0);
    /**
    * @defgroup IncommingData ��������� �������� ������
    * ������ ������� ��� ��������� ����������� �� ������� ������
    * @{
    */
    /**
    * @brief ��������� ������ � ����������� ������ ������������
    * @param data ������ � ������������
    */
    void inRegistration(QByteArray &data);
    /**
    * @brief ��������� ������ ��� ����������� ������������
    * @param data ������ ��� �����������
    */
    void inAuthorization(QByteArray &data);
    /**
    * @brief ��������� ������, ����������� ��� �������� ����� ���� �� �������
    * @param data ������ ��� �������� ����
    */
    void inNewGame(QByteArray &data);

    void inMessage(QByteArray &data);
    /**
    * @brief ��������� ������ � ����������� ������ � ����
    * @param data ������ � ����������� � ��������� ����
    */
    void inConnectToGame(QByteArray &data);
    /**
    * @brief ��������� ������ �� ���������� �� ����
    * @param data ������ �� ���������� ������ �� ��������� ����(�� ������� �������)
    */
    void inDisconnectGame(QByteArray &data);
    /**
    * @brief ��������� ������ �� ������ ��������� ����
    * @param data ������, ���������� ���������� �� ������ ��������� ����
    */
    void inCancelGame(QByteArray &data);

    void inStartGame(QByteArray &data);

    void inFinishGame(QByteArray &data);
    /**
    * @brief ��������� ������, ����������� ��� ��������� �������� �� ������
    * @param data ������, ���������� ����������, ����������� ��� ��������� �������� �� ������
    */
    void inPlayerStatistics(QByteArray &data);

    void inTotalStatistics(QByteArray &data);

    void inMove(QByteArray &data);

    void inListAllGame(QByteArray &data);

    void inListAllNewGame(QByteArray &data);
    /** @}*/

    /**
    * @brief ������ ��� ��������� ������� ������
    */
    void incomingData();

private:
    //! ��������� �� ������ ������ �������� �� ������
    ThousandClient *workClient;

public slots:
    /**
    * @defgroup OutcommingData ���������� ������ ��� ��������
    * ������ �������, ��������������� ��� ���������� ������, ���������� �� �������, � �������� ��������
    * @{
    */

    /**
    * @brief �������������� ������ � ������������ ��� �����������
    * @param info ������ � ������������������ ������������
    */
    void outRegistration(const RegistrationData &info);
    /**
    * @brief �������������� ����� �� ����������
    * @param info ������ ����������� ������������
    */
    void outAuthorization(const AuthorizationData &info);
    /**
    * @brief
    * @param
    */
    void outMessage(const QString &message);
    /**
    * @brief
    * @return
    */
    void outNewGame(const GameSettings &game);
    /**
    * @brief
    * @return
    */
    void outConnectGame(const quint16 &gameID);
    /**
    * @brief
    * @return
    */
    void outDisconnectGame(const quint16 &gameID);
    /**
    * @brief
    * @return
    */
    void outCancelGame(const quint16 &gameID);
    /**
    * @brief
    * @return
    */
    void outStartGame(const quint16 &gameID);
    /**
    * @brief
    * @return
    */
    void outFinishGame(const quint16 &gameID);
    /**
    * @brief
    * @return
    */
    void outListAllGame();
    /**
    * @brief
    * @return
    */
    void outListAllNewGame();
    /**
    * @brief
    * @return
    */
    void outTotalStatistics();
    /**
    * @brief
    * @return
    */
    void outPlayerStatistics(const PlayerInformation &player);
    /**
    * @brief
    * @return
    */
    void outMove(const Card &card);
    /** @}*/

signals:
    //! ������ � ���������� ����������
    void compliteRegistration(QVector<QString> data);
    //! ����� � ���������� �����������
    void compliteAuthorization(QVector<QString> data);
    //! ������ � ��������� �������� ����� ���� �� �������
    void compliteNewGame(QDataStream &in);
    //! ������ � ��� ��� �� ������ ������ ���������
    void compliteMessage(QString message);
    //! ������ � ��� ��� ������ �������������� � ����
    void compliteConnectToGame(QDataStream &in);
    //! ������ � ��� ��� ������ ������������ �� ����
    void compliteDisconnectGame(QDataStream &in);
    //! ������ �� �������� ������ ��������� ����
    void compliteCancelGame(QDataStream &in);
    //! ������ � ������ ����
    void compliteStartGame(QDataStream &in);
    //! ������ �� �������� ����
    void compliteFinishGame(QDataStream &in);
    //! ������ ���������� ���������� ������
    void complitePlayerStatistics(PlayerInformation info);
    //! ������ ���������� ��� ���������� �������
    void compliteTotalStatistics(QVector<PlayerInformation> info);
    //! ������ � �������� ����
    void compliteMove(Card card);
    //! ������ ���������� ������ ���� ���
    void compliteListAllGame(QList<GameThousand> list);
    //! ������ ��������� ������ ���� ����� ���
    void compliteListAllNewGame(QList<GameThousand> list);
};

#endif // THOUSANDCLIENTDATAPARSER_H
