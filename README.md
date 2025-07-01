# Black-Scholes Pricer (C++)

A simple, modern C++ implementation of the Black-Scholes option pricing model.

## ✨ Features

- European call and put pricing
- Unit tests
- Example usage
- CMake-based build system

## 🛠️ Build Instructions
First clone the repository and its dependencies:
```bash
git clone git@github.com:aliakatas/black-scholes-pricer.git
git submodule update --init
cd black_scholes_pricer
```

For local system build:
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

To build and collect the artefacts using a container:
```bash
cd container/
docker build -f Dockerfile.build -t black-scholes-pricer-builder .
docker create --name black-scholes-pricer-builder black-scholes-pricer-builder
docker cp black-scholes-pricer-builder:/build ./output
docker rm black-scholes-pricer-builder
```

## 🚧 Development 
For container-based development:
```bash
cd container/
USER=$(whoami) USER_UID=$(id -u) USER_GID=$(id -g) docker compose build
USER=$(whoami) USER_UID=$(id -u) USER_GID=$(id -g) docker compose up -d
```
Then connect to the running container from VS Code.
