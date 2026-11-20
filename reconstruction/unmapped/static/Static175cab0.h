// Source exposure: binary-analysis; no external implementation source reused.
// Static175cab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cab0*);
    virtual void release(Static175cab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cab0*);
struct Static175cab0 {
    void* value;
    Static175cab0();
    ~Static175cab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
