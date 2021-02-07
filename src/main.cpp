#include <iostream>

#include "librespot_cpp.h"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "usage: librespot-app <username> <password>" << std::endl;
		return 0;
	}
	auto cfg = rs::core::config::session_config();
	auto cred = rs::core::authentication::with_password(argv[1], argv[2]);

	std::cout << "connecting..." << std::endl;

	try
	{
		auto session = rs::core::session::connect(cfg, cred);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}