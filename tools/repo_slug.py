"""Single source for the GitHub repository slug used by tooling.

The repository moved from a personal account to an organisation; the old
name is kept as an alias so stale remotes and runner configs still match.
"""
import os

DEFAULT_SLUG = 'Mudcrab-Team/skyrim_decomp'
LEGACY_SLUGS = ('awarebayes/skyrim_decomp', 'awarebayes/skyrim-research')
# The maintainer is a person; bot comments and author checks use this login.
MAINTAINER_LOGIN = 'awarebayes'


def current_slug(env=None):
    """Slug for API calls: GITHUB_REPOSITORY when set, else the default."""
    value = ((env if env is not None else os.environ).get('GITHUB_REPOSITORY') or '').strip()
    return value if value.count('/') == 1 and ' ' not in value else DEFAULT_SLUG


def canonical(slug):
    """Lower-cased slug with legacy names mapped to the current one."""
    slug = (slug or '').strip().strip('/').lower()
    if slug.endswith('.git'):
        slug = slug[:-4]
    if slug in {s.lower() for s in LEGACY_SLUGS}:
        return DEFAULT_SLUG.lower()
    return slug


def same_repo(a, b):
    return bool(canonical(a)) and canonical(a) == canonical(b)


def aliases(slug=None):
    """Every lower-cased name that denotes the project repository."""
    return {DEFAULT_SLUG.lower(), *(s.lower() for s in LEGACY_SLUGS), (slug or current_slug()).lower()}
