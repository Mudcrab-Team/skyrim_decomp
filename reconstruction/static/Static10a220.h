// Source exposure: binary-analysis
// Static10a220, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a220;
extern void construct(Static10a220*, const Descriptor*);
extern void destroy(Static10a220*);
struct Static10a220 {
    void* value;
    Static10a220() { construct(this, &descriptor); }
    ~Static10a220() { destroy(this); }
};
