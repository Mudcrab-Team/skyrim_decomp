// Source exposure: binary-analysis; no external implementation source reused.
// Static173f980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f980*);
    virtual void release(Static173f980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f980*);
struct Static173f980 {
    void* value;
    Static173f980();
    ~Static173f980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
