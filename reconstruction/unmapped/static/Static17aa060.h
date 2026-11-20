// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa060*);
    virtual void release(Static17aa060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa060*);
struct Static17aa060 {
    void* value;
    Static17aa060();
    ~Static17aa060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
