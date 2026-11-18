// Source exposure: binary-analysis; no external implementation source reused.
// Static175be80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175be80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175be80*);
    virtual void release(Static175be80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175be80*);
struct Static175be80 {
    void* value;
    Static175be80();
    ~Static175be80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
