## NitroShare

[![Current tagged release](https://img.shields.io/github/tag/nitroshare/nitroshare.svg)](https://github.com/nitroshare/nitroshare-desktop/releases/latest)
[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)](http://opensource.org/licenses/MIT)
[![Join the chat at https://gitter.im/nitroshare/nitroshare-desktop](http://img.shields.io/badge/gitter-JOIN_CHAT-green.svg?style=flat)](https://gitter.im/nitroshare/nitroshare-desktop?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

A cross-platform network file transfer application designed to make transferring any file to any device as painless as possible.

### Features

* Runs on Windows / Mac OS X / Linux
* Automatic discovery of devices on the local network
* Simple and intuitive user interface
* Incredibly fast transfer speeds
* Transfer entire directories
* Optional TLS encryption
* Local HTTP API
* Completely free and open-source

### Download

Downloads can be found on the NitroShare website: https://nitroshare.net

### Documentation

Instructions for building NitroShare from source as well as protocol descriptions can be found on [the GitHub wiki](https://github.com/nitroshare/nitroshare-desktop/wiki).

### Building on Linux

Patched 'splashdialog.cpp' in application folder with `#include <QStyle>` line.

1. The instructions below were tested on Ubuntu 20.04. 

   `sudo apt-get install build-essential cmake qtbase5-dev`

   To enable support for application indicators, you will need to install the following packages:

   `sudo apt-get install libgtk2.0-dev libappindicator-dev libnotify-dev`

   In addition, the following libraries are required:

   `sudo apt-get install qttools5-dev libqt5svg5-dev`

2. Change to the root of the source directory and build the project:

    ```
    mkdir build && cd build
    cmake ..
    make
    ```

3. The NitroShare binary will be in the out/ directory and can be run with:

   `out/nitroshare`
