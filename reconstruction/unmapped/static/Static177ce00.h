// Source exposure: binary-analysis; no external implementation source reused.
// Static177ce00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ce00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ce00*);
    virtual void release(Static177ce00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ce00*);
struct Static177ce00 {
    void* value;
    Static177ce00();
    ~Static177ce00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
