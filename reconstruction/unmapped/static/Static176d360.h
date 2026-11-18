// Source exposure: binary-analysis; no external implementation source reused.
// Static176d360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d360*);
    virtual void release(Static176d360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d360*);
struct Static176d360 {
    void* value;
    Static176d360();
    ~Static176d360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
