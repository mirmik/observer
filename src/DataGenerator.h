#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include <ralgo/linalg/vecops.h>
#include <igris/container/array_view.h>
#include <Fiber.h>

class Signal
{
public:
    virtual igris::array_view<float> data_betwen_indexes(size_t begin, size_t end) = 0;
};

class DiscreteTimeSignal : public Signal 
{
    ralgo::vector<float> data; // Заменить на циркулярный буффер.
    double delta;

public:
    DiscreteTimeSignal(double delta) : delta(delta) {}

    igris::array_view<float> data_betwen_indexes(size_t begin, size_t end) override
    {   
        data.resize(end-begin);
        for (size_t i = 0; i < end-begin; ++i) 
        {
            data[i] = (begin + i) * delta;
        }
        return {data.data(), data.size()};
    }
};

class FiberSignal : public Signal
{
    std::shared_ptr<Fiber> fiber;

public:
    igris::array_view<float> data_betwen_indexes(size_t begin, size_t end) override 
    {
        return {{}, {}};
    }
};

#endif