#!/usr/bin/env python3

import licant

licant.include("rabbit")

licant.cxx_application("observer",
	sources = [
		"src/*.cpp",
	],
	mdepends = ["rabbit"],

	libs=["igris", "nos", "crow", "Qt5Core", "Qt5Widgets", "Qt5Charts", "Qt5Gui", "Qt5OpenGL"],
	include_paths = ["src", "."],

	cc_flags = " -g -O0 -fPIC -pedantic -Werror=all -Werror=extra",

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
	"-I/usr/include/x86_64-linux-gnu/qt5/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt5 "
	"-fPIC -pedantic -Werror=all",

	qt_moc = [
		"src/MainWindow.h", 
		"src/Observer.h", 
		"src/ThemeController.h"
	],
)

licant.ex("observer")