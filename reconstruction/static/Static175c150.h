// Source exposure: binary-analysis; no external implementation source reused.
// Static175c150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c150*);
    virtual void release(Static175c150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c150*);
struct Static175c150 {
    void* value;
    Static175c150();
    ~Static175c150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
