// Source exposure: binary-analysis; no external implementation source reused.
// Static176bf10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bf10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bf10*);
    virtual void release(Static176bf10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bf10*);
struct Static176bf10 {
    void* value;
    Static176bf10();
    ~Static176bf10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
