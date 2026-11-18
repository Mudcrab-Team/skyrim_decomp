// Source exposure: binary-analysis
// Staticb5460, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5460;
extern void construct(Staticb5460*, const Descriptor*);
extern void destroy(Staticb5460*);
struct Staticb5460 {
    void* value;
    Staticb5460() { construct(this, &descriptor); }
    ~Staticb5460() { destroy(this); }
};
