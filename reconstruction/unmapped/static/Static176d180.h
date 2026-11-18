// Source exposure: binary-analysis; no external implementation source reused.
// Static176d180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d180*);
    virtual void release(Static176d180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d180*);
struct Static176d180 {
    void* value;
    Static176d180();
    ~Static176d180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
