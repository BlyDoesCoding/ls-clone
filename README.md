## Day 1: ls-clone

A tiny **C** program that mimics `ls` but adds a splash of colour and emojis to make directory listings.

The project is part of a personal coding challenge: Write a small C Programm Every Day (When i have Time(probably never))

---

### Features

- Lists files in the current directory (or a path passed as an argument).  
- Detects file type by extension and applies colour + emoji.  
- Works on Linux/macOS (uses `dirent.h` and ANSI escape codes).  
- No external dependencies – just the C standard library.  


<img width="1009" height="434" alt="image" src="https://github.com/user-attachments/assets/5b9c1269-bf0d-4b34-83fb-4546fc4613ee" />

---

### Build & Install

```bash
# Clone the repo
git clone https://github.com/BlyDoesCoding/ls-clone
cd ls-clone

# Compile (requires Unix)
gcc -o ls-clone main.c

# Optionally move to a directory in your PATH
sudo mv ls-clone /usr/local/bin/
