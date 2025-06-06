# Distributed Calculator (gRPC + C++)

A simple distributed calculator service built using **gRPC** and **C++**.

This project demonstrates:
- Remote Procedure Calls (RPC)
- Interface Definition Language (IDL) with Protocol Buffers
- Client-Server model in a distributed system
- Syntactic Transparency: Remote calls look like local function calls
- Marshalling/Unmarshalling of data with Protocol Buffers
- Clean CMake build system

---

##  Technologies Used
- C++
- gRPC
- Protocol Buffers
- CMake
- GitHub

---

## Project Structure

```bash
distributed-calculator-grpc/
├── calculator.proto           # Interface definition (IDL)
├── generated/                  # Generated proto and gRPC code
├── server/
│   ├── calculator_server.cc     # Server implementation
│   └── CMakeLists.txt
├── client/
│   ├── calculator_client.cc     # Client implementation
│   └── CMakeLists.txt
├── CMakeLists.txt              # Root build configuration
└── README.md                   # This file
```

## Setup Instructions
1. Prerequisites
   - gRPC installed(via Homebrew or manual install)
   - Protocol Buffers(`protoc`) installed
   - CMake installed
   - C++ COmpiler(Clang or GCC)
  Check your setup
  ```bash
  protoc --version
  grpc_cpp_plugin --version
  cmake --version
  g++ --version
  ```

2. Clone the Repository
   ```bash
   git clone https://github.com/YOUR_USERNAME/distributed-calculator-grpc.git
   cd distributed-calculator-grpc
   ```
3. Generate gRPC Code
   ```bash
   protoc --proto_path=. --cpp_out=generated --grpc_out=generated --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` calculator.proto
   ```
4. Run the server
   ```bash
   ./server/calculator_server
   ```
5. Run the client(in another terminal)
   ```bash
   ./server/calculator_server
   ```

## Features
- Perform basic arithmetic operations: Add, Multiply, Divide
- Server handles division by 0 gracefully with error handling
- Client calls remote functions like local functions - synchronous, transparent

## Concepts Covered
- RPC(Remote Procedure Call): Making network calls look like local function calls
- IDL (Interface Definition Language): Defined in `calculator.proto`
- Syntactic Transparency: Client code is simple, looks like normal function calls
- Marshalling: Automatically handled by Protocol Buffers
- Client-Server Model: Standard architecture for distributed systems

## Author
Sushanth Reddy <br>
Feel free to connect on [LinkedIn](https://www.linkedin.com/in/sushanthreddykotha/).

     
