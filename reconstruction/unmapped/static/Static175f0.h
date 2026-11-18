// Source exposure: binary-analysis
// Static175f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static175f0;
extern void construct(Static175f0*, const Descriptor*);
extern void destroy(Static175f0*);
struct Static175f0 {
    void* value;
    Static175f0() { construct(this, &descriptor); }
    ~Static175f0() { destroy(this); }
};
