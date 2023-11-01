#include <computer.hpp>

#include <iostream>
#include <stdexcept>

int main() {
    std::string ip1 = "87.62.37.22";
    std::string local_ip = "192.168.1.37";
    std::string mac = "30:9C:23:1E:CD:B7";

    computer c1("pc", ip1, 22);
    std::cout << "has wol ? " << c1.has_wol() << '\n';
    std::cout << "is local ? " << c1.is_local() << '\n';

    computer c2("pc", local_ip, 22, mac);
    std::cout << "has wol ? " << c2.has_wol() << '\n';
    std::cout << "is local ? " << c2.is_local() << '\n';

    try {
        computer c3("pc", "1000.2", 22);
    } catch (const std::invalid_argument& error) {
        std::cout << "caught error saying : " << error.what() << '\n';
    }

    return 0;
}
