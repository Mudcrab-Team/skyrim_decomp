// Source exposure: binary-analysis; no external implementation source reused.
// Static177b000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b000*);
    virtual void release(Static177b000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b000*);
struct Static177b000 {
    void* value;
    Static177b000();
    ~Static177b000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
