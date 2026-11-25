#!/bin/sh
# Deploy a pr_bot revision only after it has run, with every write refused, against the PRs open right now.
#
#   tools/pr_bot_deploy.sh SHA [--allow-stale]
#
# SHA must contain origin/main (be at its head or ahead of it); a revision behind it is refused unless
# --allow-stale is given, since a stale pin runs the bot without fixes that already landed.
#
# Environment (all required except the last three):
#   SR_BOT_ROOT     checkout holding .local and the origin remote, as passed to pr_bot.py --root
#   SR_BOT_SRC      the checkout the service runs pr_bot.py from
#   SR_BOT_PYTHON   interpreter for the bot
#   SR_BOT_ENV      optional shell file of exports the service needs (runner config, paths), sourced first
#   SR_BOT_LABEL    optional launchd label to kickstart when no pin is configured
#   SR_BOT_PIN      optional file the deploy writes the SHA to; a service wrapper that refreshes SR_BOT_SRC
#                   from main on restart should check out this SHA instead. The running bot drains.
set -eu

sha=${1:?usage: pr_bot_deploy.sh SHA [--allow-stale]}
allow_stale=0
case "${2:-}" in
    "") ;;
    --allow-stale) allow_stale=1 ;;
    *) echo "unknown argument: $2" >&2; exit 2 ;;
esac
: "${SR_BOT_ROOT:?}" "${SR_BOT_SRC:?}" "${SR_BOT_PYTHON:?}"
[ -z "${SR_BOT_ENV:-}" ] || . "$SR_BOT_ENV"

# Best effort: a revision already present locally needs no fetch, and rev-parse below rejects an unknown one.
git -C "$SR_BOT_SRC" fetch -q origin "$sha" 2>/dev/null || git -C "$SR_BOT_SRC" fetch -q origin 2>/dev/null || true
sha=$(git -C "$SR_BOT_SRC" rev-parse --verify "$sha^{commit}")

# Refuse a revision that lacks the current origin/main. Skipped only when the checkout has no origin/main at all.
git -C "$SR_BOT_SRC" fetch -q origin main 2>/dev/null || true
if main=$(git -C "$SR_BOT_SRC" rev-parse --verify -q "refs/remotes/origin/main^{commit}") \
        && ! git -C "$SR_BOT_SRC" merge-base --is-ancestor "$main" "$sha"; then
    if [ "$allow_stale" = 1 ]; then
        echo "warning: $sha does not contain origin/main ($main); deploying anyway (--allow-stale)" >&2
    else
        echo "refusing $sha: it does not contain origin/main ($main); deploy origin/main HEAD or pass --allow-stale" >&2
        exit 1
    fi
fi

scratch=$(mktemp -d)
pin_tmp=
trap 'git -C "$SR_BOT_SRC" worktree remove --force "$scratch/code" >/dev/null 2>&1 || true; rm -rf "$scratch"; [ -z "$pin_tmp" ] || rm -f "$pin_tmp"' EXIT
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

# With a pin, keep the running checkout in place even if a launchd label is also set. The bot
# drains (--restart-on) and the wrapper checks out the new SHA after the process exits.
if [ -n "${SR_BOT_PIN:-}" ]; then
    pin_tmp=$(mktemp "$SR_BOT_PIN.XXXXXX")
    echo "$sha" > "$pin_tmp"
    mv -f "$pin_tmp" "$SR_BOT_PIN"
    pin_tmp=
    echo "pinned $sha; the running bot will drain before restarting"
else
    git -C "$SR_BOT_SRC" checkout -q --detach "$sha"
    if [ -n "${SR_BOT_LABEL:-}" ]; then
        launchctl kickstart -k "gui/$(id -u)/$SR_BOT_LABEL"
    fi
    echo "deployed $sha"
fi
