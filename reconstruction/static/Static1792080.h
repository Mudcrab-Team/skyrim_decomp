// Source exposure: binary-analysis
// Static1792080, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static1792080;
extern void construct(Static1792080*);
struct Static1792080 {
    Static1792080() { construct(this); }
    ~Static1792080() {}
};
