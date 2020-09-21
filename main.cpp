// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "config.h"

#include <daw/json/daw_json_link.h>

#include <fstream>
#include <iostream>
#include <iterator>

int main( int argc, char **argv ) {
	if( argc <= 1 ) {
		std::cerr << "You must supply config.json file\n";
		exit( 1 );
	}
	auto config_file = std::fstream( argv[1] );
	if( not config_file ) {
		std::cerr << "Could not open '" << argv[1] << "'\n";
		exit( 1 );
	}
	std::string json_doc;
	std::copy( std::istreambuf_iterator<char>( config_file ),
	           std::istreambuf_iterator<char>( ),
	           std::back_inserter( json_doc ) );
	try {
		Config cfg = parse_config( json_doc );

		std::cout << "config application path: " << cfg.application_path << '\n';
		std::cout << "config application name: " << cfg.application_name << '\n';
		std::cout << "config version: " << cfg.version << '\n';
	} catch( daw::json::json_exception const &je ) {
		std::cerr << "Error parsing config file '" << argv[1]
		          << "': " << to_formatted_string( je ) << '\n';
		exit( 1 );
	}
	return 0;
}
