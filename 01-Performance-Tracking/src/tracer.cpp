#include "Tracer.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>

static const std::string g_LogFileName = "performance.txt";

struct Tracer::Impl{

    std::string funcName;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

    Impl(const std::string& name) : funcName(name), start(std::chrono::high_resolution_clock::now()){ }
};

Tracer::Tracer(const std::string& funcName) : pImpl(std::make_unique<Impl>(funcName)){ }

Tracer::~Tracer(){
    auto end        = std::chrono::high_resolution_clock::now();
    auto duration   = std::chrono::duration_cast<std::chrono::microseconds>(end - pImpl->start).count();

    std::ofstream logOutFile(g_LogFileName, std::ios::app);
    logOutFile << "[" << pImpl->funcName << "] " << duration << " us" << std::endl;
}
