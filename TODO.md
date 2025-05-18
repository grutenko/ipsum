# TODO — ipsum core tasks

This document outlines planned implementation steps for the `ipsum` CIDR toolkit.

Current status: designing and prototyping core functionality using prefix trees and clean CLI command routing.

---

## 🌲 Data Structures

- [ ] Define `cidr_t` — base type for IPv4 block (uint32_t addr + uint8_t mask)
- [ ] Define `cidr_node_t` — prefix tree node for aggregation and search
- [ ] Implement tree insert, lookup, and collapse logic
- [ ] Provide tree-to-list flattening for output

---

## 🧠 Core CIDR Operations

- [ ] `cidr_parse()` / `cidr_print()` — string <-> struct conversion
- [ ] `cidr_contains()` — check if A contains B
- [ ] `cidr_adjacent()` — are two blocks adjacent and mergeable
- [ ] `cidr_merge()` — compute parent CIDR if mergeable
- [ ] `cidr_split()` — break block into equal smaller subnets

---

## 🧰 Command Implementations

- [ ] `agg` — load list, insert into tree, compress, flatten, output
- [ ] `deagg` — split input block into smaller /N subnets
- [ ] `sub` — subtract tree B from tree A
- [ ] `match` — lookup IP(s) against CIDR set
- [ ] `diff` — symmetric difference between two prefix sets
- [ ] `stat` — show count, coverage, block sizes, compression ratio
- [ ] `uniq` — deduplicate list of prefixes
- [ ] `check` — verify input format, overlaps, nested blocks
- [ ] `opt` — run `uniq` and `agg` together

---

## 🛠 CLI and Shell Integration

- [ ] `main.c` with subcommand dispatch (e.g. `argv[1]` → command)
- [ ] `--help` and `--version` flags
- [ ] Read from `stdin` or file (line-based)
- [ ] Output to `stdout`
- [ ] Command aliases (long names: `aggregate`, `deaggregate`)

---

## 🧪 Testing

- [ ] Create `tests/` folder with `.in` / `.out` fixtures
- [ ] Write `tests/run.sh` to validate behavior
- [ ] Add edge case tests: `/0`, `/32`, overlapping blocks
- [ ] Benchmark with real-world BGP dumps

---

## 📚 Documentation

- [ ] `README.md` — ✅ done
- [ ] `CONTRIBUTING.md`, `CODE_OF_CONDUCT.md`
- [ ] `man/ipsum.1` — command help (Unix-style)
- [ ] `design.md` — prefix tree structure and merge logic
