#ifndef GAMEINITIALIZATOR_H
#define GAMEINITIALIZATOR_H

class GameInitializator
{
public:
    GameInitializator();

    virtual void initialize();
    void initializeMe(GameInitializator *init);
};

#endif // GAMEINITIALIZATOR_H
