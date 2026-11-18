// Source exposure: binary-analysis; no external implementation source reused.
// Static177f880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f880*);
    virtual void release(Static177f880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f880*);
struct Static177f880 {
    void* value;
    Static177f880();
    ~Static177f880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
