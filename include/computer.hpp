#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <string>

class computer {
    public:
        computer();
        void add_wol(const std::string mac_addr);

    private:
        std::string m_ip_addr;
        int m_port;
        bool m_is_local;
        bool m_has_wol;
        std::string m_mac_addr;
};

#endif
