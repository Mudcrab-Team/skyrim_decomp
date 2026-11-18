// Source exposure: binary-analysis
// Static97d80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97d80;
extern void construct(Static97d80*, const Descriptor*);
extern void destroy(Static97d80*);
struct Static97d80 {
    void* value;
    Static97d80() { construct(this, &descriptor); }
    ~Static97d80() { destroy(this); }
};
