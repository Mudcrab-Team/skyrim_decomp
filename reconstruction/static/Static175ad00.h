// Source exposure: binary-analysis; no external implementation source reused.
// Static175ad00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ad00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ad00*);
    virtual void release(Static175ad00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ad00*);
struct Static175ad00 {
    void* value;
    Static175ad00();
    ~Static175ad00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
