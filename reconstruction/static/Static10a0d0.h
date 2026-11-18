// Source exposure: binary-analysis
// Static10a0d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a0d0;
extern void construct(Static10a0d0*, const Descriptor*);
extern void destroy(Static10a0d0*);
struct Static10a0d0 {
    void* value;
    Static10a0d0() { construct(this, &descriptor); }
    ~Static10a0d0() { destroy(this); }
};
