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
    int data = 111;
    client.send_data<int>(data, sizeof(int));
    cout << "send :" << data << " to server" << endl;
    client.recv_data<int>(&data, sizeof(int));
    cout << "receive : " << data << " to client" << endl;
    return 0;
}
