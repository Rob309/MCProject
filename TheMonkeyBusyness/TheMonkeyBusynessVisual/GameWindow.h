#pragma once
#include <QtWidgets/QWidget>
#include <QtCore/QPoint>
#include <QtCore/QTimer>
#include <QElapsedTimer>
#include <string>
#include <vector>
#include <cpr/cpr.h>
#include <crow/json.h>
#include "InputHandler.h" // For handling player input


using Position = std::pair<float, float>;
using Direction = std::pair<float, float>;

class GameWindow : public QWidget {
    Q_OBJECT
public:
    explicit GameWindow(int playerId, int gameId, const std::string& serverUrl, QWidget* parent = nullptr);

private:
    int playerId;                      // Player's unique ID
    int gameId;                        // Game's unique ID
    std::string serverUrl;             // Server URL for requests
    QPoint playerPosition;             // Current position of the player
    InputHandler playerInput;          // Handles user inputs (movement, shooting)
    QTimer* timer;                     // Timer for the game loop

    std::vector<std::vector<int>> map; // Local copy of the map (2D grid representation)
    std::vector<std::pair<Position, Direction>> bulletsCoordinates;
    int health;
    std::vector<Position> playersCoordinates;

    void fetchGameState();             // Fetch game state from the server
    void updateGameState(const crow::json::rvalue& jsonResponse); // Update local state based on server data
    void updatePlayerDirection();       // Update player movement locally
    void sendPlayerInputToServer();    // Send input data (movement, shooting) to the server

    void paintEvent(QPaintEvent* event) override; // Render the game window


    QElapsedTimer fpsTimer;  // Timer to measure FPS
    int frameCount = 0;      // Frame counter
    int currentFPS = 0;      // Calculated FPS
};
