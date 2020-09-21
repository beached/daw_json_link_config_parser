// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include "config.h"

#include <daw/json/daw_json_link.h>

#include <tuple>

namespace daw::json {
	template<>
	struct json_data_contract<Config> {
		static constexpr char const application_path[] = "application_path";
		static constexpr char const application_name[] = "application_name";
		static constexpr char const version[] = "version";
		using type = json_member_list<json_string<application_path>,
		                              json_string<application_name>,
		                              json_number<version, unsigned>>;

		static inline auto to_json_data( Config const &value ) {
			return std::forward_as_tuple( value.application_path,
			                              value.application_path, value.version );
		}
	};
} // namespace daw::json
