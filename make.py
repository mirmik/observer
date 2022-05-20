#!/usr/bin/env python3

import licant

licant.cxx_application("observer",
	sources = [
		"src/main.cpp", 
		"src/MainWindow.cpp", 
		"src/Observer.cpp", 
		"src/ThemeController.cpp"
	],
	libs=["igris", "nos", "crow", "Qt5Core", "Qt5Widgets", "Qt5Charts", "Qt5Gui"],
	include_paths = ["src", "."],

	cc_flags = "-DQT_CHARTS_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -g -O0 " 
	"-I/usr/include/x86_64-linux-gnu/qt5/QtCharts -I/usr/include/x86_64-linux-gnu/qt5 "
	"-I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5 "
	"-I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5 "
	"-I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/x86_64-linux-gnu/qt5 "
	"-fPIC -pedantic -Werror=all -Werror=extra",

	ld_flags = "-DQT_CHARTS_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -g -O0 " 
	"-I/usr/include/x86_64-linux-gnu/qt5/QtCharts -I/usr/include/x86_64-linux-gnu/qt5 "
	"-I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5 "
	"-I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5 "
	"-I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/x86_64-linux-gnu/qt5 "
	"-fPIC -pedantic -Werror=all",

	cxx_flags = "-DQT_CHARTS_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -g -O0 " 
	"-I/usr/include/x86_64-linux-gnu/qt5/QtCharts -I/usr/include/x86_64-linux-gnu/qt5 "
	"-I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5 "
	"-I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5 "
	"-I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/x86_64-linux-gnu/qt5 "
	"-fPIC -pedantic -Werror=all",

	qt_moc = [
		"src/MainWindow.h", 
		"src/Observer.h", 
		"src/ThemeController.h"
	],
)

licant.ex("observer")