#pragma once

// Rendering and Dimensions
namespace RenderConfig {
    constexpr int kTileSize = 40;          // Size of a single grid tile
    constexpr int kPlayerSize = 30;        // Size of the player
    constexpr int kBulletSize = 10;        // Size of bullets
    constexpr int kWindowWidth = 800;      // Default game window width
    constexpr int kWindowHeight = 600;     // Default game window height
}

// Player Configuration
namespace PlayerConfig {
    constexpr int kDefaultHealth = 100;    // Default health for a player
    constexpr int kNoGameId = -1;          // Indicates no game is assigned
    constexpr int kNoLobbyId = -1;         // Indicates no lobby is assigned
    constexpr float kDefaultPositionX = 0.0f; // Default X position
    constexpr float kDefaultPositionY = 0.0f; // Default Y position
    constexpr float kDefaultDirectionX = 0.0f; // Default X direction
    constexpr float kDefaultDirectionY = 0.0f; // Default Y direction
}

// Timing and Updates
namespace TimingConfig {
    constexpr int kGameLoopIntervalMs = 64; // Game loop interval (milliseconds)
}