"""Private storage paths shared by contributor tools; SR_LOCAL_DIR must already exist."""
import os
from pathlib import Path
import subprocess


def local_dir(root, env=None):
    env = os.environ if env is None else env
    override = env.get('SR_LOCAL_DIR')
    if not override:
        return Path(root) / '.local'
    path = Path(override).expanduser()
    if not path.is_absolute():
        path = Path(root) / path
    if not path.is_dir():
        raise ValueError('SR_LOCAL_DIR must name an existing directory')
    return path.resolve()


def local_path(root, path, env=None):
    """Resolve repo-relative paths, relocating only paths under the default .local root."""
    path = Path(path)
    if not path.is_absolute() and path.parts[:1] == ('.local',):
        return local_dir(root, env) / Path(*path.parts[1:])
    return path if path.is_absolute() else Path(root) / path


def no_sibling_names(env=None):
    return (os.environ if env is None else env).get('SR_NO_SIBLING_NAMES') == '1'


def main_worktree_local(root):
    """The main worktree's .local when `root` is a linked git worktree without a .local of its own.

    Toolchains, Wine and the game executable are set up once per clone; a fresh worktree would
    otherwise look empty. None when `root` is the main worktree, is not a git checkout, or has its
    own .local (then that one is the intended private store).
    """
    if (Path(root) / '.local').exists():
        return None
    return main_checkout_local(root)


def main_checkout_local(root):
    """The main checkout's .local when `root` is a linked git worktree, else None.

    Found through `git rev-parse --git-common-dir`. A worktree that already has some private
    files of its own still lacks toolchains set up once in the main checkout, so tools fall back
    to this directory per resource.
    """
    root = Path(root)
    try:
        proc = subprocess.run(['git', 'rev-parse', '--path-format=absolute', '--git-common-dir', '--git-dir'],
                              cwd=root, capture_output=True, text=True, timeout=20)
    except (OSError, subprocess.SubprocessError):
        return None
    lines = proc.stdout.splitlines()
    if proc.returncode or len(lines) != 2 or lines[0] == lines[1]:
        return None
    main = Path(lines[0]).parent / '.local'
    return main.resolve() if main.is_dir() else None
