#!/bin/sh
# Supervisor entry for the PR bot. Refreshes the checkout this script lives in from origin/main, then
# polls for an hour and exits so the service manager restarts it on current tools.
#   SR_BOT_ROOT  checkout that holds .local and the git history (required)
set -e
here=$(cd "$(dirname "$0")/.." && pwd)
: "${SR_BOT_ROOT:?SR_BOT_ROOT must name the checkout holding .local}"
git -C "$here" fetch -q --depth 1 origin main
git -C "$here" reset -q --hard FETCH_HEAD
exec "${SR_BOT_PYTHON:-python3}" "$here/tools/pr_bot.py" --poll --interval 60 --restart-after 3600 --root "$SR_BOT_ROOT"
