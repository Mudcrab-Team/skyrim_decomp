// Source exposure: binary-analysis; no external implementation source reused.
// Static175cbf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cbf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cbf0*);
    virtual void release(Static175cbf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cbf0*);
struct Static175cbf0 {
    void* value;
    Static175cbf0();
    ~Static175cbf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
