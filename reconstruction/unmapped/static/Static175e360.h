// Source exposure: binary-analysis; no external implementation source reused.
// Static175e360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e360*);
    virtual void release(Static175e360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e360*);
struct Static175e360 {
    void* value;
    Static175e360();
    ~Static175e360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
