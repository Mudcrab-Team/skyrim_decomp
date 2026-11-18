// Source exposure: binary-analysis; no external implementation source reused.
// Static176ef80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ef80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ef80*);
    virtual void release(Static176ef80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ef80*);
struct Static176ef80 {
    void* value;
    Static176ef80();
    ~Static176ef80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
