//
// Created by ls on 5/7/24.
//

#ifndef COMMON_H
#define COMMON_H

#include <cassert>
#include <optional>
#include <memory>

#define API __attribute__((visibility("default")))

class GreetingsPlugin
{
public:
    virtual ~GreetingsPlugin() = default;

    [[nodiscard]] virtual std::string greet() const = 0;
};

template <typename Base>
class Registry
{
    static std::unique_ptr<Base> items API;

public:
    static const Base& verify()
    {
        assert(items && "Plugin was not initialized");
        return *items;
    }

    template <std::derived_from<Base> Derived>
        requires std::default_initializable<Derived>
    class Hook
    {
        static std::unique_ptr<Base> make()
        {
            return std::make_unique<Derived>();
        }

    public:
        Hook()
        {
            items = make();
        }
    };
};

template <typename Base>
std::unique_ptr<Base> Registry<Base>::items = nullptr;

#endif //COMMON_H
