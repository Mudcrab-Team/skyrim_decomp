// Source exposure: binary-analysis; no external implementation source reused.
// Static177bd20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bd20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bd20*);
    virtual void release(Static177bd20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bd20*);
struct Static177bd20 {
    void* value;
    Static177bd20();
    ~Static177bd20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
