use crate::logger::logger::Logger;
use std::ffi::{CStr};
use std::os::raw::c_char;

#[unsafe(no_mangle)]
pub extern "C" fn logger_init(config_file_path: *const c_char) -> bool {
    if config_file_path.is_null() {
        return false;
    }
    let c_str = unsafe {
        CStr::from_ptr(config_file_path)
    };

    let file_path = match c_str.to_str() {
        Ok(path) => path,
        Err(_) => return false,
    };
    Logger::init(file_path);
    true
}