[![Build Status](https://github.com/aabolfazl/io-uring-lab/actions/workflows/cmake-linux-io-uring.yml/badge.svg)](https://github.com/aabolfazl/io-uring-lab)

# 🚀 io-uring lab

A comprehensive collection of examples demonstrating Linux's high-performance io_uring API. This repository aims to be a practical learning resource for developers who want to understand and implement io_uring in their applications.

## 🎯 Goal

The primary goal of this project is to provide clear, well-documented examples of io_uring's rich API features. Each example is designed to demonstrate a specific concept or use case, making it easier for learners to understand and implement io_uring in their projects.

This project emerged from the development experience of [Vortex](https://github.com/aabolfazl/Vortex) - a high-performance Layer 4 Load Balancer built with io_uring. During Vortex's development, I noticed that while io_uring offers powerful capabilities, the learning curve can be steep due to:
- Scattered documentation across kernel sources
- Complex interaction patterns
- Lack of comprehensive, beginner-friendly examples
- Limited practical implementation references

io_uring-lab aims to bridge this gap by providing the following:
- Step-by-step examples progressing from basic to advanced concepts
- Well-documented code with detailed explanations
- Practical, real-world usage patterns
- Clear path for developers to implement io_uring in their projects

Whether you're building a high-performance server like Vortex, implementing network tools, or just learning about modern Linux I/O, these examples will help you understand and effectively use io_uring's capabilities.

## Requirements
- Linux Kernel 5.1+ (basic features)
- Linux Kernel 5.6+ (for advanced networking features)
- Linux Kernel 5.19+ (for multishot accept)
- liburing development headers
- C compiler with C11 support

## 📚 Learning Path

### 1. Core Concepts
Learn the fundamental building blocks of io_uring:
- Ring setup and basic configuration
- SQE (Submission Queue Entry) preparation
- CQE (Completion Queue Entry) handling
- Completion queue event handling
- Understanding linked operations
- Buffer management basics
- Error handling patterns

### 2. File Operations
Explore file I/O with io_uring:
- Basic read/write operations
- Vectored I/O (readv/writev)
- Splice operations for efficient data transfer
- Practical implementations:
  - Simple cat utility
  - Efficient file copy
  - File reading patterns

### 3. Network Operations
Master network programming with io_uring:
- TCP accept operations
- Connection establishment
- Basic send/recv implementation
- Zero-copy networking (hardware/kernel requirements)
- Multishot accept for high-performance servers
- Socket operations and management

### 4. Advanced Features
Dive into advanced io_uring capabilities:
- Submission queue polling
- I/O polling mechanisms
- Buffer management strategies
- Async operations and timeout handling
- Event notification systems
- Operation cancellation
- Fixed buffers and registered buffers
- SQPOLL and IOPOLL modes
- Kernel-side polling
- Multishot operations
- Fast poll support
- Direct descriptors

### 5. Performance Optimization
Learn to maximize io_uring performance:
- File descriptor registration
- Buffer registration techniques
- Batch submission strategies
- Memory management optimization
- Performance monitoring and profiling

### 6. Real-world Applications
See io_uring in action:
- Simple HTTP server implementation
- High-performance file server
- I/O benchmarking tool
- Practical network services

## 🤝 Contributing

Contributions are warmly welcomed! Here's how you can contribute:

- **Bug Reports**: Open an issue describing the bug and how to reproduce it
- **Feature Requests**: Suggest new examples or improvements via issues
- **Code**: Submit PRs for:
  - New examples
  - Bug fixes
  - Improvements to existing examples
  - Better documentation

## 📝 License

This project is licensed under the MIT License - see the LICENSE file for details.
