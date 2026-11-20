// Source exposure: binary-analysis; no external implementation source reused.
// Static174cee0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174cee0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174cee0*);
    virtual void release(Static174cee0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174cee0*);
struct Static174cee0 {
    void* value;
    Static174cee0();
    ~Static174cee0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
