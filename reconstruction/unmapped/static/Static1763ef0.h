// Source exposure: binary-analysis; no external implementation source reused.
// Static1763ef0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763ef0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763ef0*);
    virtual void release(Static1763ef0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763ef0*);
struct Static1763ef0 {
    void* value;
    Static1763ef0();
    ~Static1763ef0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
