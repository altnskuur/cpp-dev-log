#include "Tracer.hpp"
#include <thread>

void agirIsYapanFonksiyon(){

    TRACE_FUNC(); // İşte bu kadar! Fonksiyon bitince otomatik loglayacak.
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main(){

    agirIsYapanFonksiyon();
    return 0;
}
