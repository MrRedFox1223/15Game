#include "gameinitializator.h"

GameInitializator::GameInitializator() {}

void GameInitializator::initialize() {}

void GameInitializator::initializeMe(GameInitializator * init)
{
    init->initialize();
}
