// Source exposure: binary-analysis; no external implementation source reused.
// Static176f200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f200*);
    virtual void release(Static176f200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f200*);
struct Static176f200 {
    void* value;
    Static176f200();
    ~Static176f200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
