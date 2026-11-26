#!/usr/bin/env python3
"""Install the VS2015 Update 2 (19.00.23918) x64 compiler from Microsoft's own installer image.

    vs2015_u2.py install --accept-license --root DIR [--sdk-from ROOT [--wrapper]] [--iso FILE] [--work DIR]
    vs2015_u2.py pins    [--iso FILE]            # print the package table for a new pin

Microsoft still serves the Visual Studio 2015 Update 2 Community image (vs2015.2.com_enu.iso) from
download.microsoft.com with no sign-in. The compiler is a few MSI packages inside it, about 16 MB
of a 7.4 GB image, so only those files are read with HTTP range requests (the image is ISO 9660
without extensions; the table is read from its first sectors). Every package is then checked
against `tools/verifier/vs2015-u2-packages.json` (SHA-256 and size) before it is opened, the
MSIs are extracted with `msiexec /a` on Windows or `msiextract` elsewhere, and the four compiler
binaries are checked against `tools/verifier/pinned/19.00.23918.sha256`. Nothing else from the
image, and nothing from any other host, is used.

The result is `DIR/VC/Tools/MSVC/14.00.23918/{bin/Hostx64/x64,include,lib/x64}` in the layout of the
pinned 2017 install, plus `DIR/Windows Kits` copied from `--sdk-from` (the pinned install's SDK;
the recipe names SDK 10.0.19041.0 for every toolset) and the two VC runtime DLLs the compiler
process loads, copied from that install's toolset. Standard library only.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import tempfile
import time
import urllib.request

HERE = Path(__file__).resolve().parent
ISO_URL = 'https://download.microsoft.com/download/f/d/c/fdce5d40-87d3-4bd6-9139-2a7638b96174/vs2015.2.com_enu.iso'
ISO_HOSTS = ('download.microsoft.com',)
TOOLSET = '19.00.23918'
VERSION_DIR = '14.00.23918'
PACKAGES = HERE / 'vs2015-u2-packages.json'
PINS = HERE / 'pinned' / f'{TOOLSET}.sha256'
# The VC 14.0 packages of the x64-hosted, x64-targeting compiler (core, base and native tools, each
# with its English resources) and the CRT headers, as directories of the image. Each directory's
# files are fetched whole. The same image also carries the VC 12.0 packages (vc_*), which are not
# this compiler. The CRT libraries (about 55 MB) are not needed: units are only compiled.
VC_DIR = 'packages/VisualC_D14'
PACKAGE_DIRS = tuple(f'{VC_DIR}/{name}' for name in (
    'VC_Tools.Core', 'VC_Tools.Core.Res/enu', 'VC_Tools.X64.Base', 'VC_Tools.X64.Base.Res/enu',
    'VC_Tools.X64.Nat', 'VC_Tools.X64.Nat.Res/enu', 'VC_CRT.Headers'))
RUNTIME_DLLS = ('msvcp140.dll', 'vcruntime140.dll')
SECTOR = 2048
BLOCK = 1 << 19


class SetupError(Exception):
    pass


def _writable(func, path, exc_info):
    os.chmod(path, 0o700)
    func(path)


def rmtree(path):
    """Remove a tree whose files may be read-only (msiexec extracts them so on Windows)."""
    if sys.version_info >= (3, 12):
        shutil.rmtree(path, onexc=lambda func, p, exc: _writable(func, p, exc))
    else:
        shutil.rmtree(path, onerror=_writable)


def merge_copy(src, dest):
    """copytree's copy function for merging packages: a file two packages both carry must be identical."""
    if os.path.exists(dest):
        if sha256_file(src) != sha256_file(dest):
            raise SetupError(f'two packages carry different {os.path.basename(dest)}')
        return dest
    return shutil.copy2(src, dest)


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, 'rb') as stream:
        for chunk in iter(lambda: stream.read(1 << 20), b''):
            h.update(chunk)
    return h.hexdigest()


