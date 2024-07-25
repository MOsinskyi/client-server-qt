<img src="/home/maksym/Downloads/—Pngtree—modern isometric server illustrated on_6202098.png" alt="—Pngtree—modern isometric server illustrated on_6202098" style="zoom: 25%;" />

# Client-Server Qt

This project is a simple client-server application using Qt and C++. The server listens for incoming connections and echoes messages back to connected clients.

## :star: Features

* Accepts multiple client connections.
* Echoes messages sent by clients.
* Uses Qt framework for networking.

## 🚧 Requirements

* Qt 6.x.

* C++17 compatible compiler.

## 🧭 Getting Started

### Clone the repository

```bash
git clone https://github.com/MOsinskyi/qt-client-server.git
cd qt-client-server
```

### Build the project

1. Open the project in Qt Creator.

2. Configure the project using the desired kit.

3. Build the project.

Alternatively, you can build the project using the command line:

```bash
mkdir build
cd build
qmake ..
make
```

### Run the server

```bash
./build/client-server-qt
```

## 🧩 Project Structure

* `main.cpp`: Entry point for the application. Initializes the `QApplication` and the `Server`.

* `server.h`: Header file for the `Server` class, which handles incoming connections and data transmission.

* `server.cpp`: Implementation of the `Server` class.

## 🔍 Server Class Overview

| Server Constructor                           | Starts the server and listens on the specified port and initializes the `nextBlockSize` to 0. |
| -------------------------------------------- | ------------------------------------------------------------ |
| sendToClient(QString str)                    | Prepares a data packet with the current time and the provided string. Sends the packet to all connected clients. |
| incomingConnection(qintptr socketDescriptor) | Handles new incoming connections. Sets up signal-slot connections for data reading and socket destruction. |
| slotReadyRead()                              | Reads incoming data from clients. Echoes the received message back to all clients. |

## ©️ License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details.
