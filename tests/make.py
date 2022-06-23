#!/usr/bin/env python3

import sys
import licant
from licant.cxx_modules import application
from licant.modules import submodule, module
from licant.libs import include

application("runtests",
	sources = [
		"*.cpp",
		"../src/Workspace.cpp",
		"../src/MainWindow.cpp",
	],

	#cxxstd="c++20",
	ccstd="c11",
	include_paths = [".", "../src"],

	libs=["igris", "nos", "crow", "rabbit", "ralgo", "Qt5Core", "Qt5Widgets", "Qt5Gui", "Qt5OpenGL"],

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
		"../src/MainWindow.h", 
		"../src/View.h", 
	],

)

licant.ex("runtests")
