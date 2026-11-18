// Source exposure: binary-analysis; no external implementation source reused.
// Static178db20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178db20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178db20*);
    virtual void release(Static178db20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178db20*);
struct Static178db20 {
    void* value;
    Static178db20();
    ~Static178db20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
