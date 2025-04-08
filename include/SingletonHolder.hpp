#pragma once
#include "Policies/CreationPolicies.hpp"
#include "Policies/LifetimePolicies.hpp"
#include "Policies/ThreadingPolicies.hpp"

template <
    typename T,
    template <class> class CreationPolicy = CreateUsingNew,
    template <class> class LifetimePolicy = DefaultLifetime,
    template <class> class ThreadingPolicy = ClassLevelLockable
>
class SingletonHolder {
public:
    SingletonHolder() = delete;
    SingletonHolder(const SingletonHolder&) = delete;
    SingletonHolder& operator=(const SingletonHolder&) = delete;

    static T& Instance() {
        if (!pInstance_) {
            typename ThreadingPolicy<T>::Lock guard; // Блокировка
            if (!pInstance_) {
                pInstance_ = CreationPolicy<T>::Create();
                LifetimePolicy<T>::ScheduleDestruction(&DestroySingleton);
            }
        }
        return *pInstance_;
    }

private:
    static void DestroySingleton() {
        CreationPolicy<T>::Destroy(pInstance_);
        pInstance_ = nullptr;
    }

    static T* pInstance_;
};

template <typename T, template <class> class CP, template <class> class LP, template <class> class TP>
T* SingletonHolder<T, CP, LP, TP>::pInstance_ = nullptr;