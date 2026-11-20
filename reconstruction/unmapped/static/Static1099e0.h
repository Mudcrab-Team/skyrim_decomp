// Source exposure: binary-analysis
// Static1099e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1099e0;
extern void construct(Static1099e0*, const Descriptor*);
extern void destroy(Static1099e0*);
struct Static1099e0 {
    void* value;
    Static1099e0() { construct(this, &descriptor); }
    ~Static1099e0() { destroy(this); }
};
