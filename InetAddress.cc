#include "InetAddress.h"
#include <strings.h>
#include <cstring>

InetAddress::InetAddress(uint16_t port,std::string ip = "127.0.0.1")
{
    bzero(&addr_,sizeof addr_);
    addr_.sin_family = AF_INET; // 协议Ipv4
    addr_.sin_addr.s_addr = inet_addr(ip.c_str()); // 转成点分10进制的网络数
    addr_.sin_port = htons(port); // 网络字节序
}

std::string InetAddress::toIp() const
{
    char buf[64] = {0};
    inet_ntop(AF_INET,&addr_.sin_addr,buf,64);
    return buf;
}
std::string InetAddress::toIpPort() const
{
    char buf[64] = {0};
    inet_ntop(AF_INET,&addr_.sin_addr,buf,64);
    size_t end = strlen(buf);
    uint16_t port = ntohs(addr_.sin_port);
    sprintf(buf+end,":%u",port);
    return buf;
}
uint16_t InetAddress::toPort() const
{
    return ntohs(addr_.sin_port);
}