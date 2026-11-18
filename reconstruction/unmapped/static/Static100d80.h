// Source exposure: binary-analysis
// Static100d80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100d80;
extern void construct(Static100d80*, const Descriptor*);
extern void destroy(Static100d80*);
struct Static100d80 {
    void* value;
    Static100d80() { construct(this, &descriptor); }
    ~Static100d80() { destroy(this); }
};
