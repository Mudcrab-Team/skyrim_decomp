// Source exposure: binary-analysis
// Static15250, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15250;
extern void construct(Static15250*, const Descriptor*);
extern void destroy(Static15250*);
struct Static15250 {
    void* value;
    Static15250() { construct(this, &descriptor); }
    ~Static15250() { destroy(this); }
};
