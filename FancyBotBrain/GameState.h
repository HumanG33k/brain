#pragma once

#include <mutex>
#include "WoWObjectManager.h"

class GameState
{
public:
	static GameState& Instance();

    std::unique_lock<std::mutex> GetLock();

	~GameState();

	void Update();

    bool GetIsInGame() const;

    WoWObjectManager& ObjectManager();

private:
	GameState();

    void UpdateInGame();

private:
	bool mIsInGame;
    bool mFirstTick;
    uint64_t mTickCount;
    WoWObjectManager mObjectManager;
    std::mutex mMutex;
};