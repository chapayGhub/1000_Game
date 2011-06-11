#include "thousandgamequeryhandler.h"
#include "thousandgameserver.h"
#include "thousandgamedataparser.h"
#include "connectionmanager.h"
#include "protocol.h"
#include <QSqlQuery>
#include <QSqlError>

ThousandGameQueryHandler::ThousandGameQueryHandler(ThousandGameServer *parentServer, QObject *parent) :
    AbstractQueryHandler(parent),
    server(parentServer)
{
    parser = new ThousandGameDataParser(this, parent);
}

ThousandGameQueryHandler::~ThousandGameQueryHandler() {
    delete parser;
    parser = 0;
}

void ThousandGameQueryHandler::run() {
    QueryStruct incommingRequest;//�������� ������
    QueryStruct outcommingRequest;//��������� ������
    QVector<QString> messageArray;//������ ���������
    bool empty;//������� ������� �������
    do {
        messageArray.clear();
        //��������� ������, ������� ��������� ������ � �������
        server->locker.lockForRead();
        incommingRequest = server->_mRequestQueries.first();
        server->locker.unlock();
        QByteArray inputData, outputData;//�������� � ��������� ������
        QTcpSocket *socket = 0;
        //! TODO: ������������� ����� ����������
        if (incommingRequest.size > 0) {
            socket = server->_mManager->findSocket(incommingRequest.socketDescriptor);
            QDataStream stream(socket);
            Q_ASSERT_X(socket, "ThousandGameQueryHandler::run()", "Cannot find socket for reading");
            quint16 dataSize = incommingRequest.size;
            quint16 blockSize = 0;
            //��������� ������ ��� ������ � ��������
            while(dataSize) {
                blockSize = socket->bytesAvailable();
                if (blockSize) {
                    char *buffer = new char[blockSize];
                    stream.readRawData(buffer, sizeof(buffer));
                    inputData.append(buffer);
                    dataSize -= blockSize;
                    blockSize = 0;
                    delete buffer;
                }
                else qDebug()<<"Null block";
            }
        }
        QueryType type = incommingRequest.type;
        switch(type) {
        //===============================================================================================
        case REGISTER : {
            RegistrationData regInfo = parser->inRegistration(inputData);
            //! TODO: ������� ����������� � ��������� �� ����� ����
            QSqlDatabase db = server->mapName2Database.value("1000_UserInformation.sqlite");
            if (db.isValid())
                messageArray.append(tr("Cannot find connetion to database 1000_UserInformation.sqlite\n"));
            else {
                QSqlQuery query(db);
                QString strQuery = "SELECT Nickname FROM UserInformation WHERE Nickname = %1;";
                strQuery.arg(regInfo.nickName);
                query.prepare(strQuery);
                query.exec();
                if (query.isValid())
                    messageArray.append(tr("The user with the same nickname is already exist!\n"));
                else {
                    strQuery = "INSERT INTO UserInformation "
                            "(Nickname, Password, RealName, TotalNumberOfGames, Wins, Loses)"
                            "VALUES('%1', '%2', '%3', 0, 0, 0);";
                    strQuery.arg(regInfo.nickName)
                            .arg(regInfo.password)
                            .arg(regInfo.realName);
                    query.prepare(strQuery);
                    query.exec();
                    if (!query.isActive()) messageArray.append(query.lastError().text());
                    else messageArray.append(tr("Registration successful!\n"));
                    query.finish();
                }
            }
            outputData = parser->outRegistration(messageArray);
            outcommingRequest.socketDescriptor = incommingRequest.socketDescriptor;
            outcommingRequest.type = REGISTER;
            outcommingRequest.size = sizeof(outputData);
            break;
        }
        //===============================================================================================
        case AUTHORIZATION : {
            AuthorizationData authInfo = parser->inAuthorization(inputData);
            QSqlDatabase db = server->mapName2Database.value("1000_UserInformation.sqlite");
            if (db.isValid())
                messageArray.append(tr("Cannot find connetion to database 1000_UserInformation.sqlite\n"));
            else {
                QSqlQuery query(db);
                //�������� �� ������� ���������� ������������
                QString strQuery = "SELECT Nickname, Password FROM UserInformation "
                        "WHERE Nickname = %1;";
                strQuery.arg(authInfo.login);
                query.prepare(strQuery);
                query.exec();
                if (!query.isValid())
                    messageArray.append(tr("Invalid user login\n"));
                else {//��������� �� ���������� �������
                    if (query.value(1).toString() != authInfo.password)
                        messageArray.append(tr("Invalid user password\n"));
                    else messageArray.append(tr("Authorization successful!\n"));
                }
            }
            outputData = parser->outAuthorization(messageArray);
            outcommingRequest.socketDescriptor = incommingRequest.socketDescriptor;
            outcommingRequest.type = AUTHORIZATION;
            outcommingRequest.size = sizeof(outputData);
            break;
        }
        //===============================================================================================
        case MESSANGE : {
            break;
        }
        case NEWGAME : {
            break;
        }
        case CONNECTGAME : {
            break;
        }
        case DISCONNECTGAME : {
            break;
        }
        case STARTGAME : {
            break;
        }
        case CANCELGAME : {
            break;
        }
        case FINISHGAME : {
            break;
        }
        case LISTALLGAME : {
            break;
        }
        case LISTALLNEWGAME : {
            break;
        }
        case TOTALSTATISTICS : {
            break;
        }
        case PLAYERSTATISTICS : {
            break;
        }
        case MOVE : {
            break;
        }
        default : {
        }

        }
        //�������� ��������� ������� �������
        QByteArray byteRequest;
        byteRequest<<outcommingRequest;
        server->_mManager->setSocketState(socket, WaitForQueryTransmission);
        server->sendToClient(byteRequest, socket);
        server->_mManager->setSocketState(socket, WaitForDataTransmission);
        server->sendToClient(outputData, socket);
        server->_mManager->setSocketState(socket, WaitForQueryTransmission);
        //������� ������������ ������ �� �������
        server->locker.lockForWrite();
        server->_mRequestQueries.removeFirst();
        server->locker.unlock();
        //��������� ������� �� �������
        server->locker.lockForRead();
        empty = server->_mRequestQueries.isEmpty();
        server->locker.unlock();
    } while (!empty);

}
