// Source exposure: binary-analysis
// Static209b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static209b0;
extern void construct(Static209b0*, const Descriptor*);
extern void destroy(Static209b0*);
struct Static209b0 {
    void* value;
    Static209b0() { construct(this, &descriptor); }
    ~Static209b0() { destroy(this); }
};
