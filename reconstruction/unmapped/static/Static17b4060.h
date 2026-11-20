// Source exposure: binary-analysis; no external implementation source reused.
// Static17b4060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b4060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b4060*);
    virtual void release(Static17b4060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b4060*);
struct Static17b4060 {
    void* value;
    Static17b4060();
    ~Static17b4060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
