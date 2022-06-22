#!/usr/bin/env python3

import sys
import licant
from licant.cxx_modules import application
from licant.modules import submodule, module
from licant.libs import include

application("runtests",
	sources = [
		"*.cpp",
		"../src/Workspace.cpp"
	],

	cxxstd="c++20",
	ccstd="c11",
	cxx_flags = "-g -Werror=all -Werror=extra -Weffc++",
	cc_flags = "-g -Werror=all -Werror=extra",

	include_paths = [".", "../src"],
	libs = ["igris"]
)

licant.ex("runtests")
