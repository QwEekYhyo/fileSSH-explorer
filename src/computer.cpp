#include <computer.hpp>
#include <utils.hpp>

#include <stdexcept>

computer::computer(std::string hostname, std::string ip_addr, unsigned int port, std::string mac_addr) {
    m_hostname = hostname;
    if (!ip_handling::validate_ip(ip_addr)) throw std::invalid_argument("IP address is not valid");
    m_ip_addr = ip_addr;
    m_is_local = ip_handling::check_if_local(m_ip_addr);

    m_port = port;
    if (mac_addr != "") add_wol(mac_addr);
}

void computer::add_wol(const std::string mac_addr) {
    if (ip_handling::validate_mac(mac_addr)) {
        m_has_wol = true;
        m_mac_addr = mac_addr;
    } else {
        throw std::invalid_argument("MAC address is not valid");
    }
}

const bool& computer::is_local() {
    return m_is_local;
}

const bool& computer::has_wol() {
    return m_has_wol;
}
