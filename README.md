# Minitalk - Client and Server Communication

Welcome to the Minitalk project! In this assignment, the goal is to create a client-server communication program where information is transmitted using UNIX signals. The server, initiated first, prints its PID after launch. The client, taking the server PID and a string as parameters, sends the string to the server using SIGUSR1 and SIGUSR2 signals.

## Project Overview

### Key Objectives

- Implement a server that prints its PID after launch.
- Develop a client program that sends a string to the server using UNIX signals.
- Ensure quick and efficient communication between the client and server.
- Enable the server to handle multiple string receptions from different clients without needing a restart.

### Why UNIX Signal Communication?

UNIX signal communication is a lightweight and efficient way for inter-process communication. This project provides a hands-on experience in designing a simple yet powerful client-server communication system using only two signals: SIGUSR1 and SIGUSR2. Mastering this concept is valuable for understanding signal handling and IPC mechanisms.

## Getting Started

### Prerequisites

- A basic understanding of UNIX signals.
- A code editor of your choice.

### Usage

1. Compile the server program:

    ```bash
    gcc server.c -o server
    ```

2. Launch the server:

    ```bash
    ./server
    ```

   Note the printed PID for use by the client.

3. Compile the client program:

    ```bash
    gcc client.c -o client
    ```

4. Run the client with the server PID and the string to send:

    ```bash
    ./client SERVER_PID "Hello, Server!"
    ```

5. Observe the server displaying the received string.

---
