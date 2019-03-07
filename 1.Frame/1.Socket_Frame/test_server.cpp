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
    MYSocket server("192.168.2.13", 6667);
    server.server_create();
    server.server_accept();
    char fromIP[20] = {0};
    server.server_get_IP(fromIP);
    cout << fromIP << " already connect!" << endl;
    char data[100] = {0};
    server.recv_data(data, sizeof(char) * 100);
    cout << "receive : '" << data << "' from client" << endl;
    int data1 = 123;
    server.send_data(&data1, sizeof(data1));
    cout << "send : '" << data1 << "' to client" << endl;
    return 0;
}
