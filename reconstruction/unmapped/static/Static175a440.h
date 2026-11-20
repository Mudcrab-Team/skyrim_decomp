// Source exposure: binary-analysis; no external implementation source reused.
// Static175a440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a440*);
    virtual void release(Static175a440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a440*);
struct Static175a440 {
    void* value;
    Static175a440();
    ~Static175a440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
