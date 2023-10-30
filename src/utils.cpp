#include <utils.hpp>

namespace ip_handling {
    bool validate_ip(const std::string ip_addr) {
        std::vector<std::string> parsed = string_utils::split(ip_addr, ".");
        if (parsed.size() != 4) {
            return false;
        }
        // TODO exception handling of std::invalid_argument
        for (std::string byte_string : parsed) {
            int byte = std::stoi(byte_string);
            if (byte < 0 || byte > 255) {
                return false;
            }
        }
        return true;
    }
}

namespace string_utils {
    std::vector<std::string> split(std::string str, std::string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> output;

        while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos) {
            token = str.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            output.push_back (token);
        }

        output.push_back (str.substr (pos_start));
        return output;
    }
}
