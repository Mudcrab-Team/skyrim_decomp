// Source exposure: binary-analysis; no external implementation source reused.
// Static17b6930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b6930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b6930*);
    virtual void release(Static17b6930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b6930*);
struct Static17b6930 {
    void* value;
    Static17b6930();
    ~Static17b6930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
