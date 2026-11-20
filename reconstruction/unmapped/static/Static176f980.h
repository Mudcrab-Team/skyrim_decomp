// Source exposure: binary-analysis; no external implementation source reused.
// Static176f980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f980*);
    virtual void release(Static176f980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f980*);
struct Static176f980 {
    void* value;
    Static176f980();
    ~Static176f980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
