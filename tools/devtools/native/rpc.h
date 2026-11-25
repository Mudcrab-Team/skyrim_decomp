#pragma once

#include <filesystem>
#include <functional>
#include <string>
#include <nlohmann/json.hpp>

namespace devtools
{
    using Json = nlohmann::json;
    using Dispatch = std::function<Json(const std::string&, const Json&)>;

    struct RpcError
    {
        int code;
        const char* message;
    };

    bool StartServer(int port, std::string token, const std::filesystem::path& transcript, Dispatch dispatch,
                     std::function<void()> closeSession);
}
