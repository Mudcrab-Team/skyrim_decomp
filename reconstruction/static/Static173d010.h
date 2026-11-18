// Source exposure: binary-analysis; no external implementation source reused.
// Static173d010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d010*);
    virtual void release(Static173d010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d010*);
struct Static173d010 {
    void* value;
    Static173d010();
    ~Static173d010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
