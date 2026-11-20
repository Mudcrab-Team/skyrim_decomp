// Source exposure: binary-analysis; no external implementation source reused.
// Static173d920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d920*);
    virtual void release(Static173d920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d920*);
struct Static173d920 {
    void* value;
    Static173d920();
    ~Static173d920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
