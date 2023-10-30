#include <utils.hpp>
#include <iostream>

int main() {
    std::vector<std::string> truc = string_utils::split("ceci est un test", " ");
    for (std::string s : truc) {
        std::cout << s << " retour à la ligne" << '\n';
    }
    std::string ip1 = "87.62.37.22";
    std::cout << ip1 << " : " << ip_handling::validate_ip(ip1) << '\n';
    std::string ip2 = "256.144444.37.22.201";
    std::cout << ip2 << " : " << ip_handling::validate_ip(ip2) << '\n';
    std::string ip3 = "10.37.22";
    std::cout << ip3 << " : " << ip_handling::validate_ip(ip3) << '\n';
    return 0;
}
