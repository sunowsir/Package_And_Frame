/*
 * File Name:    SocketFrame.h
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年03月06日 星期三 11时06分09秒
 */

#ifndef _SOCKETFRAME_H
#define _SOCKETFRAME_H

#include "../needHead.h"

namespace Sunow_Lib {
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
        bool server_get_IP(char *return_IP);
        bool server_accept();
        
        bool client_create();
        
        template <typename T>
        bool send_data(T data, int bitsize);
        template <typename T>
        bool recv_data(T return_data, int bitsize);
    };
}


#endif
