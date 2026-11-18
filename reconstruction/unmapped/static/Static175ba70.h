// Source exposure: binary-analysis; no external implementation source reused.
// Static175ba70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ba70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ba70*);
    virtual void release(Static175ba70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ba70*);
struct Static175ba70 {
    void* value;
    Static175ba70();
    ~Static175ba70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
