#include <core/client.h>

Client::Client(QObject *parent) : QObject(parent)
{
}
Client::~Client() = default;
int Client::getServerNum()
{
    return int(this->_serverList.length());
}
QList<Server *> Client::getServerList()
{
    return this->_serverList;
}
Server *Client::getServer(int index)
{
    if (index < 0 || index >= this->getServerNum())
    {
        qFatal("服务器列表索引越界");
        return nullptr;
    }
    return this->_serverList[index];
}
void Client::addServer(QString host, int port, QString nick, QString user, QString passwd)
{
    auto *newServer = new Server(Server::Tcp, host, port, nick, user, passwd);
    newServer->login();
    connect(newServer, &Server::loginSuccess, this, &Client::addServer2List);
}
void Client::addServer2List(Server *server)
{
    this->_serverList.append(server);
    emit loginSuccess(server);
}
