#include <netinet/in.h>
#include <arpa/inet.h>
#include <map>
#include "Connection.h"
#include <poll.h>
#include <stdio.h>
#ifndef SOCK_NONBLOCK
#include <fcntl.h>
#define SOCK_NONBLOCK O_NONBLOCK
#endif


#define SERVER "142.232.135.38"
#define SOCKET_DATA_WAITING 555
#define SOCKET_NODATA 666


class TCPClient {

public:
	TCPClient();
	int initializeSocket(short port, char * server);
	void sendBytes(char * data, uint32_t len);
	int32_t receiveBytes(char * buffer, uint32_t size);

	void closeConnection();


private:
	int clientSocket;
	sockaddr_in serverAddr;


};