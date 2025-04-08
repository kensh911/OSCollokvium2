#pragma once
#include <mutex>

class Mutex {
public:
    void Lock() { mtx.lock(); }
    void Unlock() { mtx.unlock(); }

private:
    std::mutex mtx;
};