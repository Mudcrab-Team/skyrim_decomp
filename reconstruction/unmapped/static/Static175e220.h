// Source exposure: binary-analysis; no external implementation source reused.
// Static175e220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e220*);
    virtual void release(Static175e220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e220*);
struct Static175e220 {
    void* value;
    Static175e220();
    ~Static175e220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
