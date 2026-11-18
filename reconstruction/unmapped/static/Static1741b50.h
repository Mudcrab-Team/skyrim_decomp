// Source exposure: binary-analysis
// Static1741b50, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static1741b50;
extern void construct(Static1741b50*);
struct Static1741b50 {
    Static1741b50() { construct(this); }
    ~Static1741b50() {}
};
