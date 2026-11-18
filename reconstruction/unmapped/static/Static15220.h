// Source exposure: binary-analysis
// Static15220, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15220;
extern void construct(Static15220*, const Descriptor*);
extern void destroy(Static15220*);
struct Static15220 {
    void* value;
    Static15220() { construct(this, &descriptor); }
    ~Static15220() { destroy(this); }
};
