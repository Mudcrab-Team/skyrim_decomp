// Source exposure: binary-analysis
// Static100ed0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100ed0;
extern void construct(Static100ed0*, const Descriptor*);
extern void destroy(Static100ed0*);
struct Static100ed0 {
    void* value;
    Static100ed0() { construct(this, &descriptor); }
    ~Static100ed0() { destroy(this); }
};
