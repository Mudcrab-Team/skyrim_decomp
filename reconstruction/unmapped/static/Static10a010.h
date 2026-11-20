// Source exposure: binary-analysis
// Static10a010, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a010;
extern void construct(Static10a010*, const Descriptor*);
extern void destroy(Static10a010*);
struct Static10a010 {
    void* value;
    Static10a010() { construct(this, &descriptor); }
    ~Static10a010() { destroy(this); }
};
