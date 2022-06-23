#ifndef OBSERVER_VIEW_ADAPTOR_H
#define OBSERVER_VIEW_ADAPTOR_H

#include <Fiber.h>

class Workspace;

class ViewAdaptor 
{
    Workspace * ws;

public:
    ViewAdaptor(Workspace * ws) : ws(ws) {}
    virtual ~ViewAdaptor() = default;
};

class ChartViewAdaptor 
{
    std::vector<FiberID> fiber_id_list;
    std::shared_ptr<Fiber> x_fiber;
    
    void set_fibers(FiberID xaxis_id, std::vector<FiberID> yaxis_id) 
    {
        //x_fiber = ws->get_fiber(xaxis_id);

        for (auto ax: yaxis_id) 
        {

        }
    }

    virtual ~ChartViewAdaptor() = default;
};

#endif