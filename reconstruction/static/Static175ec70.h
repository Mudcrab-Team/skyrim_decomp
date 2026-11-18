// Source exposure: binary-analysis; no external implementation source reused.
// Static175ec70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ec70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ec70*);
    virtual void release(Static175ec70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ec70*);
struct Static175ec70 {
    void* value;
    Static175ec70();
    ~Static175ec70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
