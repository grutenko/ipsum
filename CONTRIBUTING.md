# Contributing to `ipsum`

Thanks for your interest in contributing to **ipsum** — a minimal, Unix-style CIDR utility written in C.

This project is currently experimental and under active design.
Pull requests, ideas, and questions are very welcome.

---

## 🛠 How to Contribute

1. **Fork the repository** and clone it locally.
2. Build the project with:
```sh
make
```

Run basic tests:
```sh
make test
```
Create a new branch for your fix or feature:
```sh
git checkout -b feature/your-thing
```
Submit a pull request with a clear description of what you changed and why.

## 📄 Coding Guidelines

Write clean, simple C in the style of cut, sort, uniq.
Avoid dynamic memory if possible.
Prefer small, modular functions.
Use standard C89/C99 and POSIX headers.
Don’t use third-party dependencies (pure libc).
Keep CLI behavior consistent with Unix philosophy: composable, pipeable, quiet by default.

## 🧪 Tests

Add test cases for any new functionality in tests/.
If possible, include input and expected output files:
tests/mycase.in
tests/mycase.out

## 📬 Reporting Bugs / Requesting Features

Please open an issue with:

A clear title
Steps to reproduce (if a bug)
Example input/output (if relevant)

## 📜 License

By contributing, you agree that your work will be released under the MIT License.

Happy hacking — and keep it subnetted!
