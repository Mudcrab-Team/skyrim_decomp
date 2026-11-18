// Source exposure: binary-analysis; no external implementation source reused.
// Static1763fe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763fe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763fe0*);
    virtual void release(Static1763fe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763fe0*);
struct Static1763fe0 {
    void* value;
    Static1763fe0();
    ~Static1763fe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
