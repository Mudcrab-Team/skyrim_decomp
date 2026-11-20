// Source exposure: binary-analysis; no external implementation source reused.
// Static177f380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f380*);
    virtual void release(Static177f380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f380*);
struct Static177f380 {
    void* value;
    Static177f380();
    ~Static177f380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
