// Source exposure: binary-analysis; no external implementation source reused.
// Static177b500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b500*);
    virtual void release(Static177b500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b500*);
struct Static177b500 {
    void* value;
    Static177b500();
    ~Static177b500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
