// Source exposure: binary-analysis
// Static1aef0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1aef0;
extern void construct(Static1aef0*, const Descriptor*);
extern void destroy(Static1aef0*);
struct Static1aef0 {
    void* value;
    Static1aef0() { construct(this, &descriptor); }
    ~Static1aef0() { destroy(this); }
};
