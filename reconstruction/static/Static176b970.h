// Source exposure: binary-analysis; no external implementation source reused.
// Static176b970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b970*);
    virtual void release(Static176b970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b970*);
struct Static176b970 {
    void* value;
    Static176b970();
    ~Static176b970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
