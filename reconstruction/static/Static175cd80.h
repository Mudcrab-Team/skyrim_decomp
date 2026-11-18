// Source exposure: binary-analysis; no external implementation source reused.
// Static175cd80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cd80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cd80*);
    virtual void release(Static175cd80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cd80*);
struct Static175cd80 {
    void* value;
    Static175cd80();
    ~Static175cd80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
