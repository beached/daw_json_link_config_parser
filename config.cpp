// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "config_json.h"

#include <string_view>

Config parse_config( std::string_view json_document ) {
	// NO Comments return daw::json::from_json<Config>( json_document );
	// C++ Sytle Comments 
	return daw::json::from_json<Config, daw::json::CppCommentSkippingPolicyChecked>( json_document );
}
