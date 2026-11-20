// Source exposure: binary-analysis; no external implementation source reused.
// Static175c010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c010*);
    virtual void release(Static175c010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c010*);
struct Static175c010 {
    void* value;
    Static175c010();
    ~Static175c010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
