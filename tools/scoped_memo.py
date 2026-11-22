"""Memoize a pure read of the working tree for the length of one operation.

A validation or acceptance run sees one stable tree, so a result that depends only on file
contents may be computed once per run. The memo exists only inside `memo_scope()`, is never
shared between scopes, and is bypassed entirely outside one, so a long-lived process or a test
that edits files between calls always recomputes.
"""
from contextlib import contextmanager
from contextvars import ContextVar

_MEMO = ContextVar('scoped_memo', default=None)


@contextmanager
def memo_scope():
    if _MEMO.get() is not None:
        yield
        return
    token = _MEMO.set({})
    try:
        yield
    finally:
        _MEMO.reset(token)


def memoized(key, compute):
    """`compute()`, cached under `key` while a scope is open. Callers must not mutate the result."""
    memo = _MEMO.get()
    if memo is None:
        return compute()
    if key not in memo:
        memo[key] = compute()
    return memo[key]
