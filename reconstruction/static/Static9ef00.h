// Source exposure: binary-analysis
// Static9ef00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ef00;
extern void construct(Static9ef00*, const Descriptor*);
extern void destroy(Static9ef00*);
struct Static9ef00 {
    void* value;
    Static9ef00() { construct(this, &descriptor); }
    ~Static9ef00() { destroy(this); }
};
