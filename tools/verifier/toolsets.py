#!/usr/bin/env python3
"""Which compiler a unit is built with, derived from the recipe its `Recipe:` line names.

A recipe records the compiler it was written for in `compiler.binary_sha256` (the hash of `cl.exe`).
A pin file lists the four compiler binaries of one toolset: `tools/verifier/pinned.sha256` for the
default toolset and `tools/verifier/pinned/<id>.sha256` for each other one. The unit's toolset is
the one whose pin file holds the recipe's `cl.exe` hash, so a unit can only be built, compared and
confirmed with the compiler its recipe names, and a recipe cannot name a compiler no pin file knows.

Standard library only: the CI runner, the contributor helper, the host agent and the bot import it.
"""
import json
from pathlib import Path

DEFAULT = '19.16.27054'
PIN_DEFAULT = 'tools/verifier/pinned.sha256'
PIN_DIR = 'tools/verifier/pinned'
# The compiler the Havok objects of the target were built with (Rich header: VS2015 Update 2).
HAVOK = '19.00.23918'


class ToolsetError(ValueError):
    """A recipe or pin file is unreadable, or no pin file matches the recipe's compiler."""


def pin_path(toolset):
    """Repository-relative pin file of `toolset`."""
    return PIN_DEFAULT if toolset == DEFAULT else f'{PIN_DIR}/{toolset}.sha256'


def read_pin_file(path):
    """{binary name: sha256} of one pin file."""
    out = {}
    for line in Path(path).read_text().splitlines():
        parts = line.split()
        if len(parts) == 2:
            out[parts[1]] = parts[0]
    return out


def known(repo):
    """{toolset id: {binary name: sha256}} for every pin file of the checkout, the default first."""
    repo = Path(repo)
    out = {DEFAULT: read_pin_file(repo / PIN_DEFAULT)}
    for path in sorted((repo / PIN_DIR).glob('*.sha256')):
        out[path.stem] = read_pin_file(path)
    return out


def recipe_cl_hash(repo, recipe_rel):
    try:
        return json.loads((Path(repo) / recipe_rel).read_text())['compiler']['binary_sha256']
    except (OSError, ValueError, KeyError, TypeError) as exc:
        raise ToolsetError(f'invalid compiler pin in {recipe_rel}') from exc


def toolset_of_recipe(repo, recipe_rel, strict=False):
    """The toolset id whose `cl.exe` pin equals the recipe's `compiler.binary_sha256`.

    A recipe whose hash no pin file holds is built with the default toolset, as before pin files
    existed for other compilers, unless `strict` (tests/test_toolsets.py keeps every committed
    recipe on a known pin)."""
    try:
        digest = recipe_cl_hash(repo, recipe_rel)
    except ToolsetError:
        if strict:
            raise
        return DEFAULT
    try:
        table = known(repo)
    except OSError:
        if strict:
            raise
        return DEFAULT
    for toolset, pins in table.items():
        if pins.get('cl.exe') == digest:
            return toolset
    if strict:
        raise ToolsetError(f'no toolchain pins for {recipe_rel}')
    return DEFAULT


def pins_for_recipe(repo, recipe_rel, strict=False):
    """(toolset id, pin file path, {binary name: sha256}) of the compiler `recipe_rel` names."""
    toolset = toolset_of_recipe(repo, recipe_rel, strict)
    return toolset, pin_path(toolset), known(repo)[toolset]


def declared_recipe(text, fallback):
    """The first `reconstruction/recipes/*.json` path in a unit's source, else `fallback`."""
    import re
    found = re.search(r'\breconstruction/recipes/[a-zA-Z0-9_.-]+\.json', text)
    return found.group(0) if found else fallback


def toolchain_args(pairs):
    """{toolset id: path} from repeated `ID=PATH` command-line values."""
    out = {}
    for pair in pairs or ():
        key, sep, value = pair.partition('=')
        if not sep or not key or not value:
            raise ToolsetError(f'toolchain must be ID=PATH, got {pair!r}')
        out[key] = value
    return out


def select_msvc(default_msvc, toolchains, toolset):
    """The toolchain directory of `toolset` on a host: its default one, or its entry in `toolchains`.

    None when the host has no toolchain for it; the caller reports that as an infrastructure
    refusal, never as a result about the candidate."""
    if toolset == DEFAULT:
        return default_msvc
    return (toolchains or {}).get(toolset)
