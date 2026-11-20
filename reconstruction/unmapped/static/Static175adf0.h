// Source exposure: binary-analysis; no external implementation source reused.
// Static175adf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175adf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175adf0*);
    virtual void release(Static175adf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175adf0*);
struct Static175adf0 {
    void* value;
    Static175adf0();
    ~Static175adf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
