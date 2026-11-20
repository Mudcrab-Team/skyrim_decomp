// Source exposure: binary-analysis; no external implementation source reused.
// Static176f840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f840*);
    virtual void release(Static176f840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f840*);
struct Static176f840 {
    void* value;
    Static176f840();
    ~Static176f840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
