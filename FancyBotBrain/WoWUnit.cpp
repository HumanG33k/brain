#include "WoWUnit.h"

#include "WowOffsets.h"

WoWUnit WoWUnit::Read(void* pObject)
{
    WoWUnit unit;
    Read(&unit, pObject);
    return unit;
}

void WoWUnit::Read(WoWUnit* pUnit, void* pObject)
{
    WoWObject::Read(pUnit, pObject);
    auto pDescriptor = GetDataPointer(pObject);
    ReadOffsetInto(AddOffset(pDescriptor, DATA_HEALTH), &pUnit->mHealth);
    ReadOffsetInto(AddOffset(pDescriptor, DATA_MAX_HEALTH), &pUnit->mMaxHealth);
    ReadOffsetInto(AddOffset(pDescriptor, DATA_FACTION_ID), &pUnit->mFactionId);
    ReadOffsetInto(AddOffset(pDescriptor, DATA_DYNAMIC_FLAGS), &pUnit->mDynamicFlags);
    ReadOffsetInto(AddOffset(pDescriptor, DATA_MOVEMENT_FLAGS), &pUnit->mMovementState);
    ReadOffsetInto(AddOffset(pDescriptor, DATA_MANA), &pUnit->mMana);
    ReadOffsetInto(AddOffset(pDescriptor, DATA_MAX_MANA), &pUnit->mMaxMana);
    ReadOffsetInto(AddOffset(pDescriptor, DATA_RAGE), &pUnit->mRage);
    ReadOffsetInto(AddOffset(pDescriptor, DATA_TARGET_GUID), &pUnit->mTargetGUID);
}

bool WoWUnit::IsAlive() const
{
    return mHealth > 0;
}

bool WoWUnit::IsLootable() const
{
    return (mDynamicFlags & 0x1) == 0x1;
}

uint32_t WoWUnit::GetFaction() const
{
    return mFactionId;
}
