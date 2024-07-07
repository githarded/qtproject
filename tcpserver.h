#pragma once

#include <QDebug>
#include <QObject>
#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_SIZE 1024
#define PORT 8887
#define MaxClient 20

class tcpSeverer : public QObject
{
    Q_OBJECT
public:
    explicit tcpSeverer(QString file_path);
    //不同类型的文件传输
    void foldertransmitS(QString file_path); //文件夹类型接收
    void filetransmitS(QString file_path);   //文件类型接收

private:
    //判断传输文件的类型的函数
    int filetype(QString file_path);
    int switchfile(QString file_path);
    void switchflag(QString file_path);

    int _socketfd;
    sockaddr_in *_addr;
    socklen_t _len;
    int _socketfd2;
    int _flag;
    sockaddr_in *addrs;
};
