// Source exposure: binary-analysis; no external implementation source reused.
// Static173e000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e000*);
    virtual void release(Static173e000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e000*);
struct Static173e000 {
    void* value;
    Static173e000();
    ~Static173e000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
