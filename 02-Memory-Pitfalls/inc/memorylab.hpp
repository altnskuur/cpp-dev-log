/* memorylab.hpp */
#pragma once

namespace MemoryLab{

    template<typename T>
    T* retPtr_SegFault(){
        T l_foo{};
        T* p_foo;
        p_foo = &l_foo;
        return p_foo;
    }

    template<typename T>
    T& retRef_UndefBehav(){
        T l_foo{};
        T* p_foo;
        p_foo = &l_foo;
        return *p_foo;
    }

    template<typename T>
    T* retPtr_mustdel(){
        T* p_foo = new T();
        return p_foo;
    }

    template<typename T>
    T& retRef_mustdel(){
        T* p_foo = new T();
        return *p_foo;
    }
}
