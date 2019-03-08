/*
 * File Name:    SocketFrame.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年03月06日 星期三 11时06分20秒
 */

#include "./SocketFrame.h"

Sunow_Socket_Lib::MYSocket::MYSocket(const char *IP, const int Port) {
    if (IP == NULL) {
        std::cerr << "Sunow_Lib::MYSocket::MYSocket() [IP is NULL]!" << std::endl;
        exit(1);
    }
    this->IP = new char[strlen(IP)];
    strcpy(this->IP, IP);
    this->Port = Port;
    
    /* 初始化sockaddr_in结构体属性  */
    this->socket_addr.sin_family = AF_INET;
    this->socket_addr.sin_addr.s_addr = inet_addr(this->IP);
    this->socket_addr.sin_port = htons(this->Port);
    
    this->socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

Sunow_Socket_Lib::MYSocket::~MYSocket() {
    if (this->IP != NULL) delete[] this->IP;
    close(this->socketfd);
}

bool Sunow_Socket_Lib::MYSocket::server_create () {
    if (bind(this->socketfd, (struct sockaddr*)&this->socket_addr, sizeof(this->socket_addr)) < 0) {
        std::cerr << "sunow_Lib::MYSocket::server_create() : [bind error]!" << std::endl;
        return false;
    }
    if (listen(this->socketfd, 20) < 0) {
        std::cerr << "sunow_Lib::MYSocket::server_create() : [listen error]!" << std::endl;
        return false;
    }
    return true;
}

bool Sunow_Socket_Lib::MYSocket::client_create() {
    if (inet_pton(AF_INET, this->IP, &this->socket_addr.sin_addr) < 0) {
        std::cerr << "Sunow_Lib::MYSocket::client_create() : [inet_pton error]!" << std::endl;
        return false;
    }
    if (connect(this->socketfd, (struct sockaddr*)&this->socket_addr, sizeof(this->socket_addr)) < 0) {
        std::cerr << "Sunow_Lib::MYSocket::client_create() : [connect error]!" << std::endl;
        return false;
    }
    return true;
}

/* socket服务端获取accept监听到的连入者IP */
bool Sunow_Socket_Lib::MYSocket::server_get_IP(char *return_IP) {
    if (inet_ntop(AF_INET, (void *)&(this->accept_socket_addr.sin_addr), return_IP, 20) == NULL) {
        std::cerr << "Sunow_Lib::MYSocket::server_get_IP() : [inet_ntop error]!" << std::endl;
        return false;
    }
    return true;
}

bool Sunow_Socket_Lib::MYSocket::server_accept() {
    int new_socketfd;
    this->accept_socket_addr_len = sizeof(this->accept_socket_addr);
    new_socketfd = accept(this->socketfd, (struct sockaddr *)&this->accept_socket_addr, &this->accept_socket_addr_len);
    if (new_socketfd < 0) {
        return false;
    }
    this->old_socketfd = this->socketfd;
    this->socketfd = new_socketfd;
    return true;
}
