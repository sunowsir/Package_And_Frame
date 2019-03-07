#!/bin/bash

g++ -c ./SocketFrame.cpp
if [[ $1 == "server" ]];
then
    g++ -c ./test_server.cpp
    g++ ./SocketFrame.o ./test_server.o -o Server
else 
    g++ -c ./test_client.cpp
    g++ ./SocketFrame.o ./test_client.o -o Client
fi
