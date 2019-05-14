/*
    This file is part of BlueFramework, a simple 3D engine.
    Copyright (c) 2019 Technical University of Munich
    Chair of Computational Modeling and Simulation.

    BlueFramework is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License Version 3
    as published by the Free Software Foundation.

    BlueFramework is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "BlueFramework/Core/assert.h"

#ifdef _WIN32
#include <Windows.h> // root of all evil
#endif

BLUEFRAMEWORK_CORE_NAMESPACE_BEGIN

bool isDebuggerConnected() {
#ifdef _WIN32	
    return IsDebuggerPresent() == 1;
#else
    return false;
#endif
}

BLUEFRAMEWORK_CORE_NAMESPACE_END
