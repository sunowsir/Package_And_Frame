/*
 * File Name:    server.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年03月06日 星期三 16时47分06秒
 */

#include "./SocketFrame.h"

using std::cin;
using std::cout;
using std::endl;
using namespace Sunow_Lib;

int main() {
    MYSocket server("192.168.2.133", 6667);
    server.server_create();
    server.server_accept();
    char fromIP[20] = {0};
    server.server_get_IP(fromIP);
    cout << fromIP << "already connect!" << endl;
    // char data[100] = {0};
    int data = 0;
    server.recv_data<int>(data, (int)sizeof(int));
    cout << "receive : \"" << data << "\"" << endl;
    data = 100;
    server.send_data<int>(data, (int)sizeof(int));
    cout << "send : \"" << data << "\"" << endl;
    return 0;
}
