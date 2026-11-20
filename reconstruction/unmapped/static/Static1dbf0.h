// Source exposure: binary-analysis
// Static1dbf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dbf0;
extern void construct(Static1dbf0*, const Descriptor*);
extern void destroy(Static1dbf0*);
struct Static1dbf0 {
    void* value;
    Static1dbf0() { construct(this, &descriptor); }
    ~Static1dbf0() { destroy(this); }
};
