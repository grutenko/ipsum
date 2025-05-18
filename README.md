# ipsum — planned CLI utility for CIDR operations

**ipsum** is an experimental command-line tool for working with sets of IP networks (CIDR blocks).
The goal is to provide a clean, scriptable interface for common subnet-related operations in the Unix tradition.

⚠️ **This is an early prototype. Most features are planned, not implemented yet.**

---

## ✨ Planned Features

- 📦 `merge` — combine overlapping or adjacent CIDRs into minimal covering set
- ✂️ `split` — divide a CIDR block into smaller subnets
- 🚫 `subtract` — remove one set of CIDRs from another
- 🔍 `contains` — check if IPs belong to any given network
- 📊 `stats` — report total hosts, coverage, compression ratio, etc.
- 🧪 `validate` — check input format, redundancy, overlaps
- ⚙️ Flags like `--level`, `--count`, `--prefix`, `--postfix`, `--json`

---

## Example (planned) usage

```sh
ipsum merge input.txt > optimized.txt
ipsum subtract allow.txt deny.txt > result.txt
ipsum contains 8.8.8.8 ranges.txt
ipsum stats ranges.txt
```

## Goals

- 🚀 Fast and minimal (written in C)
- 🧰 Composable with standard Unix tools
- 🧼 Deterministic, strict, script-friendly
- ❌ No dependencies, no surprises

## Status

- ✅ Concept and design in progress
- 🛠 Core components being prototyped in C
- 🧪 Features will be added incrementally

## License

MIT
