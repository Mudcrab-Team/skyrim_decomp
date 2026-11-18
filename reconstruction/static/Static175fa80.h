// Source exposure: binary-analysis; no external implementation source reused.
// Static175fa80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fa80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fa80*);
    virtual void release(Static175fa80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fa80*);
struct Static175fa80 {
    void* value;
    Static175fa80();
    ~Static175fa80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
