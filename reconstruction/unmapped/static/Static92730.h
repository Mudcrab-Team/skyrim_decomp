// Source exposure: binary-analysis
// Static92730, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static92730;
extern void construct(Static92730*, const Descriptor*);
extern void destroy(Static92730*);
struct Static92730 {
    void* value;
    Static92730() { construct(this, &descriptor); }
    ~Static92730() { destroy(this); }
};
