// Source exposure: binary-analysis; no external implementation source reused.
// Static175ff80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ff80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ff80*);
    virtual void release(Static175ff80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ff80*);
struct Static175ff80 {
    void* value;
    Static175ff80();
    ~Static175ff80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
