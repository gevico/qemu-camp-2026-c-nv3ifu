# Repository Guidelines

## Project Structure & Module Organization

This repository contains 40 numbered C exercises. Implementations live under `exercises/NN_topic/`; most directories contain `NN_topic.c`, a local `Makefile`, and `readme.md`. Exercise-specific fixtures and helper modules stay beside the implementation. Tests are centralized in `tests/test_NN_topic.c` and use the lightweight framework in `checker/`. The root `checker.c` builds the `c-checker` runner. General documentation is in `docs/`, images are in `resource/`, and CI configuration is under `.github/workflows/`.

## Build, Test, and Development Commands

- `make c-checker`: compile the test runner with GCC, C11, and warning flags.
- `make list`: list all exercises recognized by the checker.
- `make check 37` or `make check 37_bitmap_operations`: build and test one exercise.
- `make check-all` or `make test`: run the complete suite and generate the results summary.
- `./run.sh 37_bitmap_operations`: build and run one solution interactively.
- `make watch`: rerun checks when source or tests change; `inotify-tools` is optional.
- `make clean`: remove generated binaries, objects, dependency files, and reports.

Individual exercises can also be built with `make -C exercises/37_bitmap_operations`; use the local `debug`, `run`, or `clean` target when available.

## Coding Style & Naming Conventions

Write portable C11 unless an exercise Makefile explicitly selects GNU11 or requires platform-specific features. Keep builds clean under `-Wall -Wextra`. Follow surrounding code: four-space indentation, braces on the same line as control statements and functions, `snake_case` identifiers, uppercase macros, and descriptive comments for non-obvious logic. Preserve the `NN_topic` naming scheme across directories, sources, targets, and tests. Remove every `I AM NOT DONE` marker after implementing an exercise.

## Testing Guidelines

Add or update `tests/test_NN_topic.c` for behavior changes. Initialize tests with `test_init`, use the framework's `ASSERT_*` macros, verify compilation and observable output, and return failure when `g_test_stats.failed_tests` is nonzero. Run the focused check first, then `make check-all` before submission. No explicit coverage threshold is configured; exercise correctness is determined by checker assertions.

## Commit & Pull Request Guidelines

The history currently contains only `Initial commit`, so no established commit convention exists. Use short, imperative subjects such as `Implement bitmap operations` and keep each commit focused. Pull requests should identify affected exercise numbers, summarize the approach, report commands run, and link relevant issues. Include screenshots only when output formatting or documentation images change; otherwise paste concise test results.
