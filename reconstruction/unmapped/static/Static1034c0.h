// Source exposure: binary-analysis
// Static1034c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1034c0;
extern void construct(Static1034c0*, const Descriptor*);
extern void destroy(Static1034c0*);
struct Static1034c0 {
    void* value;
    Static1034c0() { construct(this, &descriptor); }
    ~Static1034c0() { destroy(this); }
};
