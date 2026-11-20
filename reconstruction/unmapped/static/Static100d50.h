// Source exposure: binary-analysis
// Static100d50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100d50;
extern void construct(Static100d50*, const Descriptor*);
extern void destroy(Static100d50*);
struct Static100d50 {
    void* value;
    Static100d50() { construct(this, &descriptor); }
    ~Static100d50() { destroy(this); }
};
