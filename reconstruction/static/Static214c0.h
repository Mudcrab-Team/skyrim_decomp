// Source exposure: binary-analysis
// Static214c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static214c0;
extern void construct(Static214c0*, const Descriptor*);
extern void destroy(Static214c0*);
struct Static214c0 {
    void* value;
    Static214c0() { construct(this, &descriptor); }
    ~Static214c0() { destroy(this); }
};
