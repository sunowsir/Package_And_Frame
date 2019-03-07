/*
 * File Name:    client.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年03月06日 星期三 21时14分25秒
 */

#include "./SocketFrame.h" 

using std::cin;
using std::cout;
using std::endl;
using namespace Sunow_Lib;


int main() {
    MYSocket client("192.168.2.13", 6667);
    client.client_create();
    char data[] = "hello server";
    client.send_data(data, sizeof(data) * 10);
    cout << "send : '" << data << "' to server" << endl;
    int data1 = 0;
    client.recv_data(&data1, sizeof(int));
    cout << "receive : '" << data1 << "' from client" << endl;
    return 0;
}
