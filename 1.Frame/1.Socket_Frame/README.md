# Socket框架说明

* *==namespace==* :  `Sunow_Socket_Lib`

* *==class name==* :  `MYSocket`

* *==成员函数==*　：

  1.  构造函数：

      `MYSocket(const char *IP /*IP*/ , const int Port = 6666/*端口*/);`

  2.  服务端开启端口创建监听：

      `bool server_create();`

  3.  服务端接受连入（无连接阻塞：accept）:

      `bool server_accept();`

  4.  服务端获取`server_accept();`接入的连接对端IP ：

      `bool server_get_IP(char *return_IP);`

      >   return_IP : char *类型，用于存储获得的IP。

  5.  客户端创建连接：

      `bool client_create();`

  6.  发送与接收数据：

      ```c++
      /* 发送数据 
       * data : 待发送数据变量的地址，若是数组则填写数组名称即可。
       * bitsize : 待发送数据大小，与malloc类似，例如：sizeof(char) * 10;
       */
      
      template <typename T>
      bool send_data(T *data, const int bitsize);
      
      /* 接收数据 
       * data与bitsize同上。
       */
      
      template <typename T>
      bool recv_data(T *data, const int bitsize);
      ```

      