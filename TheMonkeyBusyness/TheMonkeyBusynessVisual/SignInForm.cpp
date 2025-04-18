﻿#include "SignInForm.h"
#include "PlayWindow.h"
#include "Player.h"
#include "SessionManager.h"


SignInForm::SignInForm(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Sign In");
    setFixedSize(700, 700); // Setează dimensiunea fixă pentru fereastră

    // **Setează imaginea ca fundal**
    QString imagePath = QCoreApplication::applicationDirPath() + "/Images/background.jpg";
    QPixmap background(imagePath);
    if (!background.isNull()) {
        background = background.scaled(size(), Qt::KeepAspectRatioByExpanding);
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(background));
        setPalette(palette);
    }

    QVBoxLayout* layout = new QVBoxLayout(this);

    // Creează titlul
    QLabel* titleLabel = new QLabel("Sign In", this);
    QFont titleFont("Arial", 36, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: rgba(255, 223, 0, 255);");
    titleLabel->setAlignment(Qt::AlignCenter);

    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(2, 2);
    shadowEffect->setBlurRadius(10);
    shadowEffect->setColor(QColor(0, 0, 0, 150));
    titleLabel->setGraphicsEffect(shadowEffect);

    layout->addWidget(titleLabel);

    m_usernameLabel = new QLabel("Username:", this);
    m_usernameField = new QLineEdit(this);
    m_usernameField->setPlaceholderText("Enter your username"); // Adăugare placeholder

    m_passwordLabel = new QLabel("Password:", this);
    m_passwordField = new QLineEdit(this);
    m_passwordField->setEchoMode(QLineEdit::Password);
    m_passwordField->setPlaceholderText("Enter your password"); // Adăugare placeholder

    m_confirmPasswordLabel = new QLabel("Confirm Password:", this);
    m_confirmPasswordField = new QLineEdit(this);
    m_confirmPasswordField->setEchoMode(QLineEdit::Password);
    m_confirmPasswordField->setPlaceholderText("Confirm your password"); // Adăugare placeholder

    m_submitButton = new QPushButton("Submit", this);
    m_backButton = new QPushButton("Back", this);

    // Stilizare pentru câmpuri și butoane
    QString fieldStyle = R"(
        QLineEdit {
            background-color: rgba(255, 255, 255, 200);
            color: black;
            border: 2px solid black;
            border-radius: 10px;
            padding: 5px;
            font-size: 16px;
        }
        QPushButton {
            background-color: rgba(255, 255, 0, 200);
            color: black;
            font-size: 18px;
            font-weight: bold;
            border-radius: 10px;
            padding: 10px;
        }
        QPushButton:hover {
            background-color: rgba(255, 215, 0, 230);
        }
    )";
    m_usernameField->setStyleSheet(fieldStyle);
    m_passwordField->setStyleSheet(fieldStyle);
    m_confirmPasswordField->setStyleSheet(fieldStyle);
    m_submitButton->setStyleSheet(fieldStyle);
    m_backButton->setStyleSheet(fieldStyle);

    QString labelStyle = R"(
        QLabel {
            color: rgba(0, 0, 0, 255);
            font-size: 18px;
            font-weight: bold;
        }
    )";
    m_usernameLabel->setStyleSheet(labelStyle);
    m_passwordLabel->setStyleSheet(labelStyle);
    m_confirmPasswordLabel->setStyleSheet(labelStyle);

    m_usernameField->setFixedSize(300, 40);
    m_passwordField->setFixedSize(300, 40);
    m_confirmPasswordField->setFixedSize(300, 40);
    m_submitButton->setFixedSize(200, 50);
    m_backButton->setFixedSize(200, 50);

    layout->addWidget(m_usernameLabel, 0, Qt::AlignCenter);
    layout->addWidget(m_usernameField, 0, Qt::AlignCenter);
    layout->addWidget(m_passwordLabel, 0, Qt::AlignCenter);
    layout->addWidget(m_passwordField, 0, Qt::AlignCenter);
    layout->addWidget(m_confirmPasswordLabel, 0, Qt::AlignCenter);
    layout->addWidget(m_confirmPasswordField, 0, Qt::AlignCenter);
    layout->addWidget(m_submitButton, 0, Qt::AlignCenter);
    layout->addWidget(m_backButton, 0, Qt::AlignCenter);

    connect(m_backButton, &QPushButton::clicked, this, &SignInForm::BackRequested); // Emit semnalul backRequested

    disconnect(m_submitButton, nullptr, nullptr, nullptr);

    connect(m_submitButton, &QPushButton::clicked, [this]() {
        QString username = m_usernameField->text();
        QString password = m_passwordField->text();
        QString confirmPassword = m_confirmPasswordField->text();

        if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
            QMessageBox::warning(this, "Sign In Failed", "All fields must be filled!");
            return;
        }

        if (password != confirmPassword) {
            QMessageBox::warning(this, "Sign In Failed", "Passwords do not match!");
            return;
        }

        //std::string serverUrl = "http://localhost:8080"; // Adjust this to match your server's address
        std::string usernameStd = username.toUtf8().constData();
        std::string passwordStd = password.toUtf8().constData();

        // Use the Player::SignIn function to create a new user
        int playerId = Player::SignIn(gameserverUrl, usernameStd, passwordStd);

        if (playerId == -1) {
            QMessageBox::warning(this, "Sign In Failed", "Username already exists or other error.");
        }
        else {
            QMessageBox::information(this, "Sign In Successful", "Account created successfully!");
            // Salvează numele utilizatorului în `SessionManager`
            SessionManager::SetCurrentUsername(username);

            emit SessionStarted();

            PlayWindow* playWindow = new PlayWindow(playerId);
            playWindow->setAttribute(Qt::WA_DeleteOnClose);
            playWindow->show();

            close();
        }
        });
}
