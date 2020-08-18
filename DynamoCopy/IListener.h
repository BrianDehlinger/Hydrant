#pragma once
#include <string>


class I_Server;

class IListener
{
public:
	IListener() {}
	virtual ~IListener() {};
	virtual void on_message(const std::string &message, I_Server *const server) = 0;
};

class DummyListener : public IListener
{
public:
	DummyListener() {};
	~DummyListener() {};
	void on_message(const std::string& message, I_Server *const server) override;
};

