# ft_script

> A low-level UNIX systems programming project: recoding the classic `script` command in C.

## 📌 Overview

`ft_script` is a custom implementation of the standard UNIX `script` utility. It records a terminal session, capturing all input and output (including hidden control characters, ANSI escape sequences, and timing data) and saves it to a typescript file. 

Developed as part of the **42 School** curriculum, this project enforces strict constraints: **no memory allocation (`malloc`/`free`) in the core logic**, and the exclusive use of **System Calls (Section 2 of the manual)** to interact directly with the Linux kernel.

This project serves as a practical exploration of terminal emulation, process multiplexing, and direct kernel interactions—foundational concepts for systems engineering, infrastructure automation, and low-level security analysis.

## 🛠️ Technical Concepts & Architecture

Building a bridge between a user's terminal and a background shell requires orchestrating several complex UNIX mechanisms. This project demonstrates proficiency in:

* **Pseudo-Terminals (PTY):** Manually provisioning and unlocking Master/Slave pseudo-terminals via `ioctl` (reproducing the behavior of `grantpt` and `unlockpt`).
* **Terminal Configuration (termios):** Safely backing up terminal states and switching the parent terminal to **RAW mode** (`TCGETS` / `TCSETS`) to prevent input interception and ensure transparent byte transmission.
* **Process Control:** Utilizing `fork()` and `execve()` to spawn an isolated shell environment, and securely redirecting standard file descriptors (`dup2`).
* **I/O Multiplexing:** Implementing a non-blocking bridge using `select()` to simultaneously monitor user input (`STDIN`) and the shell's output (`PTY Master`).
* **Signal Handling:** Dynamically catching `SIGWINCH` to synchronize terminal window resizing between the physical terminal and the emulated PTY in real-time.

## 🚀 Installation & Usage

### Compilation
Ensure you have `make` and a standard C compiler (`cc`/`gcc`) installed.

```bash
git clone [https://github.com/Alexs1004/ft_script.git](https://github.com/Alexs1004/ft_script.git)
cd ft_script
make

```

### Usage

Run the executable to start recording your session. By default, it saves the output to a file named `typescript`.

```bash
./ft_script [options] [file]

```

**Available Options:**

* `-a` : Append the output to the file instead of overwriting it.
* `-q` : Quiet mode. Suppresses the start and end status messages on standard output.

**Example:**

```bash
./ft_script -a my_session_log.txt
# ... perform your terminal operations ...
# Type 'exit' or press Ctrl+D to stop the recording.
cat my_session_log.txt # View your exact session history

```

## 📁 Repository Structure

The architecture is designed for maintainability and clear separation of concerns:

```text
.
├── inc/
│   └── ft_script.h       # Core structures, macros, and prototypes
├── src/
│   ├── main.c            # Argument parsing and program orchestration
│   ├── pty.c             # Pseudo-terminal master/slave initialization via ioctl
│   ├── terminal.c        # Terminal state backup and RAW mode enforcement
│   ├── multiplex.c       # I/O routing loop using select()
│   ├── exec.c            # Process cloning and shell execution
│   ├── signal.c          # Dynamic window resize (SIGWINCH) handling
│   └── utils.c           # File management and timestamp formatting (ctime)
└── libft/                # Custom standard C library implementation

```

## 🧠 Why this project matters

In modern IT environments—whether managing SOC operations, tuning SIEMs, or writing infrastructure-as-code—the Command Line Interface is central.

Developing `ft_script` from scratch provides a microscopic view into how shells and terminals actually communicate. Understanding how bytes are piped through pseudo-terminals, how signals interrupt processes, and how raw data is serialized before it reaches higher-level applications like SSH or automation playbooks provides a crucial edge in debugging complex system anomalies.
