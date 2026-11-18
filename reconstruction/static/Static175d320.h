// Source exposure: binary-analysis; no external implementation source reused.
// Static175d320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d320*);
    virtual void release(Static175d320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d320*);
struct Static175d320 {
    void* value;
    Static175d320();
    ~Static175d320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
