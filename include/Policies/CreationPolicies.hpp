#pragma once

// Создание через new
template <typename T>
struct CreateUsingNew {
    static T* Create() { return new T(); }
    static void Destroy(T* p) { delete p; }
};

// Создание через статический буфер (не для многопоточности!)
template <typename T, size_t Size = sizeof(T)>
struct CreateStatic {
    static T* Create() {
        static char buffer[Size];
        return new (buffer) T();
    }
    static void Destroy(T* p) { p->~T(); }
};