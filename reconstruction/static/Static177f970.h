// Source exposure: binary-analysis; no external implementation source reused.
// Static177f970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f970*);
    virtual void release(Static177f970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f970*);
struct Static177f970 {
    void* value;
    Static177f970();
    ~Static177f970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
