// Source exposure: binary-analysis; no external implementation source reused.
// Static175e3b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e3b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e3b0*);
    virtual void release(Static175e3b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e3b0*);
struct Static175e3b0 {
    void* value;
    Static175e3b0();
    ~Static175e3b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
