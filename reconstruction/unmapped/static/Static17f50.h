// Source exposure: binary-analysis
// Static17f50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static17f50;
extern void construct(Static17f50*, const Descriptor*);
extern void destroy(Static17f50*);
struct Static17f50 {
    void* value;
    Static17f50() { construct(this, &descriptor); }
    ~Static17f50() { destroy(this); }
};
