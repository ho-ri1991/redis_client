#include"redis_client.hpp"
#include<iostream>

int main(){
    auto con = redis_client::make_redis_connection("localhost", 6379);
    if(!con){
        std::cout<<"failed to connect to redis"<<std::endl;
        return 1;
    }

    redis_client::RedisExec(con, "SET var1 1");
    auto reply = redis_client::RedisExec(con, "GET var1");
    if(!reply || reply->str == nullptr){
        std::cout<<"failed to get variable"<<std::endl;
        return 0;
    }
    std::cout<<reply->str<<std::endl;
    return 0;
}