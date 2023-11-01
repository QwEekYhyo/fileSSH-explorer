#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <string>

class computer {
    public:
        computer(std::string hostname, std::string ip_address, unsigned int port, std::string mac_address = "");
        void add_wol(const std::string mac_address);

        const bool& is_local();
        const bool& has_wol();

    protected:
        std::string m_hostname;
        std::string m_ip_addr;
        unsigned int m_port;

        bool m_is_local;

        bool m_has_wol{false};
        std::string m_mac_addr;
};

#endif
