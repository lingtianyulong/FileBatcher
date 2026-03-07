use std::sync::OnceLock;
use time::format_description::FormatItem;
use tracing::{debug, error, info, warn};
use tracing_appender::non_blocking::WorkerGuard;
use tracing_subscriber::{EnvFilter, fmt, layer::SubscriberExt, util::SubscriberInitExt};

pub struct Logger {
    _guard: WorkerGuard,
}

static LOGGER: OnceLock<Logger> = OnceLock::new();

impl Logger {
    pub fn init() {
        LOGGER.get_or_init(|| {
            let file_appender = tracing_appender::rolling::daily("logs", "app.log");
            let (non_blocking, guard) = tracing_appender::non_blocking(file_appender);

            // 定义时间格式
            let time_format: &[FormatItem] =
                time::macros::format_description!("[year]-[month]-[day] [hour]:[minute]:[second]");

            let timer = fmt::time::OffsetTime::new(
                time::UtcOffset::from_hms(8, 0, 0).expect("UTC+8 offset should be valid"),
                time_format,
            );

            let fmt_layer = fmt::layer()
                .with_timer(timer)
                .with_thread_ids(true)
                .with_thread_names(true)
                .with_target(true)
                .with_writer(non_blocking)
                .with_ansi(false);

            tracing_subscriber::registry()
                .with(EnvFilter::new("info"))
                .with(fmt_layer)
                .init();

            Logger { _guard: guard }
        });
    }

    pub fn info(msg: &str) {
        info!("{}", msg);
    }

    pub fn warn(msg: &str) {
        warn!("{}", msg);
    }

    pub fn error(msg: &str) {
        error!("{}", msg);
    }

    pub fn debug(msg: &str) {
        debug!("{}", msg);
    }
}

#[cfg(test)]
mod tests {
    use super::Logger;
    use std::{
        fs, thread,
        time::{Duration, SystemTime, UNIX_EPOCH},
    };

    #[test]
    fn init_writes_log_message_to_file() {
        Logger::init();

        let message = format!(
            "logger-test-message-{}",
            SystemTime::now()
                .duration_since(UNIX_EPOCH)
                .expect("system time should be after unix epoch")
                .as_nanos()
        );

        Logger::info(&message);

        // non_blocking writer flushes asynchronously, so give it a short moment.
        thread::sleep(Duration::from_millis(300));

        let log_dir = std::path::Path::new("logs");
        assert!(
            log_dir.exists(),
            "logs directory should be created after init"
        );

        let found_message = fs::read_dir(log_dir)
            .expect("logs directory should be readable")
            .filter_map(Result::ok)
            .map(|entry| entry.path())
            .filter(|path| path.is_file())
            .any(|path| {
                fs::read_to_string(path)
                    .map(|content| content.contains(&message))
                    .unwrap_or(false)
            });

        assert!(found_message, "expected log file to contain test message");
    }
}
