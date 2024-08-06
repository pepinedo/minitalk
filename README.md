<a href="https://github.com/francfer-art/42MiniTalk">
  <img src ="https://raw.githubusercontent.com/15Galan/42_project-readmes/master/banners/cursus/projects/minitalk-dark.png")>
</a>

<p align="center">
  <a href="https://github.com/francfer-art/42MiniTalk">
  <img src="https://raw.githubusercontent.com/mcombeau/mcombeau/main/42_badges/minitalkm.png" alt="MiniTalk Logo">
  </a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Score-Evaluating-brightgreen" alt="MiniTalk Score">
</p>

## Table of Contents

- [Introduction](#introduction)
- [Error Handling](#error-handling)
- [Global Variables](#global-variables)
- [Allowed Functions](#allowed-functions)
- [Mandatory Part](#mandatory-part)
- [Usage](#usage)
- [Avaliable Parameters](#avaliable-parameters)
- [Bonus Part](#bonus-part)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This program consists of a client and a server component designed for communication using UNIX signals. Below are the specifications and guidelines for implementing the client-server communication.

## Error Handling

Thoroughly handle errors to ensure the program does not quit unexpectedly (e.g., segmentation fault, bus error, double free, etc.).
Ensure your program does not have memory leaks.

## Global Variables

You can have one global variable per program (one for the client and one for the server), but their use must be justified.

## Allowed Functions

You are allowed to use the following functions to complete the mandatory part:

```
write
ft_printf and any equivalent you coded
signal
sigemptyset
sigaddset
sigaction
kill
getpid
malloc
free
pause
sleep
usleep
exit
```

## Mandatory Part

Server:

The server must be started first and print its PID after launch.
It must be able to receive strings from multiple clients in succession without needing to restart.
The server must display received strings quickly. A delay of 1 second for displaying 100 characters is considered too long.

Client:

Takes two parameters: the server PID and the string to send.
Sends the provided string parameter to the server using UNIX signals.

Communication:

Communication between the client and server should only use UNIX signals (SIGUSR1 and SIGUSR2).
Ensure robust error handling throughout both client and server components.
Implement efficient and quick string processing and communication mechanisms.


## Usage

After compiling, start the server using ./server.
Note the server PID printed.
Start the client using ./client <server_PID> "<string_to_send>".
The server should promptly display the received string.

## Bonus Features

The server acknowledges every message received by sending back a signal to the client.
Unicode characters support!

After compiling, start the server using ./server_bonus
Note the server PID printed.
Start the client using ./client_bonus <server_PID> "<string_to_send>".
The server should promptly display the received string.

## Contributing

Contributions are welcome! If you have improvements or additional features to suggest, please open an issue or submit a pull request. Follow the Contribution Guidelines for more details.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

