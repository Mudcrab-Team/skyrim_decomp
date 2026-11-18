// Source exposure: binary-analysis; no external implementation source reused.
// Static1789bc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789bc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789bc0*);
    virtual void release(Static1789bc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789bc0*);
struct Static1789bc0 {
    void* value;
    Static1789bc0();
    ~Static1789bc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
