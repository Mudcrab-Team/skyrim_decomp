// Source exposure: binary-analysis
// Static108360, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108360;
extern void construct(Static108360*, const Descriptor*);
extern void destroy(Static108360*);
struct Static108360 {
    void* value;
    Static108360() { construct(this, &descriptor); }
    ~Static108360() { destroy(this); }
};
