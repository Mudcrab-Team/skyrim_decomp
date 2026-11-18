// Source exposure: binary-analysis; no external implementation source reused.
// Static178eb70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178eb70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178eb70*);
    virtual void release(Static178eb70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178eb70*);
struct Static178eb70 {
    void* value;
    Static178eb70();
    ~Static178eb70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
