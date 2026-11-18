// Source exposure: binary-analysis; no external implementation source reused.
// Static177fb00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fb00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fb00*);
    virtual void release(Static177fb00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fb00*);
struct Static177fb00 {
    void* value;
    Static177fb00();
    ~Static177fb00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
