// Source exposure: binary-analysis; no external implementation source reused.
// Static176a980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a980*);
    virtual void release(Static176a980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a980*);
struct Static176a980 {
    void* value;
    Static176a980();
    ~Static176a980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
