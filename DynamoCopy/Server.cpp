#include "Server.h"

TCPServer::TCPServer(int port) {
	this->listening_port = port;
}

void TCPServer::addListener(std::shared_ptr<IListener> listener) 
{
	this->listeners.insert(listener);
}

void TCPServer::removeListener(std::shared_ptr<IListener> listener)
{
	this->listeners.erase(listener);
}

void TCPServer::notify(const std::string &message) {
	for (auto&& listener : this->listeners) {
		// Potential memory leak??? We give a pointer to the object and because it's a copy. What really happens?
		listener->on_message(message, this);
	}
}

void TCPServer::start() {
	const std::string& message = "TCP Server Start";
	this->notify(message);
}

void TCPServer::stop() {
	const std::string& message = "Server Stopped";
	this->notify(message);
}







