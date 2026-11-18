// Source exposure: binary-analysis; no external implementation source reused.
// Static177c180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c180*);
    virtual void release(Static177c180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c180*);
struct Static177c180 {
    void* value;
    Static177c180();
    ~Static177c180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
