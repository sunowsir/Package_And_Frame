/*
 * File Name:    SocketFrame.h
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年03月06日 星期三 11时06分09秒
 */

#ifndef _SOCKETFRAME_H
#define _SOCKETFRAME_H

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>


namespace Sunow_Socket_Lib {
    class MYSocket {
    private : 
        char *IP;
        int Port;
        int socketfd, old_socketfd;
        socklen_t accept_socket_addr_len;
        struct sockaddr_in socket_addr;
        struct sockaddr_in accept_socket_addr;
    public : 
        MYSocket(const char *IP, const int Port = 6666);
        ~MYSocket();
        bool server_create();
        bool server_accept();
        bool server_get_IP(char *return_IP);
        
        bool client_create();
        
        template <typename T>
        bool send_data(T *data, const int bitsize);
        template <typename T>
        bool recv_data(T *return_data, const int bitsize);
    };
    
    /* 发送数据  */
    template <typename T>
    bool MYSocket::send_data(T *data, const int bitsize) {
        if (send(this->socketfd, data, bitsize, 0) < 0) {
            std::cerr << "Sunow_Lib::MYSocket::send_data() : [send error]!" << std::endl;
            return false;
        }
        return true;
    }
    
    /* 接收数据  */
    template <typename T>
    bool MYSocket::recv_data(T *return_data, const int bitsize) {
        memset(return_data, 0, sizeof(return_data));
        if (recv(this->socketfd, return_data, bitsize, 0) < 0) {
            std::cerr << "Sunow_Lib::MYSocket::recv_data() : [recv error]!" << std::endl;
            return false;
        }
        return true;
    }
}


#endif
