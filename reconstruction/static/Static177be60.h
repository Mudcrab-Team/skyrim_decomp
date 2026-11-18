// Source exposure: binary-analysis; no external implementation source reused.
// Static177be60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177be60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177be60*);
    virtual void release(Static177be60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177be60*);
struct Static177be60 {
    void* value;
    Static177be60();
    ~Static177be60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
