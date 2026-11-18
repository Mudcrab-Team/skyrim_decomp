// Source exposure: binary-analysis
// Static1d530, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d530;
extern void construct(Static1d530*, const Descriptor*);
extern void destroy(Static1d530*);
struct Static1d530 {
    void* value;
    Static1d530() { construct(this, &descriptor); }
    ~Static1d530() { destroy(this); }
};
