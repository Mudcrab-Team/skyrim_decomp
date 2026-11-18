// Source exposure: binary-analysis
// Static1ada0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1ada0;
extern void construct(Static1ada0*, const Descriptor*);
extern void destroy(Static1ada0*);
struct Static1ada0 {
    void* value;
    Static1ada0() { construct(this, &descriptor); }
    ~Static1ada0() { destroy(this); }
};
