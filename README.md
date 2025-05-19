# ipsum — minimal CLI toolkit for CIDR operations

**ipsum** is a lightweight, Unix-style command-line utility for manipulating IP networks (CIDR blocks).
It provides a set of fast, composable commands for network engineers, DevOps, and curious hackers.

You can think of it as `cut`, `sort`, `uniq` — but for subnets.

🚧 This project is currently a **concept and design prototype**.
Commands, interfaces, and internal structures are being explored and iterated.
Implementation is partial or not yet started.

---

## ⚙️ Commands

| Command   | Description                                                   |
|-----------|---------------------------------------------------------------|
| `agg`     | Combine adjacent or overlapping CIDRs into minimal set        |
| `deagg`   | Split a CIDR block into smaller subnets                       |
| `sub`     | Subtract one list of prefixes from another                    |
| `match`   | Check if IP(s) fall into any CIDR in the list                 |
| `diff`    | Show the difference between two CIDR lists                    |
| `stat`    | Show prefix counts, address coverage, compression ratio       |
| `uniq`    | Remove duplicate or redundant prefixes                        |
| `check`   | Validate input format and structural consistency              |
| `opt`     | Shortcut for `uniq + agg` (deduplication and compression)     |

---

## 📦 Example usage

```sh
# Aggregate routes
ipsum agg @bgp-fullview.txt > compressed.txt

# Split a /16 into /24s
ipsum deagg --output=file.txt --by=24 10.0.0.0/16

# Subtract blacklisted IPs
ipsum sub @allowlist.txt @blacklist.txt

# Match IPs against a set of prefixes
ipsum match --by=8.8.8.8 @google.txt

# Compare prefix sets from two ASNs
ipsum diff @as15169.txt @as13335.txt

# Show statistics
ipsum stat @cloudflare.txt

# Clean and compress prefix list
ipsum opt @ripe-dump.txt
```

## 🛠 Features

- ⚡️ Written in C for speed and portability
- 🧱 Prefix tree structure for efficient operations
- 🔧 Designed for automation, scripting, and pipelines
- 🧰 Zero dependencies, pure libc
- 📚 Inspired by real-world BGP, routing, firewall, and filtering use cases
- 📤 Input

## Accepts files or stdin
- Supports IPv4 (IPv6 planned)
- One CIDR block per line:
192.168.0.0/24
10.0.0.0/8

## 📦 Building

```make
sudo make install
```

- 📜 License
MIT

- 🤝 Contributing
See CONTRIBUTING.md

This project is designed for people who think in subnets and prefer tools that don't talk back.
