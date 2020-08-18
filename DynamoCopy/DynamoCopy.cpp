// DynamoCopy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include "Server.h"
#include "IListener.h"
#include <fstream>


int main()
{
	auto listener = std::make_shared<DummyListener>();
	auto server = std::make_unique<TCPServer>(50);
	server->addListener(listener);
	printf("%d\n", listener.use_count());
	server->removeListener(listener);
	printf("%d\n", listener.use_count());
	std::ifstream in_file;
	std::string filename;
	std::cin >> filename;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
