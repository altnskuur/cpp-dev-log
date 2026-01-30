#include "tracker.hpp"
#include "memorylab.hpp"

int main(){
    enum class Operations{
        RetPtr_SegFault = 1,
        RetRef_UndefBehav,
        RetPtr_mustdel,
        RetRef_mustdel,
        Operations_max
    };

    std::cout << std::endl;
    std::cout << "-----Experiment Starts-----" << std::endl;
    std::cout << std::endl;

    Tracker *obj_experiment[static_cast<int>(Operations::Operations_max)];

    std::cout << "RetPtr_SegFault operation will start." << std::endl;
    obj_experiment[static_cast<int>(Operations::RetPtr_SegFault)]   = MemoryLab::retPtr_SegFault<Tracker>();
    std::cout << "RetPtr_SegFault operation is end." << std::endl;
    std::cout << std::endl;

    std::cout << "RetRef_UndefBehav operation will start." << std::endl;
    obj_experiment[static_cast<int>(Operations::RetRef_UndefBehav)] = &MemoryLab::retRef_UndefBehav<Tracker>();
    std::cout << "RetRef_UndefBehav operation is end." << std::endl;
    std::cout << std::endl;

    std::cout << "RetPtr_mustdel operation will start." << std::endl;
    obj_experiment[static_cast<int>(Operations::RetPtr_mustdel)]    = MemoryLab::retPtr_mustdel<Tracker>();
    std::cout << "RetPtr_mustdel operation is end." << std::endl;
    std::cout << std::endl;

    std::cout << "RetRef_mustdel operation will start." << std::endl;
    obj_experiment[static_cast<int>(Operations::RetRef_mustdel)]    = &MemoryLab::retRef_mustdel<Tracker>();
    std::cout << "RetRef_mustdel operation is end." << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "-----Checking Alive Statusses-----" << std::endl;
    std::cout << std::endl;
    obj_experiment[static_cast<int>(Operations::RetPtr_SegFault)]->check();
    obj_experiment[static_cast<int>(Operations::RetRef_UndefBehav)]->check();
    obj_experiment[static_cast<int>(Operations::RetPtr_mustdel)]->check();
    obj_experiment[static_cast<int>(Operations::RetRef_mustdel)]->check();

    return 0;
}
