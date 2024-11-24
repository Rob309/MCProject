#pragma once

namespace WeaponConfig
{
    constexpr float kBasicSpeed = 3;
    constexpr int kBasicDamage = 10;
    constexpr float kBasicFireRate = 0.1;  //fire rate of 1 means 1 shot every 1s. Fire rate of 0.1 means 10 shots every 1s
    constexpr float kMaxBasicBullets = 100;

    constexpr float kSpeedPowerupIncreasePercent = 100;
    constexpr float kDamagePowerupIncreasePercent = 100;

    constexpr float frameTime = 1.0f / 60.0f;  //TODO probably better to use DEFINE instead of constexpr,check later.ALSO MOVE IT TO ANOTHER CONSTANT VALUES FILE
}