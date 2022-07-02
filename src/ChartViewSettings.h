#ifndef OBSERVER_CHART_VIEW_SETTINGS_H
#define OBSERVER_CHART_VIEW_SETTINGS_H

#include <QtWidgets>
#include <Fiber.h>
#include <ralgo/linalg/vecops.h>

class ChartViewSettings : public QDialog
{
    Q_OBJECT

    QListWidget * wdg;
    QVBoxLayout * layout;

public:
    ChartViewSettings(std::vector<std::shared_ptr<Fiber>> fibers)
    {
        wdg = new QListWidget;
        auto vec = ralgo::vecops::transform<std::vector<std::string>>(fibers,
            [](const std::shared_ptr<Fiber>& ref)
        {
                auto& fiber = *ref;
                return fiber.name();
        });

        QStringList lst;
        for (auto& a : vec) 
        {
            lst << QString::fromStdString(a);
        }

        wdg->addItems(lst);
        layout = new QVBoxLayout;
        layout->addWidget(wdg);
        setLayout(layout);
    }
};

#endif