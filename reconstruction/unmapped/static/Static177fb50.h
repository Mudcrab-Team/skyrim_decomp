// Source exposure: binary-analysis; no external implementation source reused.
// Static177fb50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fb50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fb50*);
    virtual void release(Static177fb50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fb50*);
struct Static177fb50 {
    void* value;
    Static177fb50();
    ~Static177fb50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
