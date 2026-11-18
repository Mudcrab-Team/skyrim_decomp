// Source exposure: binary-analysis; no external implementation source reused.
// Static174d350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d350*);
    virtual void release(Static174d350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d350*);
struct Static174d350 {
    void* value;
    Static174d350();
    ~Static174d350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
