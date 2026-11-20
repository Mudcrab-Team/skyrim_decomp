// Source exposure: binary-analysis; no external implementation source reused.
// Static175e400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e400*);
    virtual void release(Static175e400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e400*);
struct Static175e400 {
    void* value;
    Static175e400();
    ~Static175e400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
