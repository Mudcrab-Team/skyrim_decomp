// Source exposure: binary-analysis
// Static97d20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97d20;
extern void construct(Static97d20*, const Descriptor*);
extern void destroy(Static97d20*);
struct Static97d20 {
    void* value;
    Static97d20() { construct(this, &descriptor); }
    ~Static97d20() { destroy(this); }
};
