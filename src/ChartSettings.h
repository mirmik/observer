#ifndef OBSERVER_CHART_SETTINGS_H
#define OBSERVER_CHART_SETTINGS_H

#include <stdint.h>

class ChartSettings 
{
    FiberID x_axis_id;
    std::vector<FiberID> y_axes_id;
};

#endif