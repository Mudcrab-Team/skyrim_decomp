// Source exposure: binary-analysis; no external implementation source reused.
// Static175cc40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cc40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cc40*);
    virtual void release(Static175cc40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cc40*);
struct Static175cc40 {
    void* value;
    Static175cc40();
    ~Static175cc40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
