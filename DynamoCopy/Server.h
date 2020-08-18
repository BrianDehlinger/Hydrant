#pragma once
#include <string>
#include <set>
#include "IListener.h"
#include <memory>

class I_Server
{
public:
	I_Server() {}
	virtual ~I_Server() {};
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void addListener(std::shared_ptr<IListener> listener) = 0;
	virtual void removeListener(std::shared_ptr<IListener> listener) = 0;
	virtual void notify(const std::string& message) = 0;
private:
	int listening_port;
	std::set<std::unique_ptr<IListener>> listeners;
};

class TCPServer : public I_Server {
public:
	TCPServer(int port);
	~TCPServer() {}
	void start() override;
	void stop() override;
	void addListener(std::shared_ptr<IListener> listener) override;
	void removeListener(std::shared_ptr<IListener> listener) override;
	void notify(const std::string& message) override;
private:
	int listening_port = -1;
	std::set<std::shared_ptr<IListener>> listeners;
};

