![Score](score.png)


# nsh (Minishell)

`nsh` is a custom implementation of a Unix shell, developed as part of the 42 School curriculum. It provides a simplified yet functional environment for command execution, featuring parsing, tokenization, expansion, redirections, pipelines, built-in commands, and more. The project is structured into modular components, each responsible for a specific stage of shell behavior.

---

## Features

- **Command parsing**: Full tokenizer and parser to transform user input into structured commands.
- **Execution engine**: Support for pipelines, redirections, and subshells.
- **Built-in commands**:
  - `echo`
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`
- **Environment variable expansion**: Proper handling of `$VAR` and special variables.
- **Wildcards**: Support for `*` expansion.
- **Heredoc** (`<<`): Input redirection with custom delimiters.
- **Error handling**: Syntax error detection, exit codes, and signal handling.
- **Memory management**: Includes a custom tracking system to detect and avoid leaks.

---

## Project Structure

```
nsh/
├── built_in/        # Implementation of shell built-in commands
├── execution/       # Process execution, pipelines, redirections
├── expansion/       # Variable and wildcard expansion
├── getenv/          # Environment variable utilities
├── heredoc/         # Heredoc implementation
├── includes/        # Header files
├── mem_track/       # Custom memory tracking utilities
├── parser/          # Command parser (AST, grammar rules)
├── sources/         # Main program sources (entry point, setup)
├── stdfcts/         # Reimplemented libc-like helper functions
├── tokenization/    # Input lexer/tokenizer
├── utils/           # General utilities
└── Makefile         # Build system
```

---

## Build & Usage

### Requirements
- GCC / Clang
- GNU Make
- Linux or macOS environment

### Compilation
```sh
make
```
This will generate the `nsh` executable.

### Running
```sh
./nsh
```
You will be dropped into an interactive shell where you can run commands like in Bash:
```sh
nsh$ echo Hello World
Hello World
nsh$ ls -l | grep nsh
```

---

## Signals
- **Ctrl+C** → Interrupts current process (prints a new prompt).
- **Ctrl+D** → Exits the shell.
- **Ctrl+\\** → Quits the current process.

---

## Development Notes
- Written in C following 42 Norm coding standards.
- Modular design for easier debugging and extension.
- Each component (tokenizer, parser, executor, etc.) is isolated in its own directory.

---

## Limitations
- No job control (background processes `&`).
- Limited error messages compared to Bash.
- Some advanced Bash features are not supported.

---

## Authors
- **Yahya Jaafar (N0ViP)**
- **Achraf Hoummada (Yontorio)**

---

## License
This project is for educational purposes as part of the 42 curriculum. Redistribution and modification follow the school’s guidelines.

