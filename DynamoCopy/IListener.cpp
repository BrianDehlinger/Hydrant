#pragma once
#include "IListener.h"

void DummyListener::on_message(const std::string& message, I_Server *const server) {
	printf("%s", "Message received");
}
