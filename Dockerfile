# Use an official Ubuntu as a base image
FROM ubuntu:22.04

# Install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Create a working directory inside the container
WORKDIR /app

# Copy the entire project into the container
COPY . /app

# Compile the code directly with g++
RUN g++ src/Foobar/Foobar.cpp src/BloomFilter/BloomFilter.cpp src/main.cpp -o myapp

# Run the compiled program
CMD ["./myapp"]
