#ifndef OBSERVER_VIEW_H
#define OBSERVER_VIEW_H

#include <QtWidgets>
#include <rabbit/chart/qtchart.h>

class View : public QWidget 
{
    Q_OBJECT

public:
    View()
    {}
};

class ChartView  : public View
{
    Q_OBJECT

public:
    rabbit::qtchart * chart;
    QVBoxLayout * layout;

public:
    ChartView() : View() 
    {
        chart = new rabbit::qtchart;
        layout = new QVBoxLayout;
        layout->addWidget(chart);
        setLayout(layout);
        setMinimumSize(200, 200);
    }
};

#endif