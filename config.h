// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <filesystem>
#include <string>
#include <string_view>

struct Config {
	std::filesystem::path application_path;
	std::string application_name;
	unsigned version;
};

Config parse_config( std::string_view json_document );
