// Source exposure: binary-analysis; no external implementation source reused.
// Static175cce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cce0*);
    virtual void release(Static175cce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cce0*);
struct Static175cce0 {
    void* value;
    Static175cce0();
    ~Static175cce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
