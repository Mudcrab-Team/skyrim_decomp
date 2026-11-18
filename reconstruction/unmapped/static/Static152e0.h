// Source exposure: binary-analysis
// Static152e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static152e0;
extern void construct(Static152e0*, const Descriptor*);
extern void destroy(Static152e0*);
struct Static152e0 {
    void* value;
    Static152e0() { construct(this, &descriptor); }
    ~Static152e0() { destroy(this); }
};
