// Source exposure: binary-analysis; no external implementation source reused.
// Static176b880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b880*);
    virtual void release(Static176b880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b880*);
struct Static176b880 {
    void* value;
    Static176b880();
    ~Static176b880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
