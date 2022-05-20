#include <ThemeController.h>
#include <crow/address.h>
#include <nos/print.h>

ThemeController::ThemeController(QObject *parent) : QObject(parent)
{
    start_crow_tower();
    init_subscription();
}

void ThemeController::init_subscription()
{
    requestor.init(crow::crowker_address(), "crowker/control");
}

void ThemeController::start_crow_tower()
{
    crow::start_spin();
}

std::vector<std::string> ThemeController::get_theme_list()
{
    std::vector<std::string> theme_list;
    auto responce = requestor.request("theme-names");
    nos::println(responce->data());
    return theme_list;
}

ThemeController::~ThemeController()
{
    crow::stop_spin();
}