/* tracker.hpp */
#pragma once
#include <iostream>

class Tracker{

    private:
        inline static int s_objCounter{0};
        int m_id{0};

    public:
        Tracker(){
            m_id = ++s_objCounter;
            std::cout << "[+] Tracker: " << m_id << " created." << std::endl;
        };

        ~Tracker(){
            std::cout << "[-] Tracker: " << m_id << " deleted." << std::endl;
            m_id = 0;
        };

        void check(){
            if(0 != m_id){
                std::cout << "[!] Tracker: " << m_id << " still alive." << std::endl;
            } else {
                std::cout << "id can not find!" << std::endl;
            }
        }
};
