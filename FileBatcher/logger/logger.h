#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include <string_view>

namespace file_batcher::logger {
class Logger {
public:
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&) = delete;

    ~Logger();

    static void LoadConfig(const std::string& config_file_path) noexcept;

    [[nodiscard]]
    static bool init();

    static void Info(std::string_view message);

private:
    struct Config {
        std::string log_file_path = "file_batcher.log";
        size_t max_file_size = 1024 * 1024 * 10;  // 10MB
        size_t max_files = 3;
        std::string level = "info";
        std::string flush_on = "err";
    };
    Logger() = default;
    static std::shared_ptr<spdlog::logger> _logger;
    static Config _config;
};

}  // namespace file_batcher::logger
