// Source exposure: binary-analysis; no external implementation source reused.
// Static17aae80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aae80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aae80*);
    virtual void release(Static17aae80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aae80*);
struct Static17aae80 {
    void* value;
    Static17aae80();
    ~Static17aae80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
