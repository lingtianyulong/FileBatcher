#include "logger.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <spdlog/sinks/rotating_file_sink.h>

namespace file_batcher::logger {

std::shared_ptr<spdlog::logger> Logger::_logger = nullptr;
Logger::Config Logger::_config;

Logger::~Logger() {
    spdlog::drop_all();
}

bool Logger::init() {

    _logger = spdlog::rotating_logger_mt("file_batcher", _config.log_file_path,
                                         _config.max_file_size, _config.max_files);
    _logger->set_level(spdlog::level::from_str(_config.level));
    _logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
    _logger->flush_on(spdlog::level::from_str(_config.flush_on));

    return true;
}

void Logger::LoadConfig(const std::string& config_file_path) noexcept {

    if (config_file_path.empty()) {
        return;
    }

    if (!config_file_path.ends_with(".json")) {
        return;
    }
    QFile file(QString::fromStdString(config_file_path));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonObject obj = doc.object();
    if (obj.contains("log_file_path")) {
        _config.log_file_path = obj["log_file_path"].toString().toStdString();
    }
    if (obj.contains("max_file_size")) {
        _config.max_file_size = obj["max_file_size"].toInt();
    }
    if (obj.contains("max_files")) {
        _config.max_files = obj["max_files"].toInt();
    }
    if (obj.contains("level")) {
        _config.level = obj["level"].toString().toStdString();
    }
    if (obj.contains("flush_on")) {
        _config.flush_on = obj["flush_on"].toString().toStdString();
    }
}

void Logger::Info(std::string_view message) {
    if (_logger) {
        _logger->info(message.data());
        return;
    }
}

}  // namespace file_batcher::logger