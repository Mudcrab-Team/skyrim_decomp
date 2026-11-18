// Source exposure: binary-analysis; no external implementation source reused.
// Static175b5c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b5c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b5c0*);
    virtual void release(Static175b5c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b5c0*);
struct Static175b5c0 {
    void* value;
    Static175b5c0();
    ~Static175b5c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
