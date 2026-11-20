// Source exposure: binary-analysis; no external implementation source reused.
// Static176b740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b740*);
    virtual void release(Static176b740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b740*);
struct Static176b740 {
    void* value;
    Static176b740();
    ~Static176b740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
