// Source exposure: binary-analysis; no external implementation source reused.
// Static177fa60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fa60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fa60*);
    virtual void release(Static177fa60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fa60*);
struct Static177fa60 {
    void* value;
    Static177fa60();
    ~Static177fa60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
