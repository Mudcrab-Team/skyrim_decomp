#!/usr/bin/env bash
# Install the side-by-side MSVC toolsets that tools/verifier/compiler_sweep.py compares, next to the
# pinned 19.16.27054 install, without touching it. Packages come from the same pinned VS 2017 15.9.85
# installer manifest and msvc-wine commit as setup_toolchain.sh (vsdownload.py checks each payload
# against the manifest); the compiler binaries are then checked against tools/verifier/pinned/<id>.sha256.
#
# Usage: setup_sweep_toolchains.sh <pinned-toolchain-dir> [out-dir]   (out-dir default: its parent)
# Needs: git, curl, python3, msiextract (msitools) for the VS2015 toolset, APFS or any cp -R.
# Each toolset directory reuses the pinned install's wrapper scripts and Windows SDK, with only
# VC/Tools/MSVC replaced. The v140 toolset ships without the VS2015 C++ runtime DLLs the compiler
# process loads, so the three the 15.9 toolset directory carries are copied in (they do not affect the
# object code).
set -euo pipefail
HERE=$(cd "$(dirname "$0")" && pwd)
PINNED=$(cd "${1:?pinned toolchain dir}" && pwd)
OUT=${2:-$(dirname "$PINNED")}
WORK=${WORK:-$HERE/../../.local/verifier-sweep-setup}
mkdir -p "$WORK"
read_pin() { sed -n "s/^$1=//p" "$HERE/setup_toolchain.sh" | head -n1; }
COMMIT=$(read_pin MSVC_WINE_COMMIT); URL=$(read_pin VSMAN_URL); SHA=$(read_pin VSMAN_SHA256)
[ -d "$WORK/msvc-wine/.git" ] || git clone -q "$(read_pin MSVC_WINE_URL)" "$WORK/msvc-wine"
git -C "$WORK/msvc-wine" -c advice.detachedHead=false checkout -q "$COMMIT"
curl -fsSL -o "$WORK/VisualStudio.vsman" "$URL"
echo "$SHA  $WORK/VisualStudio.vsman" | shasum -a 256 -c -

fetch() { # <dest> <package...>
    local dest=$1; shift
    python3 -I "$WORK/msvc-wine/vsdownload.py" --manifest "$WORK/VisualStudio.vsman" --major 15 \
        --host-arch x64 --architecture x64 --with-default no --with-msvc no --with-sdk no --with-asan no \
        --with-atl no --with-dia no --with-msbuild no --with-devcmd no --skip-recommended --accept-license \
        --cache "$WORK/cache" --dest "$dest" "$@" >/dev/null
}
assemble() { # <id> <toolset dir of VC/Tools/MSVC/<ver>>
    local id=$1 src=$2 ver; ver=$(basename "$src")
    local dir="$OUT/msvc-$id"
    rm -rf "$dir"; mkdir -p "$dir/VC/Tools/MSVC"
    for x in bin "Windows Kits"; do cp -cR "$PINNED/$x" "$dir/$x" 2>/dev/null || cp -R "$PINNED/$x" "$dir/$x"; done
    ln -s "Windows Kits" "$dir/kits"
    cp -R "$src" "$dir/VC/Tools/MSVC/$ver"
    sed -i.bak "s/^MSVCVER=.*/MSVCVER=$ver/" "$dir/bin/x64/msvcenv.sh"; rm -f "$dir/bin/x64/msvcenv.sh.bak"
    (cd "$dir/VC/Tools/MSVC/$ver/bin/Hostx64/x64" && shasum -a 256 -c "$HERE/pinned/$id.sha256")
}

for V in 14.11:19.11.25548 14.12:19.12.25835 14.13:19.13.26132 14.14:19.14.26433 14.15:19.15.26731; do
    short=${V%%:*}; id=${V##*:}
    fetch "$WORK/dl-$short" "Microsoft.VisualC.$short.Tools.HostX64.TargetX64" \
        "Microsoft.VisualC.$short.CRT.Headers" "Microsoft.VisualC.$short.CRT.x64.Desktop"
    assemble "$id" "$(ls -d "$WORK/dl-$short"/VC/Tools/MSVC/*)"
done

# VS2015 Update 3 (v140): MSI packages in the old VC/bin/amd64 layout, rearranged to the 2017 one.
fetch "$WORK/dl-v140" Microsoft.VisualC.140.Tools.HostX64.TargetX64.Msi Microsoft.VisualC.140.Tools.Base.X64.Msi \
    Microsoft.VisualC.140.Tools.Core.Msi Microsoft.VisualC.140.CRT.Headers.Msi Microsoft.VisualC.140.CRT.x64.Desktop.Msi || true
rm -rf "$WORK/v140x"; mkdir -p "$WORK/v140x"
for m in "$WORK"/cache/Microsoft.VisualC.140.*/*.msi; do msiextract -C "$WORK/v140x" "$m" >/dev/null; done
VC="$WORK/v140x/Program Files/Microsoft Visual Studio 14.0/VC"
T="$WORK/v140-tree/14.00.24247"; rm -rf "$WORK/v140-tree"; mkdir -p "$T/bin/Hostx64" "$T/lib"
cp -R "$VC/bin/amd64" "$T/bin/Hostx64/x64"; cp "$VC/bin/vcmeta.dll" "$T/bin/Hostx64/x64/"
cp -R "$VC/include" "$T/include"; cp -R "$VC/lib/amd64" "$T/lib/x64"; mkdir -p "$T/atlmfc/include"
for f in msvcp140.dll vcruntime140.dll; do
    [ -e "$T/bin/Hostx64/x64/$f" ] || cp "$(ls -d "$PINNED"/VC/Tools/MSVC/*)/bin/Hostx64/x64/$f" "$T/bin/Hostx64/x64/"
done
assemble 19.00.24247 "$T"
echo "done: toolsets under $OUT/msvc-<id>"
