For a function-only contribution, use the [function intake template](PULL_REQUEST_TEMPLATE/function.md)
or `python3 tools/contrib.py submit`. Project acceptance follows that submission; it is not a prerequisite.
The checklist below is for tooling and research changes.

## Change and evidence

Describe the result, exact target/source revisions, reproduction and limitations.

## Publication and provenance

- [ ] I read LEGAL.md, PROVENANCE.md and the licensing scope, and can contribute this material.
- [ ] No game bytes, raw exports, dumps, proprietary symbols, assets, secrets or unlicensed code
  (FNV decompilation material allowed by the maintainer decision aside, labelled `SIBLING`).
- [ ] External sources, AI assistance and source exposure are declared.
- [ ] Match/behavior claims cite existing acceptance evidence; local or CI passes are not called
  project matches. Any implementation transfer has the `docs/clean-room.md` boundary review.
- [ ] Progress describes real results; infrastructure CI is not presented as a Skyrim match.

## Validation

- [ ] `python3 tools/check.py --staged` before commit
- [ ] `python3 tools/check.py`
- [ ] `python3 -m unittest discover -s tests -v`
- [ ] `python3 tools/build_site.py`
