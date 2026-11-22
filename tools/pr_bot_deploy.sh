#!/bin/sh
# Deploy a pr_bot revision only after it has run, with every write refused, against the PRs open right now.
#
#   tools/pr_bot_deploy.sh SHA
#
# Environment (all required except the last three):
#   SR_BOT_ROOT     checkout holding .local and the origin remote, as passed to pr_bot.py --root
#   SR_BOT_SRC      the checkout the service runs pr_bot.py from
#   SR_BOT_PYTHON   interpreter for the bot
#   SR_BOT_ENV      optional shell file of exports the service needs (runner config, paths), sourced first
#   SR_BOT_LABEL    optional launchd label to kickstart; without it the service is not restarted
#   SR_BOT_PIN      optional file the deploy writes the SHA to; a service wrapper that refreshes SR_BOT_SRC
#                   from main on every restart should check out this SHA instead while the file exists
set -eu

sha=${1:?usage: pr_bot_deploy.sh SHA}
: "${SR_BOT_ROOT:?}" "${SR_BOT_SRC:?}" "${SR_BOT_PYTHON:?}"
[ -z "${SR_BOT_ENV:-}" ] || . "$SR_BOT_ENV"

# Best effort: a revision already present locally needs no fetch, and rev-parse below rejects an unknown one.
git -C "$SR_BOT_SRC" fetch -q origin "$sha" 2>/dev/null || git -C "$SR_BOT_SRC" fetch -q origin 2>/dev/null || true
sha=$(git -C "$SR_BOT_SRC" rev-parse --verify "$sha^{commit}")

scratch=$(mktemp -d)
trap 'git -C "$SR_BOT_SRC" worktree remove --force "$scratch/code" >/dev/null 2>&1 || true; rm -rf "$scratch"' EXIT
git -C "$SR_BOT_SRC" worktree add -q --detach "$scratch/code" "$sha"

# State is seeded from copies of the live files and written only under the scratch directory.
seed=
[ ! -d "$SR_BOT_ROOT/.local/pr-bot/state" ] || seed="--seed-state $SR_BOT_ROOT/.local/pr-bot/state"
echo "dry run of $sha against the open PRs"
# shellcheck disable=SC2086
if ! "$SR_BOT_PYTHON" "$scratch/code/tools/pr_bot.py" --dry-run --root "$SR_BOT_ROOT" --work "$scratch/work" $seed; then
    echo "dry run failed; $sha not deployed" >&2
    exit 1
fi

git -C "$SR_BOT_SRC" checkout -q --detach "$sha"
[ -z "${SR_BOT_PIN:-}" ] || echo "$sha" > "$SR_BOT_PIN"
if [ -n "${SR_BOT_LABEL:-}" ]; then
    launchctl kickstart -k "gui/$(id -u)/$SR_BOT_LABEL"
fi
echo "deployed $sha"
