#include <utils.hpp>
#include <iostream>

int main() {
    std::vector<std::string> truc = string_utils::split("ceci est un test", " ");
    for (std::string s : truc) {
        std::cout << s << " retour à la ligne" << '\n';
    }
    std::string ip1 = "87.62.37.22";
    std::cout << ip1 << " : " << ip_handling::validate_ip(ip1) << '\n';
    std::cout << ip1 << " is local ? " << ip_handling::check_if_local(ip1) << '\n';
    std::string ip2 = "256.144444.37.22.201";
    std::cout << ip2 << " : " << ip_handling::validate_ip(ip2) << '\n';
    std::string ip3 = "10.37.22";
    std::cout << ip3 << " : " << ip_handling::validate_ip(ip3) << '\n';
    std::string mac = "30:9C:23:1E:CD:B7";
    std::cout << mac << " : " << ip_handling::validate_mac(mac) << '\n';
    mac = "30:9C:2A3:1E:CD:B7";
    std::cout << mac << " : " << ip_handling::validate_mac(mac) << '\n';
    mac = "30:9C:CD:B7";
    std::cout << mac << " : " << ip_handling::validate_mac(mac) << '\n';
    mac = "30:9C:23:1E:CD:B7:FF:FF";
    std::cout << mac << " : " << ip_handling::validate_mac(mac) << '\n';
    ip1 = "192.10.0.0";
    std::cout << ip1 << " is local ? " << ip_handling::check_if_local(ip1) << '\n';
    ip1 = "10.10.255.0";
    std::cout << ip1 << " is local ? " << ip_handling::check_if_local(ip1) << '\n';
    ip1 = "192.168.1.37";
    std::cout << ip1 << " is local ? " << ip_handling::check_if_local(ip1) << '\n';
    ip1 = "172.168.1.37";
    std::cout << ip1 << " is local ? " << ip_handling::check_if_local(ip1) << '\n';
    ip1 = "172.31.1.37";
    std::cout << ip1 << " is local ? " << ip_handling::check_if_local(ip1) << '\n';
    return 0;
}
