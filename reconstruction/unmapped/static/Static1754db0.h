// Source exposure: binary-analysis; no external implementation source reused.
// Static1754db0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754db0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754db0*);
    virtual void release(Static1754db0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754db0*);
struct Static1754db0 {
    void* value;
    Static1754db0();
    ~Static1754db0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
