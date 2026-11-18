// Source exposure: binary-analysis; no external implementation source reused.
// Static175acb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175acb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175acb0*);
    virtual void release(Static175acb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175acb0*);
struct Static175acb0 {
    void* value;
    Static175acb0();
    ~Static175acb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
