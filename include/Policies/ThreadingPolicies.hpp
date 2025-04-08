#pragma once
#include "Mutex.hpp"

// Без потокобезопасности
template <typename T>
struct SingleThreaded {
    struct Lock { Lock() {} }; // Пустая заглушка
    using MutexType = void;
};

// С использованием мьютекса (Class-Level Lock)
template <typename T>
struct ClassLevelLockable {
    using MutexType = Mutex;
    static MutexType& GetMutex() {
        static MutexType mtx;
        return mtx;
    }
    struct Lock {
        Lock() { ClassLevelLockable<T>::GetMutex().Lock(); }
        ~Lock() { ClassLevelLockable<T>::GetMutex().Unlock(); }
    };
};