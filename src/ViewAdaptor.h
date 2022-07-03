#ifndef OBSERVER_VIEW_ADAPTOR_H
#define OBSERVER_VIEW_ADAPTOR_H

#include <Fiber.h>
#include <DataGenerator.h>

class Workspace;

class ViewAdaptor 
{
    Workspace * ws;

public:
    ViewAdaptor(Workspace * ws) : ws(ws) {}
    virtual ~ViewAdaptor() = default;
};

class ChartViewAdaptor : public ViewAdaptor
{
    //std::vector<FiberID> fiber_id_list;
    std::shared_ptr<Signal> x_fiber;
    std::list<std::shared_ptr<Signal>> y_fiber_list;

public:
    ChartViewAdaptor(Workspace * ws) : ViewAdaptor(ws) {}
    ChartViewAdaptor() = default;
    
    /*void set_fibers(FiberID xaxis_id, std::vector<FiberID> yaxis_id) 
    {
        //x_fiber = ws->get_fiber(xaxis_id);

        for (auto ax: yaxis_id) 
        {

        }
    }*/

    void set_discrete_time_mode(std::list<std::shared_ptr<Signal>> data_fibers, double delta) 
    {
        y_fiber_list = data_fibers;
    }
    

    virtual ~ChartViewAdaptor() = default;
};

#endif