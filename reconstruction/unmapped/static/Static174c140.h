// Source exposure: binary-analysis; no external implementation source reused.
// Static174c140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174c140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174c140*);
    virtual void release(Static174c140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174c140*);
struct Static174c140 {
    void* value;
    Static174c140();
    ~Static174c140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
