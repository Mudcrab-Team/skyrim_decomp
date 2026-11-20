// Source exposure: binary-analysis; no external implementation source reused.
// Static173e930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e930*);
    virtual void release(Static173e930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e930*);
struct Static173e930 {
    void* value;
    Static173e930();
    ~Static173e930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
