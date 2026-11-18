// Source exposure: binary-analysis; no external implementation source reused.
// Static175fe90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fe90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fe90*);
    virtual void release(Static175fe90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fe90*);
struct Static175fe90 {
    void* value;
    Static175fe90();
    ~Static175fe90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
