// Source exposure: binary-analysis
// Static10a100, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a100;
extern void construct(Static10a100*, const Descriptor*);
extern void destroy(Static10a100*);
struct Static10a100 {
    void* value;
    Static10a100() { construct(this, &descriptor); }
    ~Static10a100() { destroy(this); }
};
