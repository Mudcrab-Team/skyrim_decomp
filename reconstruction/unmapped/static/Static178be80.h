// Source exposure: binary-analysis; no external implementation source reused.
// Static178be80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178be80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178be80*);
    virtual void release(Static178be80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178be80*);
struct Static178be80 {
    void* value;
    Static178be80();
    ~Static178be80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
