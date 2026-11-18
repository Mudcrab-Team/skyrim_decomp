// Source exposure: binary-analysis; no external implementation source reused.
// Static176f930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f930*);
    virtual void release(Static176f930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f930*);
struct Static176f930 {
    void* value;
    Static176f930();
    ~Static176f930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
