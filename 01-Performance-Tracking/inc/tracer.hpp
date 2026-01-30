#pragma once
#include <memory>
#include <string>

#if defined(__GNUC__) || defined(__clang__)
    #define TRACE_FUNC_NAME __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
    #define TRACE_FUNC_NAME __FUNCSIG__
#else
    #define TRACE_FUNC_NAME __func__
#endif

class Tracer{

    public:
    Tracer(const std::string& funcName);
    ~Tracer(void); // must defined in .cpp file because of the ptr var in private

    private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;
};

#define TRACE_FUNC() Tracer tracer_at_line_##__LINE__(TRACE_FUNC_NAME)
