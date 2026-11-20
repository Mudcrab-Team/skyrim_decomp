// Source exposure: binary-analysis; no external implementation source reused.
// Static1792ea0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792ea0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792ea0*);
    virtual void release(Static1792ea0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792ea0*);
struct Static1792ea0 {
    void* value;
    Static1792ea0();
    ~Static1792ea0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
