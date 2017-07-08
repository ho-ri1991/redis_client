#ifndef REDIS_CLIENT_HPP
#define REDIS_CLIENT_HPP

#include<hiredis/hiredis.h>
#include<memory>
#include<string>

namespace redis_client{
    template<auto func>
    struct function_caller{
    	template<typename... Us>
        auto operator()(Us&&... us) const {
            return func(std::forward<Us...>(us...));
        }
    };

    using RedisConnection = std::unique_ptr<redisContext, function_caller<&redisFree>>;
    inline RedisConnection make_redis_connection(const std::string& ip, int port){
        return RedisConnection(redisConnect(ip.c_str(), port));
    }

    using RedisReplyObject = std::unique_ptr<redisReply, function_caller<&freeReplyObject>>;
    inline RedisReplyObject RedisExec(const RedisConnection& con, const std::string& query){
        if (!con)return nullptr;
        return RedisReplyObject((redisReply *) (redisCommand(con.get(), query.c_str())));
    }
}

#endif
