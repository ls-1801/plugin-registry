//
// Created by ls on 5/7/24.
//

#include "common.h"

class MyGreeter final : public GreetingsPlugin
{
    [[nodiscard]] std::string greet() const override
    {
        return "Hello Friend";
    }
};

static Registry<GreetingsPlugin>::Hook<MyGreeter> hook;
