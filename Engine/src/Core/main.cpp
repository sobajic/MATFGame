#include "Logger/Logger.h"
#include "Core/Application.h"

int main(int argc, char* args[])
{
    Engine::Logger::Init();
    LOG_INFO("Logger initialized!");


    // TODO Create Application and init
    
    // TODO Run Application

    // TODO Exit properly

    return 0;
}