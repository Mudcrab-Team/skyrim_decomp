// Source exposure: binary-analysis; no external implementation source reused.
// Static1763cc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763cc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763cc0*);
    virtual void release(Static1763cc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763cc0*);
struct Static1763cc0 {
    void* value;
    Static1763cc0();
    ~Static1763cc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