class Source:
    """Random access to the image: a local file, or the official URL read in aligned blocks."""

    def __init__(self, iso=None):
        self.iso, self.cache, self.fetched = iso, {}, 0
        if iso:
            self.size = Path(iso).stat().st_size
        else:
            head = urllib.request.Request(ISO_URL, method='HEAD')
            with urllib.request.urlopen(head, timeout=60) as response:
                if response.url.split('/')[2] not in ISO_HOSTS:
                    raise SetupError('image redirected away from download.microsoft.com')
                self.size = int(response.headers['Content-Length'])

    def _block(self, index):
        if index not in self.cache:
            start = index * BLOCK
            end = min(self.size, start + BLOCK) - 1
            last = None
            for attempt in range(6):
                try:
                    request = urllib.request.Request(ISO_URL, headers={'Range': f'bytes={start}-{end}'})
                    with urllib.request.urlopen(request, timeout=60) as response:
                        data = response.read()
                    if len(data) != end - start + 1:
                        raise OSError('short range response')
                    self.cache[index] = data
                    self.fetched += len(data)
                    break
                except OSError as exc:
                    last = exc
                    time.sleep(1 + attempt)
            else:
                raise SetupError(f'cannot read the image: {last}')
        return self.cache[index]

    def read(self, offset, length):
        if self.iso:
            with open(self.iso, 'rb') as stream:
                stream.seek(offset)
                return stream.read(length)
        out = []
        while length > 0:
            index, inner = divmod(offset, BLOCK)
            chunk = self._block(index)[inner:inner + length]
            if not chunk:
                raise SetupError('read past the end of the image')
            out.append(chunk)
            offset += len(chunk)
            length -= len(chunk)
        return b''.join(out)

    def stream_to(self, offset, length, dest):
        """Copy `length` bytes at `offset` to `dest` without keeping them in the block cache."""
        with open(dest, 'wb') as out:
            done = 0
            while done < length:
                n = min(1 << 22, length - done)
                if self.iso:
                    out.write(self.read(offset + done, n))
                else:
                    request = urllib.request.Request(ISO_URL, headers={
                        'Range': f'bytes={offset + done}-{offset + done + n - 1}'})
                    for attempt in range(6):
                        try:
                            with urllib.request.urlopen(request, timeout=120) as response:
                                data = response.read()
                            if len(data) == n:
                                out.write(data)
                                self.fetched += n
                                break
                        except OSError:
                            pass
                        time.sleep(1 + attempt)
                    else:
                        raise SetupError('cannot read a package from the image')
                done += n


