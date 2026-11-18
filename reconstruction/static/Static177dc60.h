// Source exposure: binary-analysis; no external implementation source reused.
// Static177dc60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177dc60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177dc60*);
    virtual void release(Static177dc60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177dc60*);
struct Static177dc60 {
    void* value;
    Static177dc60();
    ~Static177dc60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
