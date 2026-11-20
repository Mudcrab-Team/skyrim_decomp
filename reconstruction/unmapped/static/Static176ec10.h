// Source exposure: binary-analysis; no external implementation source reused.
// Static176ec10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ec10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ec10*);
    virtual void release(Static176ec10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ec10*);
struct Static176ec10 {
    void* value;
    Static176ec10();
    ~Static176ec10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
