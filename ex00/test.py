#!/usr/bin/env python3

from subprocess import run

from hypothesis import given
from hypothesis import strategies as st


def is_run_successful(result) -> bool:
    return result.returncode == 0


@given(st.integers())
def test_handle_int(num: int):
    args = ["./prog.out", str(num)]
    print(f"{args =}")
    result = run(args)
    assert is_run_successful(result)


if __name__ == "__main__":
    test_handle_int()
