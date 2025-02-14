# BloomFilter
## Overview
A Bloom Filter implementation in C++ for efficient URL blacklisting, supporting multiple hash functions.

## Technologies
- **C++**, **Google Test (GTest)**, **CMake**
- **Docker** for containerization
- GitHub Actions for **CI/CD**

## Key Features
- **Modular Design:** Interfaces for I/O and commands
- **Command Pattern:** Encapsulates operations (SearchCommand, AddCommand)
- **CI/CD:** Automated Docker image builds & tests
  
## Usage
### Build & Run Locally:
`g++ Foobar/Foobar.cpp BloomFilter/BloomFilter.cpp main.cpp -o bloomfilter ./bloomfilter`

### Using Docker:
```cpp
docker build -t bloomfilter .
docker run --rm -it bloomfilter
```

### Run Tests:
`cmake -S . -B build && cmake --build build && cd build && ctest --output-on-failure`
