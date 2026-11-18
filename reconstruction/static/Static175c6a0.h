// Source exposure: binary-analysis; no external implementation source reused.
// Static175c6a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c6a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c6a0*);
    virtual void release(Static175c6a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c6a0*);
struct Static175c6a0 {
    void* value;
    Static175c6a0();
    ~Static175c6a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
