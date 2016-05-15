#pragma once

#include <mutex>
#include "json.hpp"
#include "MerchantPane.h"
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

    nlohmann::json ToJson() const;

private:
	GameState();

    void UpdateInGame();

private:
	bool mIsInGame;
    bool mFirstTick;
    uint64_t mTickCount;
    std::mutex mMutex;

    WoWObjectManager mObjectManager;
    MerchantPane mMerchantPane;
};
