    #include "ChatSystem.h"

    #ifndef SERVER_H
    #define SERVER_H

    class Server : public ChatSystem {
        public:
        sf::TcpListener listener;

        std::string recipient = "";
        std::string buffer = "";

        Server() {
            // listener.listen(2000);;
            //  listener.accept(socket);
            //  std::cout << "Connected to server\n";

            if (listener.listen(PORT) != sf::Socket::Done)
            {
                std::cout << "Failed to bind port\n";
            }
                else std::cout << "Server listening on port 2000...\n";


                
            if (listener.accept(socket) == sf::Socket::Done)
            {
                std::cout << "Client connected!\n";
                // packet << std::string("CONNECTED");
                // packet << "Hello";
                // packet << 42;
                // packet << 3.14f;
                if (socket.receive(packet) == sf::Socket::Status::Done)
                    packet >> this->recipient >> this->buffer;

            std::cout << "\nRecieved from: " << this->recipient << "\n " << this->buffer;

        }

        }
    };

    #endif