def records(source, extent, length):
    """The directory records of one ISO 9660 directory: (name, is_dir, extent, size)."""
    data = source.read(extent * SECTOR, length)
    pos = 0
    out = []
    while pos < len(data):
        size = data[pos]
        if size == 0:
            pos = (pos // SECTOR + 1) * SECTOR
            continue
        rec = data[pos:pos + size]
        pos += size
        loc, = struct.unpack('<I', rec[2:6])
        flen, = struct.unpack('<I', rec[10:14])
        flags = rec[25]
        name = rec[33:33 + rec[32]]
        if name in (b'\x00', b'\x01'):
            continue
        text = name.decode('latin-1').split(';')[0]
        out.append((text, bool(flags & 2), loc, flen))
    return out


def find_dir(source, path):
    """(extent, length) of the directory `path` (names separated by '/'), from the primary descriptor."""
    pvd = source.read(16 * SECTOR, SECTOR)
    if pvd[0] != 1 or pvd[1:6] != b'CD001':
        raise SetupError('not an ISO 9660 image')
    root = pvd[156:190]
    extent, = struct.unpack('<I', root[2:6])
    length, = struct.unpack('<I', root[10:14])
    for part in path.split('/'):
        for name, is_dir, loc, size in records(source, extent, length):
            if is_dir and name.lower() == part.lower():
                extent, length = loc, size
                break
        else:
            raise SetupError(f'{part} is not in the image')
    return extent, length


def package_files(source):
    """{relative path: (offset, size)} of every file of the PACKAGE_DIRS directories."""
    out = {}
    for directory in PACKAGE_DIRS:
        extent, length = find_dir(source, directory)
        for name, is_dir, loc, size in records(source, extent, length):
            if not is_dir:
                out[f'{directory}/{name}'] = (loc * SECTOR, size)
    return out


def table(source, work):
    """The package table to pin: path, size and SHA-256 of each file, read from the image."""
    rows = []
    for rel, (offset, size) in sorted(package_files(source).items()):
        dest = Path(work) / rel
        dest.parent.mkdir(parents=True, exist_ok=True)
        source.stream_to(offset, size, dest)
        rows.append({'path': rel, 'size': size, 'sha256': sha256_file(dest)})
    return rows


def fetch_packages(source, work):
    """Download the pinned packages into `work`, each checked against the checked-in table."""
    expected = json.loads(PACKAGES.read_text())
    files = package_files(source)
    if sorted(files) != sorted(row['path'] for row in expected['packages']):
        raise SetupError('the image holds a different set of packages than the pin')
    for row in expected['packages']:
        offset, size = files[row['path']]
        if size != row['size']:
            raise SetupError(f'{row["path"]}: size differs from the pin')
        dest = Path(work) / row['path']
        dest.parent.mkdir(parents=True, exist_ok=True)
        if not dest.is_file() or sha256_file(dest) != row['sha256']:
            source.stream_to(offset, size, dest)
        if sha256_file(dest) != row['sha256']:
            dest.unlink()
            raise SetupError(f'{row["path"]}: SHA-256 differs from the pin')
    return expected


def extract_msi(msi, target):
    """Administrative extraction of one MSI (its cabinets sit beside it) into `target`."""
    target.mkdir(parents=True, exist_ok=True)
    if sys.platform == 'win32':
        cmd = ['msiexec', '/a', str(msi), '/qn', f'TARGETDIR={target}']
    else:
        cmd = ['msiextract', '-C', str(target), str(msi)]
    proc = subprocess.run(cmd, stdout=subprocess.DEVNULL, stderr=subprocess.PIPE, timeout=600)
    if proc.returncode != 0:
        raise SetupError(f'{Path(msi).name}: extraction failed ({proc.returncode})')


def find_vc(unpacked):
    """The `VC` directory of one extracted package (a package that holds none is not a VC package)."""
    found = sorted(path for path in Path(unpacked).rglob('VC') if path.is_dir())
    if not found:
        raise SetupError('extracted package holds no VC directory')
    return found[0]


def copy_tree(src, dest):
    """Copy a directory tree; a copy-on-write clone on macOS, where the SDK is over a gigabyte."""
    if sys.platform == 'darwin':
        if subprocess.run(['cp', '-cR', str(src), str(dest)], stderr=subprocess.DEVNULL).returncode == 0:
            return
        shutil.rmtree(dest, ignore_errors=True)
    shutil.copytree(src, dest)


def assemble(work, root, sdk_from=None, wrapper=False):
    """Lay the extracted packages out as `root`/VC/Tools/MSVC/14.00.23918 and verify the compiler."""
    unpacked = Path(work) / 'unpacked'
    if unpacked.exists():
        rmtree(unpacked)
    for msi in sorted((Path(work) / VC_DIR).rglob('*.msi')):
        # One directory per package so equal file names in different packages cannot collide.
        extract_msi(msi, unpacked / msi.parent.relative_to(Path(work) / VC_DIR).as_posix().replace('/', '_'))
    merged = Path(work) / 'merged'
    if merged.exists():
        rmtree(merged)
    merged.mkdir()
    for part in sorted(unpacked.iterdir()):
        vc = find_vc_or_none(part)
        if vc is not None:
            shutil.copytree(vc, merged / 'VC', dirs_exist_ok=True, copy_function=merge_copy)
    vc = merged / 'VC'
    tree = Path(root) / 'VC' / 'Tools' / 'MSVC' / VERSION_DIR
    if tree.exists():
        rmtree(tree)
    bindir = tree / 'bin' / 'Hostx64' / 'x64'
    shutil.copytree(vc / 'bin' / 'amd64', bindir)
    for extra in ('vcmeta.dll',):
        if (vc / 'bin' / extra).is_file():
            shutil.copy2(vc / 'bin' / extra, bindir / extra)
    shutil.copytree(vc / 'include', tree / 'include')
    (tree / 'lib' / 'x64').mkdir(parents=True, exist_ok=True)
    (tree / 'atlmfc' / 'include').mkdir(parents=True, exist_ok=True)
    if sdk_from:
        sdk = Path(sdk_from)
        for src in sorted((sdk / 'VC' / 'Tools' / 'MSVC').glob('*/bin/Hostx64/x64')):
            for dll in RUNTIME_DLLS:
                if not (bindir / dll).is_file() and (src / dll).is_file():
                    shutil.copy2(src / dll, bindir / dll)
        kits = sdk / 'Windows Kits'
        if kits.is_dir() and not (Path(root) / 'Windows Kits').exists():
            copy_tree(kits, Path(root) / 'Windows Kits')
        if wrapper:
            # The msvc-wine wrapper scripts of the pinned install, pointed at this toolset.
            wrap = sdk / 'bin'
            if not (wrap / 'x64' / 'msvcenv.sh').is_file():
                raise SetupError('--wrapper needs an msvc-wine install in --sdk-from')
            if not (Path(root) / 'bin').exists():
                copy_tree(wrap, Path(root) / 'bin')
            env = Path(root) / 'bin' / 'x64' / 'msvcenv.sh'
            env.write_text(''.join(f'MSVCVER={VERSION_DIR}\n' if line.startswith('MSVCVER=') else line
                                   for line in env.read_text().splitlines(keepends=True)))
            if not (Path(root) / 'kits').exists():
                (Path(root) / 'kits').symlink_to('Windows Kits')
    return bindir


def find_vc_or_none(part):
    try:
        return find_vc(part)
    except SetupError:
        return None


def verify_pins(bindir):
    pins = {}
    for line in PINS.read_text().splitlines():
        parts = line.split()
        if len(parts) == 2:
            pins[parts[1]] = parts[0]
    if sorted(pins) != ['c1xx.dll', 'c2.dll', 'cl.exe', 'link.exe']:
        raise SetupError(PINS.name + ' must pin cl.exe, c1xx.dll, c2.dll and link.exe')
    bad = [name for name, digest in pins.items()
           if not (bindir / name).is_file() or sha256_file(bindir / name) != digest]
    if bad:
        raise SetupError('compiler binaries differ from ' + PINS.name + ': ' + ', '.join(bad))
    return pins


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('command', choices=('install', 'pins'))
    parser.add_argument('--root', type=Path)
    parser.add_argument('--sdk-from', type=Path, help='an install whose Windows Kits and VC runtime DLLs to reuse')
    parser.add_argument('--iso', help='a local copy of the image (checked per package like the download)')
    parser.add_argument('--work', type=Path)
    parser.add_argument('--wrapper', action='store_true',
                        help='also lay out the msvc-wine wrapper of --sdk-from for this toolset (Wine hosts)')
    parser.add_argument('--accept-license', action='store_true',
                        help='use the compiler under Microsoft\'s Visual Studio 2015 Community terms (install only)')
    args = parser.parse_args(argv)
    work = args.work or Path(tempfile.mkdtemp(prefix='sr-u2-'))
    started = time.time()
    try:
        if args.command == 'install' and not args.accept_license:
            print('error: pass --accept-license to use the compiler under the Visual Studio 2015 Community terms',
                  file=sys.stderr)
            return 7
        source = Source(args.iso)
        if args.command == 'pins':
            rows = table(source, work)
            print(json.dumps({'schema': 1, 'toolset': TOOLSET, 'image_url': ISO_URL, 'image_size': source.size,
                              'packages': rows}, indent=2))
            return 0
        if not args.root:
            parser.error('install needs --root')
        fetch_packages(source, work)
        bindir = assemble(work, args.root, args.sdk_from, args.wrapper)
        verify_pins(bindir)
        print(f'vs2015 update 2 compiler installed at {bindir}: pins match; read {source.fetched} bytes of the image '
              f'in {time.time() - started:.0f} s')
        if os.environ.get('GITHUB_OUTPUT'):
            with open(os.environ['GITHUB_OUTPUT'], 'a') as out:
                out.write(f'bin={bindir}\n')
        return 0
    except (SetupError, OSError, subprocess.SubprocessError, ValueError) as exc:
        print(f'error: {exc}', file=sys.stderr)
        return 1
    finally:
        if not args.work and Path(work).exists():
            rmtree(work)


if __name__ == '__main__':
    sys.exit(main())
