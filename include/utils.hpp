#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

namespace ip_handling {
    bool validate_ip(const std::string ip_address);
}

namespace string_utils {
    std::vector<std::string> split(std::string string, std::string delimiter);
}

#endif
