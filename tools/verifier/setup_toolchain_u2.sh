#!/usr/bin/env bash
# Install the VS2015 Update 2 (19.00.23918) x64 compiler next to the pinned 19.16.27054 install, for
# units whose recipe names it (Havok code; tools/verifier/toolsets.py). The pinned install is not
# touched. The compiler comes from Microsoft's own Visual Studio 2015 Update 2 Community image on
# download.microsoft.com: tools/verifier/vs2015_u2.py reads only the compiler packages (about 16 MB
# of the 7.4 GB image) with range requests and checks each against tools/verifier/vs2015-u2-packages.json
# by SHA-256; the four compiler binaries are then checked against pinned/19.00.23918.sha256.
#
# Running this script uses Microsoft's Visual Studio 2015 Community terms for the compiler, so it
# needs --accept-license: pass it only where that basis is recorded for your use.
#
# Usage: setup_toolchain_u2.sh --accept-license <pinned-toolchain-dir> [out-dir] [--iso FILE]
#   out-dir defaults to the pinned directory's parent; the result is <out-dir>/msvc-19.00.23918.
# Needs: python3, msitools (msiextract), and an APFS volume or any `cp -R`. The wrapper scripts and
# Windows SDK of the pinned install are reused (the recipe names SDK 10.0.19041.0 for every toolset),
# with only VC/Tools/MSVC replaced; the two VC runtime DLLs the compiler process loads come from the
# pinned install's toolset and do not affect the object code.
set -euo pipefail
HERE=$(cd "$(dirname "$0")" && pwd)
ACCEPT=0; ISO=()
ARGS=()
while [ $# -gt 0 ]; do
    case "$1" in
        --accept-license) ACCEPT=1 ;;
        --iso) ISO=(--iso "$2"); shift ;;
        *) ARGS+=("$1") ;;
    esac
    shift
done
[ "$ACCEPT" = 1 ] || { echo "pass --accept-license to use the Visual Studio 2015 Community terms for this compiler" >&2; exit 7; }
PINNED=$(cd "${ARGS[0]:?pinned toolchain dir}" && pwd)
OUT=${ARGS[1]:-$(dirname "$PINNED")}
ID=19.00.23918
DIR="$OUT/msvc-$ID"
WORK=${WORK:-$HERE/../../.local/verifier-u2-setup}
mkdir -p "$WORK"
command -v msiextract >/dev/null || { echo "msiextract (msitools) is required: brew install msitools" >&2; exit 5; }

rm -rf "$DIR"; mkdir -p "$DIR"
python3 -I "$HERE/vs2015_u2.py" install --accept-license --root "$DIR" --sdk-from "$PINNED" --wrapper \
    --work "$WORK/work" ${ISO[@]+"${ISO[@]}"}
(cd "$DIR/VC/Tools/MSVC/14.00.23918/bin/Hostx64/x64" && shasum -a 256 -c "$HERE/pinned/$ID.sha256")
echo "done: $DIR"
