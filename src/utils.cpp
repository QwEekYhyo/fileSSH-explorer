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

    bool validate_mac(const std::string mac_addr) {
        std::vector<std::string> parsed = string_utils::split(mac_addr, ":");
        if (parsed.size() != 6) {
            return false;
        }
        int byte;
        for (std::string byte_string : parsed) {
            std::istringstream(byte_string) >> std::hex >> byte;
            if (byte < 0 || byte > 255) {
                return false;
            }
        }
        return true;
    }

    // it is assumed ip_addr has been validated
    bool check_if_local(const std::string ip_addr) {
        std::vector<std::string> parsed = string_utils::split(ip_addr, ".");
        std::string first_byte = parsed.at(0);
        if (first_byte == "10") return true;
        else if (first_byte == "172") {
            int second_byte = std::stoi(parsed.at(1));
            return second_byte >= 16 && second_byte <= 31;
        }
        return first_byte == "192" && parsed.at(1) == "168";
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
