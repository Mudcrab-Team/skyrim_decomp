// Source exposure: binary-analysis; no external implementation source reused.
// Static179c250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c250*);
    virtual void release(Static179c250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c250*);
struct Static179c250 {
    void* value;
    Static179c250();
    ~Static179c250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
