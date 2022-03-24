#ifndef __CLASS__CONRETE_GAME_STATE__
#define __CLASS__CONRETE_GAME_STATE__
#include <iostream>
#include "gameManager.h"
#include "cell.h"

class GameManager;

class GameState{
    public:
    virtual void enter(GameManager* gamemanager) = 0;
    virtual void process(GameManager* gamemanager) = 0;
    void exit(GameManager* gamemanager);
    virtual ~GameState() {};
};

class Init : public GameState{
    public:
        void enter(GameManager* gamemanager){}
        void process(GameManager* gamemanager);
        void exit(GameManager* gamemanager){}
        static GameState& getInstance();

    private:
        Init() {}
        Init(const Init& other);
        Init& operator=(const Init& other);
};

class Player1Turn : public GameState{
    public:
        void enter(GameManager* gamemanager){}
        void process(GameManager* gamemanager);
        void exit(GameManager* gamemanager){}
        static GameState& getInstance();

    private:
        Player1Turn() {}
        Player1Turn(const Player1Turn& other);
        Player1Turn& operator=(const Player1Turn& other);
};
class Player2Turn : public GameState{
    public:
        void enter(GameManager* gamemanager){}
        void process(GameManager* gamemanager);
        void exit(GameManager* gamemanager){}
        static GameState& getInstance();

    private:
        Player2Turn() {}
        Player2Turn(const Player2Turn& other);
        Player2Turn& operator=(const Player2Turn& other);
};
class Victory : public GameState{
    public:
        void enter(GameManager* gamemanager){}
        void process(GameManager* gamemanager);
        void exit(GameManager* gamemanager);
        static GameState& getInstance();

    private:
        Victory() {}
        Victory(const Victory& other);
        Victory& operator=(const Victory& other);
};

#endif//__CLASS__CONRETE_GAME_STATE__

