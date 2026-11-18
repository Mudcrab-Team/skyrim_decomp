// Source exposure: binary-analysis; no external implementation source reused.
// Static1747ff0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747ff0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747ff0*);
    virtual void release(Static1747ff0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747ff0*);
struct Static1747ff0 {
    void* value;
    Static1747ff0();
    ~Static1747ff0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
