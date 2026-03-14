mod logger;

pub use logger::logger::Logger;
pub use logger::api::*;
pub fn add(left: u64, right: u64) -> u64 {
    left + right
}
