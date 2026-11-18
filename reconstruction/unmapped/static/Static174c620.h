// Source exposure: binary-analysis; no external implementation source reused.
// Static174c620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174c620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174c620*);
    virtual void release(Static174c620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174c620*);
struct Static174c620 {
    void* value;
    Static174c620();
    ~Static174c620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
