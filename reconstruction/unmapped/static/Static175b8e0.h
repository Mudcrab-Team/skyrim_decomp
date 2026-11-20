// Source exposure: binary-analysis; no external implementation source reused.
// Static175b8e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b8e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b8e0*);
    virtual void release(Static175b8e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b8e0*);
struct Static175b8e0 {
    void* value;
    Static175b8e0();
    ~Static175b8e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
