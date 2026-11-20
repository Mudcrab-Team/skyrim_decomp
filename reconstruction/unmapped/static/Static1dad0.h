// Source exposure: binary-analysis
// Static1dad0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dad0;
extern void construct(Static1dad0*, const Descriptor*);
extern void destroy(Static1dad0*);
struct Static1dad0 {
    void* value;
    Static1dad0() { construct(this, &descriptor); }
    ~Static1dad0() { destroy(this); }
};
