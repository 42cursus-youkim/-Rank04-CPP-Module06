#!/usr/bin/env python3

from subprocess import run

from hypothesis import given
from hypothesis import strategies as st


def is_run_successful(result) -> bool:
    return result.returncode == 0


def is_run_raised_exception(result) -> bool:
    return "Conversion impossible" in result.stderr.decode()


INT_MAX = 2147483647
INT_MIN = -2147483648


@given(st.integers())
def test_handle_int(num: int):
    args = ["./prog.out", str(num)]
    result = run(args, capture_output=True)
    if num < INT_MIN or INT_MAX < num:
        assert is_run_raised_exception(result)
    else:
        assert is_run_successful(result)


if __name__ == "__main__":
    test_handle_int()
