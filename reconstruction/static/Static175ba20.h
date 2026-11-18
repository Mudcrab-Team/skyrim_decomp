// Source exposure: binary-analysis; no external implementation source reused.
// Static175ba20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ba20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ba20*);
    virtual void release(Static175ba20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ba20*);
struct Static175ba20 {
    void* value;
    Static175ba20();
    ~Static175ba20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
