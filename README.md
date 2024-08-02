![server](images/server.png)

![Static Badge](https://img.shields.io/badge/_6.2-gray?logo=qt) ![GitHub License](https://img.shields.io/github/license/MOsinskyi/client-server-qt?color=blue) ![GitHub repo size](https://img.shields.io/github/repo-size/MOsinskyi/client-server-qt) ![GitHub Release](https://img.shields.io/github/v/release/MOsinskyi/client-server-qt?color=purple) 


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

## 📦 Installation

### Linux Ubuntu

1. Go to release page.

2. Download ubuntu package: `server-app-linux-ubuntu.deb`.

3. Open terminal.

4. Go to downloads folder:

   ```bash
   cd ~/Downloads
   ```

5. Run `dpkg` command with root:

   ```bash
   sudo dpkg -i server-app-linux-ubuntu.deb
   ```

### Other Linux distro

1. Go to release page.
2. Chose package: `client-server-linux-installer.run` or `server-app-linux-portable.zip`

> [!NOTE]
>
> `server-app-linux-portable.zip` and `client-server-linux-installer.run` also work in ubuntu disto

3. Run the installer using command:

   ```bash
   cd ~/YOUR_DOWNLOADS_FOLDER
   chmod +x server-app-linux-installer.run
   ./server-app-linux-installer.run
   ```

   *Or*

   Click **right** mouse button, go to **Properties** and check if **Executable as Program** is turned on next double click left mouse button to start the installer application.

4. Extract the `server-app-linux-portable.zip` package.

5. Find `server-app.sh`.

6. Make the file **Executable as Program**:

   ```bash
   chmod +x server-app.sh
   ```

   Or

   *In Properties Window turn on `Executable as Program`*

7. Run the script:

   ```bash
   ./server-app-sh
   ```

8. Done ✅.

### Windows

1. Go to release page.
2. Chose package: `client-server-windows-installer.exe` or `server-app-windows-portable.zip`.
3. Run `client-server-windows-installer.exe` as administrator and follow the instructions on the screen.
4. Extract files from `server-app-windows-portable.zip`.
5. Run `server-app.bat`.
6. Done ✅.

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
