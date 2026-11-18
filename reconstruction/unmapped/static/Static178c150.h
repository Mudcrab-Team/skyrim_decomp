// Source exposure: binary-analysis; no external implementation source reused.
// Static178c150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c150*);
    virtual void release(Static178c150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c150*);
struct Static178c150 {
    void* value;
    Static178c150();
    ~Static178c150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
