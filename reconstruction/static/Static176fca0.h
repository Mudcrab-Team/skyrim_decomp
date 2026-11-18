// Source exposure: binary-analysis; no external implementation source reused.
// Static176fca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fca0*);
    virtual void release(Static176fca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fca0*);
struct Static176fca0 {
    void* value;
    Static176fca0();
    ~Static176fca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
