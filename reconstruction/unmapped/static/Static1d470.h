// Source exposure: binary-analysis
// Static1d470, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d470;
extern void construct(Static1d470*, const Descriptor*);
extern void destroy(Static1d470*);
struct Static1d470 {
    void* value;
    Static1d470() { construct(this, &descriptor); }
    ~Static1d470() { destroy(this); }
};
