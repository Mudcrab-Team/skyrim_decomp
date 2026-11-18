// Source exposure: binary-analysis; no external implementation source reused.
// Static178c010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c010*);
    virtual void release(Static178c010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c010*);
struct Static178c010 {
    void* value;
    Static178c010();
    ~Static178c010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
