// Source exposure: binary-analysis
// Static1b220, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b220;
extern void construct(Static1b220*, const Descriptor*);
extern void destroy(Static1b220*);
struct Static1b220 {
    void* value;
    Static1b220() { construct(this, &descriptor); }
    ~Static1b220() { destroy(this); }
};
