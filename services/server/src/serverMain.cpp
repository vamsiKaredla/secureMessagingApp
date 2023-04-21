#include "server.hpp"
#include <thread>

// using namespace v1_0::secureMessageTransfer;

int main() {

   // Initialization and deinitialization.
    log4cplus::Initializer initializer;

    log4cplus::BasicConfigurator config;
    config.configure();

    log4cplus::Logger logger = log4cplus::Logger::getInstance(
        LOG4CPLUS_TEXT("main"));
    LOG4CPLUS_WARN(logger, LOG4CPLUS_TEXT("Hello, World!"));

  // pointer to the runtime enviornment
  std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

  // Make shared pointer of our stub implementation
  std::shared_ptr<Server> server = std::make_shared<Server>();

  // register service with runtime
  runtime->registerService("local", "test", server);
  while (true) {
    std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(30));
  }
  return 0;
}