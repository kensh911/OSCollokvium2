# 🏗️ Singleton Design Pattern with Orthogonal Policies

## 📋 Описание

Реализация мощного Singleton паттерна на основе ортогональных стратегий из книги Александреску "Modern C++", глава 6. Проект включает различные политики создания, времени жизни и многопоточной синхронизации.

## ✨ Функционал

- 🔧 **CreationPolicies** - различные стратегии создания объектов
- ⏱️ **LifetimePolicies** - управление временем жизни singleton
- 🧵 **ThreadingPolicies** - политики синхронизации в многопоточной среде
- 🔒 **Mutex** - механизмы блокировки для thread-safety
- 🎯 **SingletonHolder** - основной template класс для singleton

## 🚀 Сборка и запуск

### Требования:
- C++17 или выше
- CMake 3.10+
- Поддержка многопоточности

### Компиляция:
```bash
mkdir build
cd build
cmake ..
make
