// Source exposure: binary-analysis
// Static1abc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1abc0;
extern void construct(Static1abc0*, const Descriptor*);
extern void destroy(Static1abc0*);
struct Static1abc0 {
    void* value;
    Static1abc0() { construct(this, &descriptor); }
    ~Static1abc0() { destroy(this); }
};
