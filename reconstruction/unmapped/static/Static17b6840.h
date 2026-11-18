// Source exposure: binary-analysis; no external implementation source reused.
// Static17b6840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b6840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b6840*);
    virtual void release(Static17b6840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b6840*);
struct Static17b6840 {
    void* value;
    Static17b6840();
    ~Static17b6840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
