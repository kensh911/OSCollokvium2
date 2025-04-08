#pragma once

// Удаление при завершении программы (atexit)
template <typename T>
struct DefaultLifetime {
    static void ScheduleDestruction(void (*func)()) {
        std::atexit(func);
    }
};

// Не удалять автоматически (пользователь управляет вручную)
template <typename T>
struct NoDestroy {
    static void ScheduleDestruction(void (*)()) {}
};