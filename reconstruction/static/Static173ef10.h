// Source exposure: binary-analysis; no external implementation source reused.
// Static173ef10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ef10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ef10*);
    virtual void release(Static173ef10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ef10*);
struct Static173ef10 {
    void* value;
    Static173ef10();
    ~Static173ef10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
