use serde::{Deserialize, Serialize};
use std::fs::File;
use std::io::{BufReader, BufWriter};

#[derive(Debug, Serialize, Deserialize)]
pub struct LoggerConfig {
    // 日志级别
    #[serde(rename = "level")]
    pub level: String,
    // 日志路径
    #[serde(rename = "log_path")]
    pub path: String,
    // 日志文件名
    #[serde(rename = "log_file_name")]
    pub file_name: String,
}

#[allow(dead_code)]
impl LoggerConfig {
    pub fn new(level: String, path: String, file_name: String) -> Self {
        Self {
            level,
            path,
            file_name,
        }
    }

    pub fn load_from_file(path: &str) -> Result<Self, Box<dyn std::error::Error>> {
        let file = File::open(path)?;
        let reader = BufReader::new(file);
        let config: Self = serde_json::from_reader(reader)?;
        Ok(config)
    }

    pub fn save_to_file(path: &str, config: &Self) -> Result<(), Box<dyn std::error::Error>> {
        let file = File::create(path)?;
        let writer = BufWriter::new(file);
        serde_json::to_writer_pretty(writer, config)?;
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::LoggerConfig;
    use std::time::{SystemTime, UNIX_EPOCH};

    #[test]
    fn test_load_from_file() {
        let config = LoggerConfig::new(
            String::from("info"),
            String::from("logs"),
            String::from("core.log"),
        );
        let test_id = SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .expect("system time should be after unix epoch")
            .as_nanos();
        let path = format!("test_config_load_{}.json", test_id);
        LoggerConfig::save_to_file(&path, &config).unwrap();
        let loaded_config = LoggerConfig::load_from_file(&path).unwrap();
        assert_eq!(loaded_config.level, "info");
        assert_eq!(loaded_config.path, "logs");
        assert_eq!(loaded_config.file_name, "core.log");
        let _ = std::fs::remove_file(path);
    }
}
