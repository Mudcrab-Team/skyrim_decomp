// Source exposure: binary-analysis; no external implementation source reused.
// Static179d270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d270*);
    virtual void release(Static179d270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d270*);
struct Static179d270 {
    void* value;
    Static179d270();
    ~Static179d270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
