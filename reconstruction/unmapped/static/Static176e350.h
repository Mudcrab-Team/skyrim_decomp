// Source exposure: binary-analysis; no external implementation source reused.
// Static176e350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e350*);
    virtual void release(Static176e350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e350*);
struct Static176e350 {
    void* value;
    Static176e350();
    ~Static176e350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
