// Source exposure: binary-analysis
// Static103640, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103640;
extern void construct(Static103640*, const Descriptor*);
extern void destroy(Static103640*);
struct Static103640 {
    void* value;
    Static103640() { construct(this, &descriptor); }
    ~Static103640() { destroy(this); }
};
