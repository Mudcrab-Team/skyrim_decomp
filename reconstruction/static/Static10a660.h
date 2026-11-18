// Source exposure: binary-analysis
// Static10a660, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a660;
extern void construct(Static10a660*, const Descriptor*);
extern void destroy(Static10a660*);
struct Static10a660 {
    void* value;
    Static10a660() { construct(this, &descriptor); }
    ~Static10a660() { destroy(this); }
};
