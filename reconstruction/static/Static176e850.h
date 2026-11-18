// Source exposure: binary-analysis; no external implementation source reused.
// Static176e850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e850*);
    virtual void release(Static176e850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e850*);
struct Static176e850 {
    void* value;
    Static176e850();
    ~Static176e850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
