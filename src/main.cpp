#include <iostream>
#include "SingletonHolder.hpp"

class DatabaseManager {
public:
    void Connect() { std::cout << "Connected to DB!\n"; }
    ~DatabaseManager() { std::cout << "DB connection closed.\n"; }
};

int main() {
    // Определяем тип Singleton с нужными стратегиями
    using DBSingleton = SingletonHolder<
        DatabaseManager,
        CreateUsingNew,
        DefaultLifetime,
        ClassLevelLockable
    >;

    // Использование
    DBSingleton::Instance().Connect();

    return 0;
}