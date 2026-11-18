// Source exposure: binary-analysis
// Static1b860, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b860;
extern void construct(Static1b860*, const Descriptor*);
extern void destroy(Static1b860*);
struct Static1b860 {
    void* value;
    Static1b860() { construct(this, &descriptor); }
    ~Static1b860() { destroy(this); }
};
