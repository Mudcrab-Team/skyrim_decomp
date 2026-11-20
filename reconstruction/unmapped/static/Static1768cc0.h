// Source exposure: binary-analysis; no external implementation source reused.
// Static1768cc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768cc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768cc0*);
    virtual void release(Static1768cc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768cc0*);
struct Static1768cc0 {
    void* value;
    Static1768cc0();
    ~Static1768cc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
