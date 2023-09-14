#pragma once

#include "RE/Starfield.h"
#include "SFSE/SFSE.h"

#include "RE/P/PlayerCamera.h"

#include <xbyak/xbyak.h>
#include <ClibUtil/singleton.hpp>

#ifdef NDEBUG
#	include <spdlog/sinks/basic_file_sink.h>
#else
#	include <spdlog/sinks/msvc_sink.h>
#endif

namespace logger = SFSE::log;
using namespace std::literals;
using namespace clib_util::singleton;

namespace stl
{
	using namespace SFSE::stl;
}

#define DLLEXPORT extern "C" [[maybe_unused]] __declspec(dllexport)

#include "Version.h"
