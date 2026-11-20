// Source exposure: binary-analysis
// Static97570, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97570;
extern void construct(Static97570*, const Descriptor*);
extern void destroy(Static97570*);
struct Static97570 {
    void* value;
    Static97570() { construct(this, &descriptor); }
    ~Static97570() { destroy(this); }
};
