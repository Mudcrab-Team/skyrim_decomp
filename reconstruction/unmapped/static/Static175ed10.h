// Source exposure: binary-analysis; no external implementation source reused.
// Static175ed10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ed10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ed10*);
    virtual void release(Static175ed10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ed10*);
struct Static175ed10 {
    void* value;
    Static175ed10();
    ~Static175ed10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
